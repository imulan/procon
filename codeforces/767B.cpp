#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

ll solve()
{
    ll ts,tf,t;
    scanf(" %lld %lld %lld", &ts, &tf, &t);
    int n;
    scanf(" %d", &n);
    vector<ll> c(n);
    rep(i,n) scanf(" %lld", &c[i]);

    if(n==0) return ts;
    if(ts<c[0]) return ts;

    ll spend=123456789012345678LL;
    ll ret=-1;

    ll start = ts;
    rep(i,n)
    {
        // printf("start = %lld\n", start);
        ll arrive=c[i]-1;
        ll wait = max(0LL,start-arrive);
        if(spend > wait)
        {
            spend=wait;
            ret=arrive;
        }
        start = max(start+t, c[i]+t);

        if(start>tf-t) break;
    }

    if(start<=tf-t)
    {
        spend=0;
        ret=start;
    }

    assert(ret!=-1);
    return ret;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
