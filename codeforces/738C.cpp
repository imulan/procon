#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int INF=1010101010;

int solve()
{
    int n,k,s,t;
    scanf(" %d %d %d %d", &n, &k, &s, &t);

    // (cap, price)
    vector<int> c(n),v(n);
    rep(i,n) scanf(" %d %d", &c[i], &v[i]);

    vector<int> g(k);
    rep(i,k) scanf(" %d", &g[i]);
    g.pb(s);

    sort(all(g));

    if(s>t) return -1;

    int l=0, r=INF;
    while(r-l>1)
    {
        int m = (l+r)/2;

        bool ok = true;

        int now=0;
        int tt=0;
        rep(i,g.size())
        {
            int d = g[i]-now;

            if(d>m)
            {
                ok = false;
                break;
            }

            if(2*d<m) tt+=d;
            else
            {
                int x = m-d;
                tt += x+2*(d-x);
            }

            now = g[i];
        }

        if(tt>t) ok=false;

        if(ok) r=m;
        else l=m;
    }

    // printf("r = %d\n", r);

    int ans = INF;
    rep(i,n)
    {
        if(r<=v[i]) ans = min(ans,c[i]);
    }


    return (ans==INF)?-1:ans;
}

int main()
{
    printf("%d\n", solve());
    return 0;
}
