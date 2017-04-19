#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    int n,t;
    int s[1000],x[1000],y[1000];

    scanf(" %d %d", &n, &t);
    rep(i,n) scanf(" %d %d %d", &s[i], &x[i], &y[i]);

    int nearest[1000];
    memset(nearest,-1,sizeof(nearest));
    rep(i,n)
    {
        if(s[i]==1) nearest[i]=i;
        else
        {
            int d=123456789;
            rep(j,n)if(s[j]==1)
            {
                int td = abs(x[i]-x[j])+abs(y[i]-y[j]);
                if(d>td)
                {
                    d=td;
                    nearest[i]=j;
                }
            }
        }
    }

    int Q;
    scanf(" %d", &Q);
    while(Q--)
    {
        int a,b;
        scanf(" %d %d", &a, &b);
        --a;
        --b;

        // 直接行く
        int ans = abs(x[a]-x[b])+abs(y[a]-y[b]);

        // ワープする
        int na=nearest[a], nb=nearest[b];
        if(na!=-1)
        {
            int A = abs(x[a]-x[na])+abs(y[a]-y[na]);
            int B = abs(x[b]-x[nb])+abs(y[b]-y[nb]);
            ans = min(ans, A+B+t);
        }
        printf("%d\n", ans);
    }
    return 0;
}
