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

const ll INF = LLONG_MAX/3;

int main(){
    int n;
    scanf(" %d", &n);

    int me = -1;
    vector<int> a(n);
    rep(i,n){
        scanf(" %d", &a[i]);
        if(a[i] == -1) me = i;
    }

    int x = 0;
    while((1<<x) != n) ++x;

    vector<int> need(x);
    for(int i=1; i<x; ++i) need[i] = need[i-1]+(1<<i)-1;

    vector<vector<ll>> dp(n+1, vector<ll>(x+1, INF));
    dp[0][0] = 0;
    rep(i,n)rep(j,x+1){
        dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
        if(j==x || i==me) continue;

        int d = i-j;
        if(i>me) --d;
        if(d>=need[j]){
            ll add = a[i];
            if(i<me) add = 0;
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+add);
        }
    }
    printf("%lld\n", dp[n][x]);
    return 0;
}
