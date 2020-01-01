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

int main(){
    int n;
    ll y;
    cin >>n >>y;

    ll s = 0;
    vector<ll> a(n);
    rep(i,n){
        cin >>a[i];
        s += a[i];
    }

    ll ans = 0;
    for(int pre=1; pre<n; ++pre)rep(suf,n){
        if(pre+suf>=n) continue;

        ll tt = 0;
        rep(i,pre) tt += a[i];
        rep(i,suf) tt += a[n-1-i];
        if(tt+y < s/5) continue;

        vector<ll> v;
        for(int i=pre; i<n-suf; ++i) v.pb(a[i]);
        int V = v.size();
        if(V<4) continue;

        vector<ll> p(V+1);
        rep(i,V) p[i+1] = v[i]+p[i];

        vector<ll> dp(V+1);
        dp[0] = 1;
        rep(loop,4){
            vector<ll> nx(V+1);

            ll ss = 0;
            int j = 0;
            rep(i,V){
                while(j<i+1 && p[i+1]-p[j]+y>=s/5){
                    ss += dp[j];
                    ++j;
                }
                nx[i+1] = ss;
            }
            dp = nx;
        }

        ans += dp[V];
    }

    cout << ans << "\n";
    return 0;
}
