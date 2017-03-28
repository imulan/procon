#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const double eps = 1e-8;

int main()
{
    int n,a,b;
    cin >>n >>a >>b;
    vector<ll> v(n);
    rep(i,n) cin >>v[i];

    sort(all(v),greater<ll>());

    long double max_av = 0;
    for(int i=a; i<=b; ++i)
    {
        long double t = 0;
        rep(j,i) t+=v[j];
        t/=i;
        max_av = max(max_av, t);
    }

    ll C[51][51]={};
    C[0][0]=1;
    for(int i=1; i<=50; ++i)
    {
        C[i][0]=C[i][i]=1;
        for(int j=1; j<i; ++j) C[i][j]=C[i-1][j-1]+C[i-1][j];
    }

    ll ans = 0;
    for(int i=a; i<=b; ++i)
    {
        long double t = 0;
        rep(j,i) t+=v[j];
        t/=i;

        if(fabs(max_av - t)<eps)
        {
            ll f_v = v[i-1];

            int l=i-1, r=i-1;
            while(l>=0 && v[l]==f_v) --l;
            ++l;
            while(r<n && v[r]==f_v) ++r;
            --r;

            ans += C[r-l+1][i-1-l+1];
        }
    }

    printf("%.10Lf\n", max_av);
    printf("%lld\n", ans);
    return 0;
}
