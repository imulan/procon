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
    int n;
    scanf(" %d", &n);

    vector<int> a(n);
    vector<int> f(n+1);
    rep(i,n)
    {
        scanf(" %d", &a[i]);
        f[a[i]]=i;
    }

    set<int> ids;
    ids.insert(-1);
    ids.insert(n);

    ll ans=0;

    for(int i=1; i<=n; ++i)
    {
        auto l = ids.lower_bound(f[i]);
        auto r = ids.lower_bound(f[i]);
        --l;

        ans += (ll)(f[i] - *l)*(*r - f[i])*i;
        ids.insert(f[i]);
    }

    cout << ans << endl;
    return 0;
}
