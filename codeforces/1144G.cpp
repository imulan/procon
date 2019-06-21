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

const int N = 200002;
const int INF = 10101010;

int dp[N][2];
pi par[N][2];

int main(){
    int n;
    scanf(" %d", &n);

    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    rep(i,N){
        dp[i][0] = -INF;
        dp[i][1] = INF;
    }

    dp[0][0] = INF;
    dp[0][1] = -INF;
    for(int i=1; i<n; ++i){
        if(a[i] > a[i-1]){
            if(dp[i-1][0] > dp[i][0]){
                dp[i][0] = dp[i-1][0];
                par[i][0] = {i-1,0};
            }
        }
        if(a[i] < dp[i-1][0]){
            if(a[i-1] < dp[i][1]){
                dp[i][1] = a[i-1];
                par[i][1] = {i-1,0};
            }
        }
        if(a[i] < a[i-1]){
            if(dp[i-1][1] < dp[i][1]){
                dp[i][1] = dp[i-1][1];
                par[i][1] = {i-1,1};
            }
        }
        if(a[i] > dp[i-1][1]){
            if(dp[i][0] < a[i-1]){
                dp[i][0] = a[i-1];
                par[i][0] = {i-1,1};
            }
        }
    }

    if(dp[n-1][0]==-INF && dp[n-1][1]==INF) printf("NO\n");
    else{
        printf("YES\n");
        pi c;
        if(dp[n-1][0]>-INF) c = {n-1,0};
        if(dp[n-1][1]< INF) c = {n-1,1};

        vector<int> ans(n);
        rep(i,n){
            ans[c.fi] = c.se;
            c = par[c.fi][c.se];
        }

        rep(i,n) printf("%d%c", ans[i], " \n"[i==n-1]);
    }
    return 0;
}
