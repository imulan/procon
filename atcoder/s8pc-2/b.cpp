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

int main()
{
    ll n;
    int q;
    cin >>n >>q;

    vector<ll> a(q);
    rep(i,q) cin >>a[i];

    set<ll> ans;

    rep(i,1<<q)
    {
        ll t=1;
        rep(j,q)
        {
            if(i>>j&1) t*=a[j];
            if(t>n) break;
        }

        if(t>n) continue;

        ll d=t;

        rep(j,q)
        {
            if(t%a[j]==0) t/=a[j];
        }

        if(t==1) ans.insert(d);
    }

    cout << ans.size() << endl;

    return 0;
}
