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
    vector<ll> v(n);
    rep(i,n) scanf(" %lld", &v[i]);

    ll ans = LLONG_MAX;
    rep(head,2)
    {
        ll ct=0;
        ll s=0;

        vector<ll> a(v);
        rep(i,n)
        {
            if((head+i)%2==0)
            {
                // s>0にしたい
                if(s+a[i]<=0)
                {
                    ct += 1-(s+a[i]);
                    a[i] = 1-s;
                }
                s += a[i];
            }
            else
            {
                // s<0にしたい
                if(s+a[i]>=0)
                {
                    ct += s+a[i]+1;
                    a[i] = -s-1;
                }
                s += a[i];
            }
        }
        ans = min(ans,ct);
    }

    printf("%lld\n", ans);
    return 0;
}
