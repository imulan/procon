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
    int w,h,t,p;
    while(cin >>w >>h >>t >>p,w){
        vector<int> dir(t),c(t);
        rep(i,t) cin >>dir[i] >>c[i];
        vector<pi> hole(p);
        rep(i,p){
            int x,y;
            cin >>x >>y;
            hole[i] = {y,x};
        }

        vector<vector<pi>> a(h,vector<pi>(w));
        rep(i,h)rep(j,w) a[i][j] = {i,j};

        auto F = [&](int d, int z){
            if(d==1){
                int mx = w;
                rep(i,h)rep(j,w){
                    if(a[i][j].se < z) a[i][j].se = z + (z-1-a[i][j].se);
                    mx = min(mx, a[i][j].se);
                }
                rep(i,h)rep(j,w) a[i][j].se -= mx;
            }
            else{
                int my = h;
                rep(i,h)rep(j,w){
                    if(a[i][j].fi < z) a[i][j].fi = z + (z-1-a[i][j].fi);
                    my = min(my, a[i][j].fi);
                }
                rep(i,h)rep(j,w) a[i][j].fi -= my;
            }
        };

        rep(i,t) F(dir[i],c[i]);

        rep(k,p){
            int ans = 0;
            rep(i,h)rep(j,w)if(a[i][j] == hole[k]) ++ans;
            cout << ans << endl;
        }
    }
    return 0;
}
