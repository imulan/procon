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

int n;

void mul(ll a[101][101], ll b[101][101], ll dst[101][101])
{
    ll c[101][101]={0};
    rep(i,n)rep(k,n)
    {
        if(a[i][k]!=0) rep(j,n) c[i][j]+=a[i][k]*b[k][j];
    }

    rep(i,n)rep(j,n) dst[i][j]=c[i][j];
}

int main()
{
    int m,k;
    while(scanf(" %d %d %d", &n ,&m, &k),n|m|k)
    {
        n+=1;
        ll A[101][101]={0};
        rep(i,n) A[i][i]=1;

        rep(i,k)
        {
            char op;
            scanf(" %c", &op);
            if(op=='g')
            {
                int x;
                scanf(" %d", &x);
                A[x][0]+=1;
            }
            else if(op=='e')
            {
                int x;
                scanf(" %d", &x);
                rep(j,n) A[x][j]=0;
            }
            else if(op=='s')
            {
                int x,y;
                scanf(" %d %d", &x, &y);
                swap(A[x],A[y]);
            }
        }

        ll P[30][101][101]={0};
        rep(i,n)rep(j,n) P[0][i][j]=A[i][j];
        for(int i=1; i<30; ++i) mul(P[i-1],P[i-1],P[i]);

        ll Q[101][101]={0};
        rep(i,n) Q[i][i]=1;
        for(int i=29; i>=0; --i)
        {
            if(m-(1<<i)>=0)
            {
                mul(P[i],Q,Q);
                m-=(1<<i);
            }
        }

        for(int i=1; i<n; ++i)
        {
            if(i>1) printf(" ");
            printf("%lld", Q[i][0]);
        }
        printf("\n");
    }

    return 0;
}
