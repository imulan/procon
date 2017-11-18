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

const int N = 1010;
const ll mod = 1e9+7;

vector<int> a[26];

ll dp[N][N];
ll dfs(int l, int r)
{
    if(l>r) return 1;
    if(dp[l][r]>=0) return dp[l][r];

    ll ret = 1;
    rep(i,26)
    {
        auto itr = lower_bound(all(a[i]),l);
        int lidx = *itr;

        itr = upper_bound(all(a[i]),r);
        --itr;
        int ridx = *itr;

        if(lidx<ridx) (ret += dfs(lidx+1,ridx-1)) %= mod;
        if(lidx<=ridx) (ret += 1) %= mod;
    }

    return dp[l][r] = ret;
}

int main()
{
    string s;
    cin >>s;
    int n = s.size();

    rep(i,26) a[i].pb(-1);
    rep(i,n) a[s[i]-'a'].pb(i);
    rep(i,26) a[i].pb(n);

    memset(dp,-1,sizeof(dp));
    ll ans = dfs(0,n-1);

    ans = (ans-1+mod)%mod;
    cout << ans << endl;
    return 0;
}
