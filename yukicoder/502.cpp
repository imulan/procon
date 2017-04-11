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

ll mod_fact(ll n)
{
    ll ret=1;
    for(ll i=2; i<=n; ++i)
    {
        (ret*=i)%=mod;
        if(i%30000000==0) printf("%lld,", ret);
    }
    printf("\n");
    return ret;
}

ll solve(ll n)
{
    if(n>=mod) return 0;

    vector<ll> v({1,76479948,27368307,888050723,661224977,261384175,547665832,724691727,136026497,217544623,668123525,522049725,189239124,917084264,358655417,462639908,99199382,97830135,141827977,811575797,724464507,456152084,769795511,825871994,852304035,217598709,624500515,423951674,814362881,256473217,586445753,778983779,965785236,847549272});

    ll ret=1;
    int idx=0;
    while((idx+1LL)*30000000<=n) ++idx;

    (ret*=v[idx])%=mod;
    ll start = idx*30000000LL;
    for(ll i=start+1; i<=n; ++i) (ret*=i)%=mod;
    return ret;
}

int main()
{
    // mod_fact(mod-1);
    ll n;
    cin >>n;
    cout << solve(n) << endl;
    return 0;
}
