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

using pi = pair<int,int>;
const int N = 60006;
int dp[N],nx[N];

int main(){
    int n,r;
    cin >>n >>r;

    vector<pi> p,m;
    rep(i,n){
        int a,b;
        cin >>a >>b;
        if(b>=0) p.pb({a,b});
        else m.pb({max(a,-b),b});
    }

    // plus
    int pct = 0;
    sort(all(p));
    for(const auto &x:p){
        if(r >= x.fi){
            ++pct;
            r += x.se;
        }
    }

    // minus
    sort(all(m), [](const pi &lh, const pi &rh){
        return lh.fi+lh.se  > rh.fi+rh.se;
    });

    fill(dp,dp+N,-N);
    dp[r] = 0;
    for(const auto &x:m){
        for(int i=x.fi; i<N; ++i){
            int ni = max(0,i+x.se);
            dp[ni] = max(dp[ni], dp[i]+1);
        }
    }

    int ans = 0;
    rep(i,N) ans = max(ans, pct+dp[i]);

    // F1
    // cout << (ans==n?"YES":"NO") << "\n";
    // F2
    cout << ans << "\n";

    return 0;
}
