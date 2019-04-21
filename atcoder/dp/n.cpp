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

const int N = 404;
const ll INF = LLONG_MAX/3;

int n;
ll a[N];

ll sa[N];
ll s(int l, int r){
    ll ret = sa[r];
    if(l>0) ret -= sa[l-1];
    return ret;
}

ll dp[N][N];
ll dfs(int l, int r){
    if(l>=r) return 0;
    if(dp[l][r]>=0) return dp[l][r];

    ll ret = INF;
    for(int i=l; i<r; ++i) ret = min(ret, dfs(l,i)+dfs(i+1,r));
    ret += s(l,r);
    return dp[l][r] = ret;
}

int main(){
    cin >>n;
    rep(i,n) cin >>a[i];

    sa[0] = a[0];
    for(int i=1; i<n; ++i) sa[i] = sa[i-1]+a[i];

    memset(dp,-1,sizeof(dp));
    cout << dfs(0,n-1) << "\n";
    return 0;
}
