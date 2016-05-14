#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

typedef pair<ll,ll> p;
typedef pair<ll,p> pp;
int main()
{
    int n;
    cin >>n;

    vector<p> m(n);
    rep(i,n) scanf(" %lld %lld", &m[i].fi, &m[i].se);

    vector<p> a,b;
    rep(i,n)
    {
        if(m[i].fi<m[i].se) a.pb(m[i]);
        else b.pb(m[i]);
    }

    sort(all(a));

    rep(i,b.size()) swap(b[i].fi,b[i].se);
    sort(all(b),greater<p>());
    rep(i,b.size()) swap(b[i].fi,b[i].se);

    ll ans=0;
    ll now=0;
    rep(i,a.size())
    {
        now+=a[i].fi;
        ans=max(ans,now);
        now-=a[i].se;
    }

    rep(i,b.size())
    {
        now+=b[i].fi;
        ans=max(ans,now);
        now-=b[i].se;
    }

    std::cout << ans << std::endl;
    return 0;
}
