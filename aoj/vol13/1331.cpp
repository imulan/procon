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

const int N = 2000;

struct P{
    double x,y,z;
};

inline double sq(double x){
    return x*x;
}

inline double dist(P p, P q){
    return sqrt(sq(p.x-q.x)+sq(p.y-q.y)+sq(p.z-q.z));
}

double distSP(P p, P q){
    double l=0, r=1;
    rep(_,40){
        double m1 = (2*l+r)/3, m2 = (l+2*r)/3;

        P a1({m1*p.x, m1*p.y, m1*p.z}), a2({m2*p.x, m2*p.y, m2*p.z});
        if(dist(q,a1) < dist(q,a2)) r=m2;
        else l=m1;
    }

    return dist(q, P({l*p.x, l*p.y, l*p.z}));
}

int main(){
    int n,m,r;
    while(scanf(" %d %d %d", &n, &m, &r),n){
        vector<P> s(n);
        vector<int> sr(n);
        rep(i,n) scanf(" %lf %lf %lf %d", &s[i].x, &s[i].y, &s[i].z, &sr[i]);

        vector<P> t(m);
        vector<int> tb(m);
        rep(i,m) scanf(" %lf %lf %lf %d", &t[i].x, &t[i].y, &t[i].z, &tb[i]);

        P E;
        scanf(" %lf %lf %lf", &E.x, &E.y, &E.z);

        rep(i,n){
            s[i].x -= E.x;
            s[i].y -= E.y;
            s[i].z -= E.z;
        }
        rep(i,m){
            t[i].x -= E.x;
            t[i].y -= E.y;
            t[i].z -= E.z;
        }
        E = {0,0,0};

        vector<vector<double>> d(m,vector<double>(n));
        rep(i,m)rep(j,n) d[i][j] = distSP(t[i],s[j]);

        vector<bitset<N>> rem(m);
        rep(i,m){
            rep(j,n){
                if(d[i][j]<sr[j] && sr[j]<max(dist(E,s[j]),dist(t[i],s[j]))) rem[i].set(j);
            }
        }

        double ans = 0;
        rep(mask,1<<m){
            bitset<N> must;
            rep(i,m)if(mask>>i&1){
                must |= rem[i];
            }

            if(must.count()<=r){
                double tmp = 0;
                rep(i,m)if(mask>>i&1) tmp += tb[i]/sq(dist(E,t[i]));
                ans = max(ans,tmp);
            }
        }
        printf("%.10f\n", ans);
    }
    return 0;
}
