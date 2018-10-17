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

#define double long double

/* 基本要素 */
typedef complex<double> Point;
typedef pair<Point, Point> Line;
typedef vector<Point> VP;
const double PI = acos(-1);
const double EPS = 1e-9; // 許容誤差^2
const double INF = 1e9;
#define X real()
#define Y imag()
// #define LE(n,m) ((n) < (m) + EPS)
#define LE(n,m) ((n) - (m) < EPS)
// #define GE(n,m) ((n) + EPS > (m))
#define GE(n,m) (EPS > (m) - (n))
#define EQ(n,m) (abs((n)-(m)) < EPS)

// 内積　dot(a,b) = |a||b|cosθ
double dot(Point a, Point b) {
  return a.X*b.X + a.Y*b.Y;
}

// 外積　cross(a,b) = |a||b|sinθ
double cross(Point a, Point b) {
  return a.X*b.Y - a.Y*b.X;
}

// 点の進行方向
// !!! 誤差に注意 !!! (掛け算したものとかなり小さいものを比べているので)
int ccw(Point a, Point b, Point c) {
  b -= a;  c -= a;
  if (cross(b,c) >  EPS) return +1;  // counter clockwise
  if (cross(b,c) < -EPS) return -1;  // clockwise
  if (dot(b,c)   < -EPS) return +2;  // c--a--b on line
  if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
  return 0;                          // a--c--b on line or a==c or b==c
}

// 線分と点
bool isecSP(Point a1, Point a2, Point b) {
  return !ccw(a1, a2, b);
}

// 点pの直線aへの射影点を返す
Point proj(Point a1, Point a2, Point p) {
  return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}

double distSP(Point a1, Point a2, Point p) {
  Point r = proj(a1, a2, p);
  if (isecSP(a1, a2, r)) return abs(r-p);
  //= !ccw(a1, a2, r)
  return min(abs(a1-p), abs(a2-p));
}


Point READ_P(){
    int x,y;
    cin >>x >>y;
    return Point(x,y);
}

int main(){
    int n;
    cin >>n;
    Point start = READ_P(), goal = READ_P();

    vector<int> r(n);
    vector<int> sz(n);
    vector<VP> light(n);
    rep(i,n){
        cin >>r[i] >>sz[i];
        rep(j,sz[i]) light[i].pb(READ_P());
    }

    const double T = 1000;
    // total_length
    vector<double> L(n);
    // speed
    vector<double> v(n);
    rep(i,n){
        rep(j,sz[i]){
            Point p = light[i][j], q = light[i][(j+1)%sz[i]];
            L[i] += abs(p-q);
        }
        v[i] = L[i]/T;
    }

    auto reach_CP = [&](int a, Point p){
        rep(i,sz[a]){
            Point pp = light[a][i], qq = light[a][(i+1)%sz[a]];
            double d = distSP(pp,qq,p);
            if(LE(d, r[a])) return true;
        }
        return false;
    };

    vector<bool> can_start(n),can_goal(n);
    rep(i,n){
        can_start[i] = reach_CP(i, start);
        can_goal[i] = reach_CP(i, goal);
    }
    // dbg(can_start);dbg(can_goal);

    auto get_arriv = [&](int a){
        vector<double> ret;

        double cum = 0;
        rep(i,sz[a]){
            ret.pb(cum / v[a]);
            if(i+1<sz[a]) cum += abs(light[a][i+1] - light[a][i]);
        }
        ret.pb(T);
        return ret;
    };

    auto get_vec = [&](int a, int idx){
        Point vec = light[a][(idx+1)%sz[a]] - light[a][idx];
        double v_sz = sqrt(norm(vec));
        vec *= v[a]/v_sz;
        return vec;
    };

    auto reach_CC = [&](int a, int b){
        vector<double> ta = get_arriv(a);
        vector<double> tb = get_arriv(b);
        // dbg(ta);dbg(tb);

        int aidx = 0, bidx = 0;
        while(aidx<sz[a] && bidx<sz[b]){
            // printf(" aidx,bidx %d %d\n",aidx,bidx);

            Point va = get_vec(a, aidx);
            Point vb = get_vec(b, bidx);

            double LL = max(ta[aidx], tb[bidx]);
            double RR = min(ta[aidx+1], tb[bidx+1]);
            // printf(" LL RR %f %f\n",LL,RR);

            rep(loop,30){
                double m1 = (2*LL+RR)/3;
                double m2 = (LL+2*RR)/3;

                Point ca = light[a][aidx] + (m1-ta[aidx])*va;
                Point cb = light[b][bidx] + (m1-tb[bidx])*vb;
                double d1 = abs(ca-cb);

                ca = light[a][aidx] + (m2-ta[aidx])*va;
                cb = light[b][bidx] + (m2-tb[bidx])*vb;
                double d2 = abs(ca-cb);

                if(d1>d2) LL = m1;
                else RR = m2;
            }

            double t = (LL+RR)/2;
            Point ca = light[a][aidx] + (t-ta[aidx])*va;
            Point cb = light[b][bidx] + (t-tb[bidx])*vb;
            double d1 = abs(ca-cb);
            if( LE(d1, r[a]+r[b]) ) return true;

            if(ta[aidx+1] < tb[bidx+1]) ++aidx;
            else ++bidx;
        }

        return false;
    };

    vector<vector<int>> G(n);
    rep(i,n)rep(j,i){
        if(reach_CC(i,j)){
            // printf(" ADD: %d <-> %d\n",i,j);
            G[i].pb(j);
            G[j].pb(i);
        }
    }

    vector<bool> vis(n);
    queue<int> que;
    rep(i,n)if(can_start[i]){
        vis[i] = true;
        que.push(i);
    }
    while(!que.empty()){
        int now = que.front();
        que.pop();
        for(int e:G[now]){
            if(!vis[e]){
                vis[e] = true;
                que.push(e);
            }
        }
    }

    bool ok = false;
    rep(i,n)if(can_goal[i] && vis[i]) ok = true;
    cout << (ok?"Yes":"No") << endl;
    return 0;
}
