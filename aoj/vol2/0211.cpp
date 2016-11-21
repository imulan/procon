#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

inline ll lcm(ll x, ll y)
{
    return x/__gcd(x,y)*y;
}

int main()
{
    int n;
    while(cin >>n,n)
    {
        vector<ll> d(n),v(n);
        rep(i,n) cin >>d[i] >>v[i];

        ll T=1;
        rep(i,n)
        {
            ll G=__gcd(v[i],d[i]);
            T=lcm(T,d[i]/G);
        }

        vector<ll> ans(n);
        rep(i,n) ans[i]=v[i]*T/d[i];

        ll div=ans[0];
        for(int i=1; i<n; ++i) div=__gcd(div,ans[i]);
        rep(i,n) cout << ans[i]/div << endl;
    }
    return 0;
}
