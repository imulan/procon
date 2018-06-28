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

const ll mod = 998244353;

const int N = 1010;
ll dp[N][N];

int main(){
    int n;
    cin >>n;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    dp[0][0] = 1;
    rep(i,n){
        (dp[i+1][0] += dp[i][0]) %= mod;
        if(a[i]>0 && a[i]<N){
            (dp[i+1][a[i]] += dp[i][0]) %= mod;
        }

        for(int j=N-1; j>0; --j){
            (dp[i+1][j] += dp[i][j]) %= mod;
            (dp[i+1][j-1] += dp[i][j]) %= mod;
        }
    }

    ll ans = (dp[n][0]-1+mod)%mod;
    cout << ans << endl;
    return 0;
}
