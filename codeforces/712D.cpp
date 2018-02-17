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

const ll mod = 1e9+7;
const int N = 200002;

ll dp[N],nx[N];
ll suf[N]={};

int main(){
    int a,b,k,t;
    cin >>a >>b >>k >>t;

    // 1回で 0 ~ 2k 点取れる

    dp[0] = 1;
    rep(i,t){
        fill(nx,nx+N,0);
        ll sum = 0;
        rep(j,2*k+1){
            (sum += dp[j]) %= mod;
            nx[j] = sum;
        }
        for(int j=2*k+1; j<N; ++j){
            sum = (sum + dp[j] - dp[j-2*k-1] + mod) % mod;
            nx[j] = sum;
        }
        rep(j,N) dp[j] = nx[j];
    }

    for(int i=N-2; i>=0; --i) suf[i] = (suf[i+1]+dp[i])%mod;

    ll ans = 0;
    // 相手が b+i 点取る時
    rep(i,N)if(dp[i]>0){
        // a+x>b+i
        // x点以上が必要
        int x = max(0,b+i-a+1);
        if(x>=N) continue;

        (ans += dp[i]*suf[x]) %= mod;
    }
    cout << ans << endl;
    return 0;
}
