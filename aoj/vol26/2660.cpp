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

const int N = 334;
const ll INF = LLONG_MAX/3;

int n,a[N],s[N];

ll f(ll x, ll y){
    int c = 0;
    ll ret = 0;
    while(x>0 || y>0 || c>0){
        int xx = x%10, yy = y%10;
        ret += xx*yy + c;

        x /= 10;
        y /= 10;
        c = (xx+yy+c>=10);
    }
    return ret;
}

ll dp[N][N];
ll dfs(int l, int r){
    if(dp[l][r]>=0) return dp[l][r];
    if(r-l == 1) return 0;

    ll ret = INF;
    for(int i=l+1; i<r; ++i){
        ll X = s[i]-s[l];
        ll Y = s[r]-s[i];
        ret = min(ret, dfs(l,i)+dfs(i,r)+f(X,Y));
    }
    return dp[l][r] = ret;
}

int main(){
    scanf(" %d", &n);
    rep(i,n) scanf(" %d", &a[i]);

    rep(i,n) s[i+1] += s[i]+a[i];
    memset(dp, -1, sizeof(dp));
    printf("%lld\n", dfs(0,n));
    return 0;
}
