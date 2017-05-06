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
    while(scanf(" %d", &n),n)
    {
        vector<int> p(n),j(n-1);
        rep(i,n) scanf(" %d", &p[i]);
        rep(i,n-1) scanf(" %d", &j[i]);

        sort(all(j),greater<int>());

        ll P=0;
        rep(i,n) P+=p[i];

        ll ans=P*n;
        rep(i,n-1)
        {
            P+=j[i];
            ans = max(ans, P*(n-i-1));
        }

        printf("%lld\n", ans);
    }
    return 0;
}
