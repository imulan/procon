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

vector<ll> divisor(ll n)
{
    vector<ll> ret;
    for(ll i=2; i*i<=n; ++i)
    {
        if(n%i==0)
        {
            ret.pb(i);
            if(i != n/i) ret.pb(n/i);
        }
    }
    ret.pb(n);
    sort(all(ret));
    return ret;
}

vector<ll> d;
map<ll,ll> dp;
ll dfs(ll x)
{
    if(x==1) return 1;
    if(dp.count(x)) return dp[x];

    ll ret = 0;
    for(ll i:d)if(x%i==0)
    {
        ret = max(ret, i*dfs(x/i)+1);
    }

    // dbg(x);
    // dbg(ret);
    return dp[x]=ret;
}

ll solve(ll x)
{
    d = divisor(x);
    return dfs(x);
}

int main()
{
    int n;
    cin >>n;

    ll ans = 0;
    while(n--)
    {
        ll a;
        cin >>a;
        ans += solve(a);
    }
    cout << ans << endl;
    return 0;
}
