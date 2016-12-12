#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll mod=1e9+7;
typedef pair<int,ll> P;

inline ll fact(int n)
{
    ll ret=1;
    for(ll i=2; i<=n; ++i) (ret*=i)%=mod;
    return ret;
}

inline bool canmove(ll from, ll to)
{
    rep(i,63)
    {
        if((from>>i&1LL) && !(to>>i&1LL)) return false;
    }
    return true;
}

ll solve()
{
    int n,k;
    scanf(" %d %d", &n, &k);

    int ct[61]={};

    vector<P> s;

    s.pb(P(0,0));
    s.pb(P(n,(1LL<<n)-1));

    rep(i,k)
    {
        ll t;
        scanf(" %lld", &t);
        ++ct[__builtin_popcountll(t)];
        s.pb(P(__builtin_popcountll(t),t));
    }

    if(k==0) return fact(n);
    rep(i,61) if(ct[i]>1) return 0;

    sort(all(s));
    s.erase(unique(all(s)),s.end());

    k=s.size();
    vector<ll> a(k);
    rep(i,k) a[i]=s[i].se;

    // rep(i,k) printf("a[%d] = %lld\n", i,a[i]);

    ll ret=1;
    rep(i,k-1)
    {
        if(!canmove(a[i],a[i+1])) return 0;
        (ret*=fact(__builtin_popcountll(a[i+1])-__builtin_popcountll(a[i])))%=mod;
    }
    return ret;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
