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
    int T;
    scanf(" %d", &T);
    while(T--)
    {
        int n,Q;
        scanf(" %d %d", &n, &Q);
        vector<int> a(n);
        rep(i,n) scanf(" %d", &a[i]);

        sort(all(a));

        vector<ll> suma(n+1);
        rep(i,n) suma[i+1] = suma[i]+a[i];

        while(Q--)
        {
            ll K;
            scanf(" %lld", &K);

            int idx = lower_bound(all(a),K)-a.begin();
            int v = n-idx;

            int l=0,r=idx;
            while(r-l>1)
            {
                int m=(l+r)/2;
                ll eat = K*m - (suma[idx]-suma[idx-m]);
                int rem = idx-m;

                if(rem>=eat) l=m;
                else r=m;
            }

            printf("%d\n", v+l);
        }
    }
    return 0;
}
