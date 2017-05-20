#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=300000;
const ll INF=LLONG_MAX/3;
ll pre[N];
ll suf[N];

int main()
{
    int n;
    scanf(" %d", &n);

    int m=3*n;
    vector<ll> a(m);
    rep(i,m) scanf(" %lld", &a[i]);

    fill(pre,pre+N,0);
    fill(suf,suf+N,INF);

    ll s=0;
    multiset<ll> x;
    rep(i,n)
    {
        s+=a[i];
        x.insert(a[i]);
    }

    pre[n-1] = s;
    for(int i=n; i<2*n; ++i)
    {
        ll min_x = *x.begin();
        if(a[i]>min_x)
        {
            s = s-min_x+a[i];

            auto itr = x.begin();
            x.erase(itr);
            x.insert(a[i]);
        }

        pre[i] = s;
    }

    s=0;
    x.clear();
    for(int i=2*n; i<m; ++i)
    {
        s+=a[i];
        x.insert(a[i]);
    }

    suf[2*n]=s;
    for(int i=2*n-1; i>=n; --i)
    {
        ll max_x = *x.rbegin();
        if(a[i]<max_x)
        {
            s = s-max_x+a[i];

            auto itr = x.find(max_x);
            x.erase(itr);
            x.insert(a[i]);
        }

        suf[i]=s;
    }

    ll ans=-INF;
    for(int i=n-1; i<2*n; ++i) ans = max(ans, pre[i] - suf[i+1]);
    printf("%lld\n", ans);
    return 0;
}
