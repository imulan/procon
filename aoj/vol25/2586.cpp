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

const double INF = 1e5;
const double eps = 1e-8;

struct Star{
    double px,py,pz,vx,vy,vz,r,vr;
};

Star scan_star(){
    double px,py,pz,vx,vy,vz,r,vr;
    scanf(" %lf %lf %lf %lf %lf %lf %lf %lf", &px, &py, &pz, &vx, &vy, &vz, &r, &vr);
    return Star{px,py,pz,vx,vy,vz,r,vr};
}

inline double pw(double x){
    return x*x;
}

int main(){
    int n;
    while(scanf(" %d", &n),n){
        vector<Star> s(n);
        rep(i,n) s[i] = scan_star();

        vector<double> disappear(n);
        rep(i,n) disappear[i] = s[i].r/s[i].vr;

        auto f = [&](int i, int j, double t){
            return sqrt( pw((s[i].px+t*s[i].vx)-(s[j].px+t*s[j].vx)) + pw((s[i].py+t*s[i].vy)-(s[j].py+t*s[j].vy)) + pw((s[i].pz+t*s[i].vz)-(s[j].pz+t*s[j].vz)) ) - (s[i].r - t*s[i].vr) - (s[j].r - t*s[j].vr);
        };

        auto calc = [&](int i, int j){
            double l = 0, r = min(disappear[i], disappear[j]);
            rep(loop,40){
                double ml = (2*l+r)/3, mr = (l+2*r)/3;
                if(f(i,j,ml) < f(i,j,mr)) r = mr;
                else l = ml;
            }

            double argt = (l+r)/2;
            if(f(i,j,argt)>0) return INF;

            l = 0;
            r = argt;
            rep(loop,40){
                double m = (l+r)/2;
                if(f(i,j,m)>0) l = m;
                else r = m;
            }
            return r;
        };

        using pi = pair<int,int>;
        using P = pair<double, pi>;
        priority_queue<P, vector<P>, greater<P>> pq;

        rep(i,n)rep(j,i){
            double t = calc(i,j);
            if(t < INF - eps) pq.push({t,{i,j}});
        }

        vector<double> ans(disappear);
        vector<bool> rem(n,true);

        while(!pq.empty()){
            P now = pq.top();
            pq.pop();

            int u = now.se.fi, v = now.se.se;
            if(rem[u] && rem[v]){
                ans[u] = ans[v] = now.fi;
                rem[u] = rem[v] = false;
            }
        }

        rep(i,n) printf("%.10f\n", ans[i]);
    }
    return 0;
}
