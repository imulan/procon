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

const int N = 3003;
const int INF = 19191919;
int dp[N][N];

int main(){
    int n;
    cin >>n;
    vector<ll> b(n+1);
    rep(i,n) cin >>b[i+1];

    vector<ll> preb(b);
    rep(i,n) preb[i+1] += preb[i];

    fill(dp[0],dp[N],-INF);
    dp[1][1] = 0;

    for(int i=1; i<=n; ++i){

        int max_val = -INF;
        int idx = i;
        for(int j=i; j<=n; ++j){
            ll num = preb[j] - preb[i-1];
            // dbg(num);

            while(idx>0){
                ll tmp = preb[i-1] - preb[idx-1];
                if(tmp <= num){
                    max_val = max(max_val, dp[i][idx]);
                    --idx;
                }
                else break;
                // dbg(tmp);
            }

            dp[j+1][i] = max(dp[j+1][i], max_val+1);
            // printf(" %d %d  : %d\n",j+1,i,dp[j+1][i]);
        }
    }

    int ans = 0;
    rep(i,N)rep(j,N) ans = max(ans,dp[i][j]);
    cout << ans << endl;
    return 0;
}
