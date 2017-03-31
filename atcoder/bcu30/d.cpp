#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    int n,q;
    scanf(" %d %d", &n, &q);
    vector<int> x(n);
    rep(i,n) scanf(" %d", &x[i]);

    vector<ll> sumx(n+1,0);
    rep(i,n) sumx[i+1]=sumx[i]+x[i];

    while(q--)
    {
        ll t;
        scanf(" %lld", &t);

        ll ans = 0;
        int idx = lower_bound(all(x),t) - x.begin();

        ans += t*idx;
        ans -= sumx[idx];
        ans += sumx[n] - sumx[idx];
        ans -= t*(n-idx);

        printf("%lld\n", ans);
    }

    return 0;
}
