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

const int N = 5005;
int dp[N][N];

int main(){
    int n,k;
    scanf(" %d %d", &n, &k);

    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);
    sort(all(a));

    vector<int> u(a);
    u.erase(unique(all(u)), u.end());
    int U = u.size();

    vector<int> cu(U);
    rep(i,n){
        int idx = lower_bound(all(u), a[i])-u.begin();
        ++cu[idx];
    }

    rep(i,U)rep(j,k+1){
        if(j<k){
            int ni = upper_bound(all(u), u[i]+5)-u.begin();
            int add = 0;
            for(int x=i; x<ni; ++x) add += cu[x];
            dp[ni][j+1] = max(dp[ni][j+1], dp[i][j]+add);
        }

        dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
    }

    int ans = 0;
    rep(i,k+1) ans = max(ans, dp[U][i]);
    printf("%d\n", ans);
    return 0;
}
