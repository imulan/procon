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

const int PW = 100001;
ll pw[PW];

string n;
int N;
ll mod;

ll dp[PW][2];
ll dfs(int d, int s)
{
    if(d == (N+1)/2) return s;
    if(dp[d][s]>=0) return dp[d][s];

    ll ret = 0;

    int l=0;
    if(d==0) l=1;

    int r=9;
    if(s==0) r=n[d]-'0';

    for(int i=l; i<=r; ++i) (ret += dfs(d+1,s|(i<n[d]-'0')))%=mod;

    return dp[d][s] = ret;
}

ll solve()
{
    pw[0]=1;
    for(int i=1; i<PW; ++i) pw[i] = (pw[i-1]*10)%mod;

    ll ans = 0;
    for(int i=1; i<N; ++i) (ans+=9*pw[(i-1)/2])%=mod;

    memset(dp,-1,sizeof(dp));
    ans += dfs(0,0);

    string s=n;
    rep(i,(N+1)/2) s[N-1-i] = s[i];
    ans += (s<=n);

    return ans%mod;
}

int main()
{
    cin >>n;
    N = n.size();

    mod = 1e9;
    cout << solve() << endl;
    mod += 7;
    cout << solve() << endl;
    return 0;
}
