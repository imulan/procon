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
    int n,k;
    while(scanf(" %d %d", &n, &k),n)
    {
        vector<int> c(n);
        rep(i,n) scanf(" %d", &c[i]);

        int t=0;
        for(int i=0; i+k-1<n; ++i)
        {
            int tmp=1;
            rep(j,k) tmp*=c[i+j];
            t=max(t,tmp);
        }

        int ans=-1;
        rep(x,n)rep(y,x)
        {
            swap(c[x],c[y]);

            int m=0;
            for(int i=0; i+k-1<n; ++i)
            {
                int tmp=1;
                rep(j,k) tmp*=c[i+j];
                m=max(m,tmp);
            }
            ans=max(ans,m-t);

            swap(c[x],c[y]);
        }

        if(ans<0) printf("NO GAME\n");
        else printf("%d\n", ans);
    }
    return 0;
}
