#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;

int main()
{
    int n,m,h,k;
    while(scanf(" %d %d %d %d", &n, &m, &h, &k),n)
    {
        vector<int> s(n);
        rep(i,n) scanf(" %d", &s[i]);

        vector<pi> e(m);
        rep(i,m)
        {
            scanf(" %d %d", &e[i].se, &e[i].fi);
            --e[i].se;
        }
        sort(all(e));

        vector<int> f(n);
        rep(i,n) f[i]=i;

        vector<pi> sw(m);
        rep(i,m)
        {
            int a=e[i].se;

            sw[i] = pi(f[a],f[a+1]);
            swap(f[a],f[a+1]);
        }

        vector<int> F(n);
        rep(i,n) F[f[i]]=i;

        int sum=0;
        rep(i,k) sum+=s[F[i]];

        int ans=sum;
        rep(i,m)
        {
            int a=sw[i].fi, b=sw[i].se;
            if(a>b) swap(a,b);

            if(a<k && k<=b) ans=min(ans,sum-s[F[a]]+s[F[b]]);
        }

        printf("%d\n", ans);
    }
    return 0;
}
