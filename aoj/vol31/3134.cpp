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
    int n,k;
    cin >>n >>k;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    vector<int> dp(1<<n,1);
    rep(mask,1<<n){
        int s = 0;
        rep(i,n)if(mask>>i&1) s += a[i];
        if(s == k) dp[mask] = 0;
    }

    rep(mask,1<<n)if(dp[mask] == 0){
        rep(i,n)if(!(mask>>i&1)){
            int nx = mask|(1<<i);
            dp[nx] = 0;
        }
    }

    int ans = n;
    rep(mask,1<<n)if(dp[mask]) ans = min(ans, n-__builtin_popcount(mask));
    cout << ans << "\n";
    return 0;
}
