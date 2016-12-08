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

    int a[200]={};
    rep(i,n) scanf(" %d", &a[i]);

    int ans=1234567;
    for(int i=1; i<=100; ++i)
    {
        int B=2*i-1;

        int b[200]={};
        rep(j,i) b[j]=j+1;
        for(int j=i; j<B; ++j) b[j]=(i-1)-(j-i);

        int p=0, m=0;
        rep(j,max(n,B))
        {
            int diff = a[j]-b[j];
            if(diff>0) p+=diff;
            else m+=-diff;
        }

        // printf("p,m %d %d\n", p,m);
        if(p>=m) ans=min(ans,p);
    }

    printf("%d\n", ans);
    return 0;
}
