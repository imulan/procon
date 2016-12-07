#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

vector<ll> factorize(ll n)
{
    vector<ll> ret;

    ll t=n;
    for(ll i=2; i*i<=n; ++i)
    {
        while(t%i==0)
        {
            t/=i;
            ret.pb(i);
        }
    }
    if(t>1) ret.pb(t);
    sort(all(ret),greater<ll>());
    return ret;
}

const ll INF=1234567890123456LL;

vector<ll> d;
int D;
vector<ll> m;

typedef pair<ll,ll> pl;
typedef pair<int,pl> P;
map<P,ll> dp;

ll dfs(int now, ll a, ll c)
{
    ll b = m[now]/a/c;

    if(!(a<=b && b<=c)) return INF;
    if(now==D) return a+b+c-3;

    P state(now,pl(a,c));

    if(dp.find(state) != dp.end()) return dp[state];

    ll ret=INF;

    ll na=a*d[now], nb=b*d[now], nc=c*d[now];
    ret = min(ret, dfs(now+1, min({na,b,c}), max({na,b,c})));
    ret = min(ret, dfs(now+1, min({a,nb,c}), max({a,nb,c})));
    ret = min(ret, dfs(now+1, min({a,b,nc}), max({a,b,nc})));

    dp[state]=ret;
    return ret;
}

int main()
{
    ll n;
    cin >>n;

    d=factorize(n);
    D = d.size();

    m = vector<ll>(D+1);
    m[0]=1;
    for(int i=1; i<=D; ++i) m[i]=m[i-1]*d[i-1];

    cout << dfs(0,1,1) << " " << n-1 << endl;
    return 0;
}
