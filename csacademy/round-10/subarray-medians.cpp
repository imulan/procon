#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;

int main()
{
    int n;
    scanf(" %d",&n);
    vector<ll> a(n);
    rep(i,n) scanf(" %lld", &a[i]);

    ll ans=0;

    rep(i,n)
    {
        int L = n-i;

        int end = n-1;
        if(L%2==0)
        {
            --end;
            --L;
        }

        vector<bool> b(n+1);
        for(int j=i; j<=end; ++j) b[a[j]] = true;

        vector<pi> p(n+1,pi(0,0));
        int last=0;
        for(int j=1; j<=n; ++j)
        {
            if(b[j])
            {
                p[last].se=j;
                p[j].fi=last;
                last = j;
            }
        }

        int m=0;
        int center = (L+1)/2;
        int pos=center;
        rep(j,center) m=p[m].se;

        ans += (ll)(i+1)*(end+1)*m;

        for(int j=end; j>i; j-=2)
        {
            rep(k,2)
            {
                int pre = p[a[j-k]].fi, post = p[a[j-k]].se;
                p[pre].se = post;
                p[post].fi = pre;

                if(a[j-k]==m)
                {
                    if(p[m].fi!=0)
                    {
                        m=p[m].fi;
                        --pos;
                    }
                    else m=p[m].se;
                }
                else
                {
                    if(a[j-k]<m) --pos;
                }
            }

            --center;
            while(pos<center)
            {
                m = p[m].se;
                ++pos;
            }
            while(pos>center)
            {
                m = p[m].fi;
                --pos;
            }

            ans += (ll)(i+1)*(j-1)*m;
        }
    }

    printf("%lld\n", ans);
    return 0;
}
