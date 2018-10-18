#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

const double EPS = 1e-7;

using vec = vector<double>;
using mat = vector<vec>;

// 連立方程式Ax=bを解く
// Aは正方行列を仮定
// 解無し、一意に定まらない : 長さ0のvector
vec gauss_jordan(const mat &A, const vec &b){
    int d = A.size();
    mat B(d, vec(d+1));
    rep(i,d){
        rep(j,d) B[i][j] = A[i][j];
        B[i][d] = b[i];
    }

    rep(i,d){
        int pivot = i;
        for(int j=i; j<d; ++j){
            if( abs(B[j][i]) > abs(B[pivot][i]) ) pivot = j;
        }
        swap(B[i], B[pivot]);

        // 解無し、一意に定まらない : 長さ0のvector
        if(abs(B[i][i]) < EPS) return vec();

        // 注目する変数の係数を1にする
        for(int j=i+1; j<=d; ++j) B[i][j] /= B[i][i];
        rep(j,d){
            if(i==j) continue;
            // j番目の式からi番目の変数を除去
            for(int k=i+1; k<=d; ++k) B[j][k] -= B[j][i]*B[i][k];
        }
    }

    vec ret(d);
    rep(i,d) ret[i] = B[i][d];
    return ret;
}

struct Point{
    double x,y,z;
};

using Vector = Point;

void printp(Point p){
    printf("  %f  %f  %f\n",p.x,p.y,p.z);
}

Point READ(){
    double x,y,z;
    cin >>x >>y >>z;
    return {x,y,z};
}

Vector cross(Vector a, Vector b){
    return {a.y*b.z-b.y*a.z, a.z*b.x-b.z*a.x, a.x*b.y-b.x*a.y};
}

bool is_parallel(Vector a, Vector b){
    bool found = false;
    double t = 0;
    if( abs(a.x) > EPS ){
        found = true;
        t = b.x / a.x;
    }
    if( abs(a.y) > EPS ){
        found = true;
        t = b.y / a.y;
    }
    if( abs(a.z) > EPS ){
        found = true;
        t = b.z / a.z;
    }
    assert(found);

    a.x *= t;
    a.y *= t;
    a.z *= t;

    return ( abs(a.x-b.x)<EPS && abs(a.y-b.y)<EPS && abs(a.z-b.z)<EPS );
}

double dist(Point p, Point q){
    auto sq = [](double x){
        return x*x;
    };
    return sqrt( sq(p.x-q.x) + sq(p.y-q.y) + sq(p.z-q.z) );
}

const int LOOP_SIZE = 100;

bool solve(){
    Point c[2];
    Vector v[2][2];

    rep(i,2){
        c[i] = READ();
        rep(j,2) v[i][j] = READ();
    }

    Vector hv[2];
    rep(i,2) hv[i] = cross(v[i][0], v[i][1]);

    if(is_parallel(hv[0],hv[1])) return false;

    // (u, H) を pairで返す
    auto find_h = [&](Point p){
        mat A(3,vec(3));
        A[0][0] = v[0][0].x;
        A[0][1] = v[0][1].x;
        A[0][2] = hv[0].x;
        A[1][0] = v[0][0].y;
        A[1][1] = v[0][1].y;
        A[1][2] = hv[0].y;
        A[2][0] = v[0][0].z;
        A[2][1] = v[0][1].z;
        A[2][2] = hv[0].z;

        vec b(3);
        b[0] = p.x - c[0].x;
        b[1] = p.y - c[0].y;
        b[2] = p.z - c[0].z;

        vec res = gauss_jordan(A,b);

        double u = res[2];
        Point H = p;
        H.x -= u*hv[0].x;
        H.y -= u*hv[0].y;
        H.z -= u*hv[0].z;
        return pair<double, Point>(u,H);
    };

    double mx = -191919;
    Point far;
    for(int i:{-1,1})for(int j:{-1,1}){
        double ls = 0, rs = 1;
        rep(loop,LOOP_SIZE){
            double s[2];
            s[0] = (2*ls + rs)/3;
            s[1] = (ls + 2*rs)/3;
            double t[2];
            rep(k,2) t[k] = sqrt(1 - s[k]*s[k]);

            Point p[2];
            rep(k,2) p[k] = {c[1].x+s[k]*i*v[1][0].x+t[k]*j*v[1][1].x, c[1].y+s[k]*i*v[1][0].y+t[k]*j*v[1][1].y, c[1].z+s[k]*i*v[1][0].z+t[k]*j*v[1][1].z};

            double u[2];
            Point h[2];
            rep(k,2){
                pair<double, Point> res = find_h(p[k]);
                u[k] = res.fi;
                h[k] = res.se;
            }

            if(u[0]>u[1]) rs = s[1];
            else ls = s[0];
        }

        double s = (ls+rs)/2;
        double t = sqrt(1 - s*s);
        Point p = {c[1].x+s*i*v[1][0].x+t*j*v[1][1].x, c[1].y+s*i*v[1][0].y+t*j*v[1][1].y, c[1].z+s*i*v[1][0].z+t*j*v[1][1].z};

        pair<double, Point> res = find_h(p);
        double u = res.fi;
        Point h = res.se;

        // printf(" ij %d %d s,t (%f , %f),  u %f\n",i,j,s,t,u);
        // printf(" p: ");printp(p);
        // printf(" h: ");printp(h);

        if(mx < u){
            mx = u;
            far = p;
        }
    }

    // dbg(mx);
    // printp(far);

    Vector rr = {far.x - c[1].x, far.y - c[1].y, far.z - c[1].z};
    Point op_far = {far.x - 2*rr.x, far.y - 2*rr.y, far.z - 2*rr.z};
    // printp(op_far);

    pair<double, Point> op_res = find_h(op_far);
    // dbg(op_res.fi);
    if( !(op_res.fi < -EPS) ) return false;

    Vector u1 = rr;
    Vector u2 = cross(u1,hv[1]);
    double u2_sz = sqrt(u2.x*u2.x + u2.y*u2.y + u2.z*u2.z);
    u2.x /= u2_sz;
    u2.y /= u2_sz;
    u2.z /= u2_sz;

    // printf(" u1: ");printp(u1);
    // printf(" u2: ");printp(u2);

    int ct = 0;
    for(int i:{-1,1}){
        double ls = -1, rs = 1;
        rep(loop,LOOP_SIZE){
            double s = (ls+rs)/2;
            double t = sqrt(1 - s*s);

            Point p = {c[1].x+s*u1.x+t*i*u2.x, c[1].y+s*u1.y+t*i*u2.y, c[1].z+s*u1.z+t*i*u2.z};

            pair<double, Point> tmp = find_h(p);
            if(tmp.fi >= 0) rs = s;
            else ls = s;
        }

        double s = (ls+rs)/2;
        double t = sqrt(1 - s*s);

        Point p = {c[1].x+s*u1.x+t*i*u2.x, c[1].y+s*u1.y+t*i*u2.y, c[1].z+s*u1.z+t*i*u2.z};

        double d = dist(c[0], p);
        if(d <= 1) ++ct;
    }

    return (ct == 1);
}

int main(){
    cout << (solve()?"YES":"NO") << endl;
    return 0;
}
