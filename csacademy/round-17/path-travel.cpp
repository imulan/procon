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
    int N,R,B;
    scanf(" %d %d %d", &N, &R, &B);

    vector<int> r(R), b(B);
    rep(i,R) scanf(" %d", &r[i]);
    rep(i,B) scanf(" %d", &b[i]);

    sort(all(r));
    sort(all(b));

    ll ans = 0;
    rep(i,R)
    {
        int d=N+1;
        auto itr = lower_bound(all(b),r[i]);

        if(itr==b.begin()) d = *itr-r[i];
        else if(itr==b.end())
        {
            --itr;
            d = r[i]-*itr;
        }
        else
        {
            d = min(d,*itr-r[i]);
            --itr;
            d = min(d,r[i]-*itr);
        }

        ans += d;
    }

    printf("%lld\n", ans);
    return 0;
}
