#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=1000;
int bit[N+2][N+2], n;

int _sum(int i, int j)
{
    int s=0;
    while(j>0)
    {
        s+=bit[i][j];
        j -= j & -j;
    }
    return s;
}

int sum(int i, int j)
{
    int s=0;
    while(i>0)
    {
        s+=_sum(i,j);
        i -= i & -i;
    }
    return s;
}

void _add(int i, int j, int x)
{
    while(j<=n)
    {
        bit[i][j]+=x;
        j += j & -j;
    }
}

void add(int i, int j, int x)
{
    while(i<=n)
    {
        _add(i,j,x);
        i += i & -i;
    }
}

int main()
{
    int X;
    scanf(" %d", &X);
    rep(cases,X)
    {
        if(cases) printf("\n");

        int T;
        scanf(" %d %d", &n, &T);

        memset(bit,0,sizeof(bit));
        while(T--)
        {
            char q;
            scanf(" %c", &q);
            if(q=='C')
            {
                int x1,y1,x2,y2;
                scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);
                add(x1,y1,1);
                add(x1,y2+1,-1);
                add(x2+1,y1,-1);
                add(x2+1,y2+1,1);
            }
            else
            {
                int x,y;
                scanf(" %d %d", &x, &y);
                printf("%d\n", sum(x,y)%2);
            }
        }

    }
    return 0;
}
