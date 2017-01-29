#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef vector<int> vi;

int main()
{
    int n,m,K;
    cin >>n >>m >>K;

    vector<vi> c(n,vi(m,-1));

    // 縦
    int l=0,r=n-1;
    for(int i=n-1; i>0; --i)
    {
        int now = n-1-i;
        // printf("now = %d\n", now);
        if(K - i*m >= 0)
        {
            c[r--][0]=m*now;
            K -= i*m;
        }
        else c[l++][0]=m*now;
    }
    c[l][0]=(n-1)*m;

    // printf("K %d\n", K);

    // 横
    rep(i,n)
    {
        int val = c[i][0];
        l=0;
        r=m-1;
        for(int j=m-1; j>0; --j)
        {
            int now = m-1-j+val;
            // printf("  now = %d\n", now);
            if(K - j >= 0)
            {
                c[i][r--]=now;
                K -= j;
            }
            else c[i][l++]=now;
        }
        c[i][l]=val+m-1;
    }

    // output
    rep(i,n)
    {
        rep(j,m)
        {
            if(j) printf(" ");
            printf("%d", c[i][j]+1);
        }
        printf("\n");
    }
    return 0;
}
