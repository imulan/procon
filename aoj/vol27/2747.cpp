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

using pi = pair<int,int>;

int main(){
    int n;
    while(cin >>n,n){
        vector<ll> ux,uy;

        vector<pi> window(n);
        rep(i,n){
            int x,y;
            cin >>x >>y;
            window[i] = {x,y};
            ux.pb(x);
            uy.pb(y);
        }

        vector<pi> curtain(4);
        rep(i,4){
            int x,y;
            cin >>x >>y;
            curtain[i] = {x,y};
            ux.pb(x);
            uy.pb(y);
        }

        sort(all(ux));
        ux.erase(unique(all(ux)), ux.end());
        sort(all(uy));
        uy.erase(unique(all(uy)), uy.end());

        auto cover = [&](const vector<pi> &v, double X, double Y){
            int ct = 0;
            int V = v.size();
            rep(i,V){
                int j = (i+1)%V;
                if(v[i].fi==v[j].fi && X<v[i].fi){
                    int ly = min(v[i].se, v[j].se);
                    int ry = max(v[i].se, v[j].se);

                    if(ly<Y && Y<ry) ++ct;
                }
            }
            return ct%2 == 1;
        };

        int X = ux.size();
        int Y = uy.size();
        ll ans = 0;
        rep(i,X-1)rep(j,Y-1){
            ll area = (ux[i+1]-ux[i])*(uy[j+1]-uy[j]);
            double px = (ux[i]+ux[i+1])/2.0;
            double py = (uy[j]+uy[j+1])/2.0;

            if(cover(window,px,py) && !cover(curtain,px,py)) ans += area;
        }
        cout << ans << endl;
    }
    return 0;
}
