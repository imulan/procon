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

const int N = 10010;
const ll INF = LLONG_MAX/3;
ll dp[N];

int main(){
    int c,n,m;
    scanf(" %d %d %d", &c, &n, &m);

    vector<int> s(n),p(n);
    rep(i,n) scanf(" %d %d", &s[i], &p[i]);

    fill(dp,dp+N,-INF);
    dp[0] = 0;
    rep(i,n){
        for(int j=N-1; j>=0; --j){
            int nx = j+s[i];
            if(nx>=N) continue;
            dp[nx] = max(dp[nx], dp[j]+p[i]);
        }
    }

    for(int i=1; i<=m; ++i){
        int lim = c/i;
        ll ans = -INF;
        rep(j,lim+1) ans = max(ans, dp[j]);
        printf("%lld\n", ans*i);
    }

    return 0;
}
