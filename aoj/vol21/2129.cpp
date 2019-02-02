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

const ll INF = LLONG_MAX/3;

ll solve(int n, int w){
    vector<ll> a(n);
    rep(i,n) scanf(" %lld", &a[i]);

    vector<ll> dp(n+1,INF);
    dp[0] = 0;
    rep(i,n){
        ll s = 0;
        for(int j=i; j<n; ++j){
            s += a[j];

            ll cost = abs(s-w);
            if(j==n-1) cost = max(0LL, s-w);

            dp[j+1] = min(dp[j+1], dp[i]+cost);
        }
    }
    return dp[n];
}

int main(){
    int C = 1;
    int n,w;
    while(scanf(" %d %d", &n, &w),n){
        printf("Case %lld: %d\n", C++, solve(n,w));
    }
    return 0;
}
