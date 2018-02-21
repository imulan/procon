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

const int N = 5005;
int dp[N][N];

int mod[7];
int num[100001];

int main(){
    int n;
    cin >>n;
    vector<int> a(n+1);
    rep(i,n){
        cin >>a[i+1];
        --a[i+1];
    }

    for(int i=1; i<=n; ++i){
        dp[i][0] = 1;
        rep(j,i){
            if((a[i]%7 == a[j]%7) || (abs(a[j]-a[i])==1)) dp[i][0] = max(dp[i][0],dp[j][0]+1);
        }
        memset(mod,0,sizeof(mod));
        memset(num,0,sizeof(num));

        rep(j,i){
            mod[a[j]%7] = max(mod[a[j]%7], dp[i][j]);
            num[a[j]] = max(num[a[j]], dp[i][j]);
        }

        for(int j=i+1; j<=n; ++j){
            dp[j][i] = dp[i][0] + 1;
            dp[j][i] = max(dp[j][i], mod[a[j]%7]+1);
            dp[j][i] = max(dp[j][i], num[a[j]+1]+1);
            dp[j][i] = max(dp[j][i], num[a[j]-1]+1);

            mod[a[j]%7] = max(mod[a[j]%7], dp[j][i]);
            num[a[j]] = max(num[a[j]], dp[j][i]);
        }
    }

    // rep(i,n+1)rep(j,n+1) printf("dp[%d][%d] %d\n",i,j,dp[i][j]);

    int ans = 0;
    rep(i,N)rep(j,N) ans = max(ans,dp[i][j]);
    cout << ans << endl;
    return 0;
}
