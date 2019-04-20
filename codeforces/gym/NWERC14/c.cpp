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

const int N = 2002;
const int D = 22;
const ll INF = LLONG_MAX/3;

ll pre[N]={};

ll dp[N][D];

ll f(ll x){
    if(x%10<5) x -= x%10;
    else x += 10-(x%10);
    return x;
}

int main(){
    int n,d;
    cin >>n >>d;
    vector<int> p(n);
    rep(i,n) cin >>p[i];

    rep(i,n) pre[i+1] = pre[i]+p[i];

    rep(i,N)rep(j,D) dp[i][j] = INF;
    dp[0][0] = 0;

    rep(i,n)rep(j,d+1){
        for(int k=i; k<n; ++k){
            ll val = pre[k+1]-pre[i];
            // printf(" [%d %d] = %lld\n",i,k,val);
            val = f(val);
            dp[k+1][j+1] = min(dp[k+1][j+1], dp[i][j]+val);
        }
    }

    ll ans = INF;
    rep(i,d+2) ans = min(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}
