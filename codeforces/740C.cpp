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
    int n,m;
    scanf(" %d %d", &n, &m);

    int ans=1234567;
    rep(i,m)
    {
        int l,r;
        scanf(" %d %d", &l, &r);
        ans = min(ans, r-l+1);
    }

    printf("%d\n", ans);
    rep(i,n)
    {
        if(i) printf(" ");
        printf("%d", i%ans);
    }
    printf("\n");

    return 0;
}
