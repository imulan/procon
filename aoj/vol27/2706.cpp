#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;

vector<pi> f(int n)
{
    int t=n;
    vector<pi> ret;
    for(int i=2; i*i<=n; ++i)
    {
        if(t%i==0)
        {
            pi add(i,0);
            while(t%i==0)
            {
                ++add.se;
                t/=i;
            }
            ret.pb(add);
        }
    }
    if(t>1) ret.pb(pi(t,1));
    return ret;
}

int main()
{
    int p,q;
    cin >>p >>q;

    int g=__gcd(p,q);
    p/=g;
    q/=g;

    vector<pi> d=f(q);
    // rep(i,d.size()) printf("%d: %d\n", d[i].fi,d[i].se);

    ll ans=1;
    rep(i,d.size()) ans*=d[i].fi;
    cout << ans << endl;
    return 0;
}
