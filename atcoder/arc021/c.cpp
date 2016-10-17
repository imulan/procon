#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<ll,int> P;

const ll INF=1234567890123LL;

int main()
{
    int k,n;
    scanf(" %d %d", &k, &n);
    vector<P> b(n);
    rep(i,n) scanf(" %lld %d", &b[i].fi, &b[i].se);

    sort(all(b));

    ll l=0, r=1234567890;
    while(r-l>1)
    {
        bool large=false;
        ll m=(l+r)/2;

        ll ct=0;
        rep(i,n)
        {
            //x回増築できる x<=(m-a_i)/d_i
            ll x = (m-b[i].fi)/b[i].se;
            if(x<0) x=0;

            ct+=x;
            if(x>k)
            {
                large=true;
                break;
            }
        }

        if(ct+n>k) large=true;

        if(large) r=m;
        else l=m;
    }

    // 全部lまで値段上げちゃっていい
    ll ans=0;
    ll ct=0;
    rep(i,n)
    {
        ll x = (l-b[i].fi)/b[i].se;
        if(x<0) x=0;

        ct+=x;
        ans+=x*b[i].fi;
        ans+=(x-1)*x/2*b[i].se;

        b[i].fi+=x*b[i].se;
    }

    priority_queue<P,vector<P>,greater<P>> pq;
    rep(i,n) pq.push(b[i]);

    while(ct<k)
    {
        P v=pq.top();
        pq.pop();

        ans+=v.fi;
        v.fi+=v.se;
        pq.push(v);
        ++ct;
    }

    cout << ans << endl;
    return 0;
}
