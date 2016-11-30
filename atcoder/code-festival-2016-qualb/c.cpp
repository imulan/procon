#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<ll,int> pi;

int main()
{
    int w,h;
    scanf(" %d %d", &w, &h);

    vector<pi> e;

    rep(i,w)
    {
        int c;
        scanf(" %d", &c);
        e.pb(pi(c,0));
    }
    rep(i,h)
    {
        int c;
        scanf(" %d", &c);
        e.pb(pi(c,1));
    }

    sort(all(e));

    ll ans=0;
    rep(i,e.size())
    {
        if(e[i].se==0)
        {
            ans+=e[i].fi*(h+1);
            --w;
        }
        else
        {
            ans+=e[i].fi*(w+1);
            --h;
        }
    }

    printf("%lld\n", ans);
    return 0;
}
