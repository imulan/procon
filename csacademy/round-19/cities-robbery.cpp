#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll INF= LLONG_MAX/4;

using P = pair<int,ll>;

int main()
{
    int n,X,K;
    scanf(" %d %d %d", &n, &X, &K);

    vector<P> c(n);
    rep(i,n) scanf(" %d %lld", &c[i].fi, &c[i].se);
    sort(all(c));

    int B = lower_bound(all(c),P(X,INF))-c.begin();

    vector<ll> sumw(n+1);
    rep(i,n) sumw[i+1] = sumw[i]+c[i].se;

    ll ans=0;
    // iまで行ってから、戻れるところまで引き返す
    rep(i,B)
    {
        int d = X-c[i].fi;
        int r = K-d;
        if(r<0) continue;

        int idx = lower_bound(all(c),P(c[i].fi+r,INF))-c.begin()-1;

        int j = max(idx,B-1);
        ans = max(ans,sumw[j+1]-sumw[i]);
    }
    for(int i=B; i<n; ++i)
    {
        int d = c[i].fi-X;
        int r = K-d;
        if(r<0) continue;

        int idx = lower_bound(all(c),P(c[i].fi-r,0))-c.begin();

        int j = min(idx,B);
        ans = max(ans,sumw[i+1]-sumw[j]);
    }

    printf("%lld\n", ans);
    return 0;
}
