#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

const double PI = acos(-1);
const double EPS = 1e-8;

using pi = pair<int,int>;
using P = pair<double,pi>;

int main(){
    int n;
    scanf(" %d", &n);

    vector<P> v;
    rep(i,n){
        int x,y;
        scanf(" %d %d", &x, &y);
        double t = atan2(y,x);
        if(t<0) t = 2*PI+t;

        v.pb({t,{x,y}});
        v.pb({t+2*PI,{x,y}});
    }
    sort(all(v));

    int V = v.size();
    ll ans = 0;
    rep(i,V){
        ll x = 0, y = 0;
        for(int j=i; j<V; ++j){
            if(v[j].fi - v[i].fi > PI+EPS) break;
            x += v[j].se.fi;
            y += v[j].se.se;
            ans = max(ans, x*x+y*y);
        }
    }

    printf("%.15f", sqrt(ans));
    return 0;
}
