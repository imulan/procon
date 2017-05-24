#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    int n;
    scanf(" %d", &n);
    vector<ll> d(n);
    rep(i,n) scanf(" %lld", &d[i]);

    vector<ll> sum(n);
    sum[0]=d[0];
    for(int i=1; i<n; ++i) sum[i]=sum[i-1]+d[i];

    map<ll,int> r;
    rep(i,n) r[sum[i]]=i;

    ll c=0;
    int ans = 0;
    rep(i,n)
    {
        if(r.count(c)) ans = max(ans,r[c]-i+1);
        c += d[i];
    }

    printf("%d\n", ans);
    return 0;
}
