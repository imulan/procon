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

using P = pair<ll,int>;

const int N = 2020;

int n;
ll a[N];
vector<P> v;

ll dp[N][N];
ll dfs(int l, int r){
    if(l>r) return 0;
    if(dp[l][r]>=0) return dp[l][r];
    int idx = l+(n-1-r);
    int p = v[idx].se;
    ll x = v[idx].fi;

    ll ret = 0;
    ret = max(ret, dfs(l+1,r)+x*(p-l));
    ret = max(ret, dfs(l,r-1)+x*(r-p));
    return dp[l][r] = ret;
}

int main(){
    cin >>n;
    rep(i,n) cin >>a[i];

    v = vector<P>(n);
    rep(i,n) v[i] = {a[i],i};
    sort(all(v), greater<P>());

    memset(dp,-1,sizeof(dp));
    cout << dfs(0,n-1) << "\n";
    return 0;
}
