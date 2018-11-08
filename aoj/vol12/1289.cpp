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

struct Point{
    double X,Y,Z;

    void PRINT(){
        printf("%.8f %.8f %.8f\n",X,Y,Z);
    }

    void ADD(Point p){
        X += p.X;
        Y += p.Y;
        Z += p.Z;
    }

    void MUL(double m){
        X *= m;
        Y *= m;
        Z *= m;
    }

    double norm(){
        return X*X + Y*Y + Z*Z;
    }

    double size(){
        return sqrt(norm());
    }

    void normalize(){
        double sz = size();
        X /= sz;
        Y /= sz;
        Z /= sz;
    }
};

using Vec = Point;

double dist(Point p, Point q){
    double dx = p.X-q.X;
    double dy = p.Y-q.Y;
    double dz = p.Z-q.Z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

double dot(Vec v, Vec u){
    return v.X*u.X + v.Y*u.Y + v.Z*u.Z;
}

Point READ(){
    double x,y,z;
    cin >>x >>y >>z;
    return {x,y,z};
}

const double LIM = 1000;
const double EPS = 1e-7;

int main(){
    int n;
    while(cin >>n,n){
        Vec v = READ();

        vector<Point> c(n);
        vector<double> r(n);
        rep(i,n){
            c[i] = READ();
            cin >>r[i];
        }

        Point now = {0,0,0};
        v.normalize();

        // Segment to Sphere
        auto distSS = [&](Point start, Vec dir, int idx){
            double L=0, R=LIM;
            rep(loop,100){
                double m1 = (2*L+R)/3 , m2 = (L+2*R)/3;
                Vec v1(dir), v2(dir);
                v1.MUL(m1);
                v2.MUL(m2);

                Point p1(start), p2(start);
                p1.ADD(v1);
                p2.ADD(v2);

                if(dist(c[idx],p1) > dist(c[idx],p2)) L=m1;
                else R=m2;
            }

            Vec add(dir);
            add.MUL(R);
            Point pos(start);
            pos.ADD(add);

            // NOT intersect
            if( dist(pos, c[idx]) > r[idx]+EPS ) return LIM;

            // 交点までのパラメータを改めて求める
            L = 0;
            rep(loop,100){
                double mid = (L+R)/2;
                Vec vv(dir);
                vv.MUL(mid);

                Point pp(start);
                pp.ADD(vv);

                if(dist(c[idx],pp) < r[idx]) R = mid;
                else L = mid;
            }
            return L;
        };

        int prev = -1;
        while(1){
            double min_t = LIM;
            int idx = -1;
            rep(i,n)if(prev!=i){
                double tt = distSS(now,v,i);
                // dbg(i);dbg(tt);
                if(tt < min_t){
                    min_t = tt;
                    idx = i;
                }
            }

            if(idx == -1) break;

            Vec vv(v);
            vv.MUL(min_t);
            Point q(now);
            q.ADD(vv);

            // dbg(dist(c[idx],q));
            Vec qn = {q.X-c[idx].X, q.Y-c[idx].Y, q.Z-c[idx].Z};
            qn.normalize();

            Vec qi(v);
            qi.MUL(-1);

            // qn.PRINT();
            // qi.PRINT();

            double cos_theta = dot(qn,qi);
            // dbg(cos_theta);

            double D = dist(now,q);
            // dbg(D);
            D *= cos_theta;

            Vec hh(qn);
            hh.MUL(D);
            Point H(q);
            H.ADD(hh);

            Vec nh = {H.X-now.X, H.Y-now.Y, H.Z-now.Z};;
            nh.MUL(2);

            Point ref(now);
            ref.ADD(nh);

            now = q;
            v = {ref.X-q.X, ref.Y-q.Y, ref.Z-q.Z};
            v.normalize();
            // printf("v = ");v.PRINT();
            prev = idx;
        }

        now.PRINT();
    }
    return 0;
}
