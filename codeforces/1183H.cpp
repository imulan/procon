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

const ll LIM = 1000000000000LL;
const int N = 101;
const int A = 26;

ll dp[N][N];

ll ADD(ll x, ll y){
    return min(x+y, LIM);
}

ll solve(){
    int n;
    ll K;
    string s;
    cin >>n >>K >>s;

    dp[0][0] = 1;
    rep(i,n)rep(j,n)if(dp[i][j]){
        bool used[A]={};
        for(int k=i; k<n; ++k){
            int idx = s[k]-'a';
            if(!used[idx]){
                used[idx] = true;
                dp[k+1][j+1] = ADD(dp[k+1][j+1], dp[i][j]);
            }
        }
    }

    ll ans = 0;
    for(int i=n; i>=0; --i){
        ll t = 0;
        rep(j,n+1) t = ADD(t, dp[j][i]);

        t = min(t,K);
        ans += t*(n-i);

        K -= t;
        if(K==0) return ans;
    }
    return -1;
}

int main(){
    cout << solve() << "\n";
    return 0;
}
