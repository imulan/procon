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
    int n;
    scanf(" %d", &n);

    if(n==1)
    {
        printf("! 1\n");
        fflush(stdout);
        return 0;
    }

    vector<int> dist0(n+1);
    for(int i=2; i<=n; ++i)
    {
        printf("? 1 %d\n", i);
        fflush(stdout);

        scanf(" %d", &dist0[i]);
    }

    int A=-1;
    int max_dist0=0;
    for(int i=2; i<=n; ++i)
    {
        if(max_dist0 < dist0[i])
        {
            max_dist0 = dist0[i];
            A = i;
        }
    }

    assert(A>0);

    vector<int> x(n);
    x[0]=A;
    for(int i=1; i<=n; ++i)if(A!=i)
    {
        printf("? %d %d\n", A,i);
        fflush(stdout);

        int d;
        scanf(" %d", &d);
        x[d]=i;
    }

    // output
    printf("!");
    rep(i,n) printf(" %d", x[i]);
    printf("\n");
    fflush(stdout);
    return 0;
}
