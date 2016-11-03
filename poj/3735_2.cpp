#include <cstdio>
#include <iostream>
#include <algorithm>
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
    int n,m,k;
    while(scanf(" %d %d %d", &n ,&m, &k),n|m|k)
    {
        int ref[31][101]={0};
        ll add[31][101]={0};

        rep(i,101) ref[0][i]=i;

        rep(i,k)
        {
            char op;
            scanf(" %c", &op);
            if(op=='g')
            {
                int x;
                scanf(" %d", &x);
                ++add[0][x];
            }
            else if(op=='e')
            {
                int x;
                scanf(" %d", &x);
                add[0][x]=0;
                ref[0][x]=0;
            }
            else if(op=='s')
            {
                int x,y;
                scanf(" %d %d", &x, &y);
                swap(ref[0][x],ref[0][y]);
                swap(add[0][x],add[0][y]);
            }
        }

        for(int i=1; i<=30; ++i)for(int j=1; j<=n; ++j)
        {
            ref[i][j]=ref[i-1][ref[i-1][j]];
            add[i][j]=add[i-1][j]+add[i-1][ref[i-1][j]];
            // printf("(%d,%d) ref %d, add %lld\n", i,j,ref[i][j],add[i][j]);
        }

        int nref[101]={0};
        rep(i,101) nref[i]=i;
        ll ans[101]={0};
        rep(i,31)
        {
            if(m>>i&1)
            {
                ll nxans[101];
                for(int j=1; j<=n; ++j) nxans[j]=add[i][nref[j]]+ans[j];
                rep(j,n+1) nref[j]=ref[i][nref[j]];
                rep(j,101) ans[j]=nxans[j];
            }
        }

        for(int i=1; i<=n; ++i)
        {
            if(i>1) printf(" ");
            printf("%lld", ans[i]);
        }
        printf("\n");
    }

    return 0;
}
