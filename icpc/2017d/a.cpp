#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)

int main()
{
    int n,m;
    while(cin >>n >>m,n)
    {
        vector<int> a(n);
        rep(i,n) cin >>a[i];

        int ans = 0;
        rep(i,n)rep(j,i)
        {
            int v = a[i]+a[j];
            if(v<=m) ans = max(ans,v);
        }

        if(ans == 0) printf("NONE\n");
        else printf("%d\n", ans);
    }
    return 0;
}
