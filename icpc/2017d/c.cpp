#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define pb(a) push_back((a))

int main()
{
    int d,w;
    while(cin >>d >>w,d)
    {
        int e[10][10]={};
        rep(i,d)rep(j,w) cin >>e[i][j];

        int ans = 0;
        rep(lx,w)for(int rx=lx+2; rx<w; ++rx)rep(ly,d)for(int ry=ly+2; ry<d; ++ry)
        {
            int out = 191919, in = 0;
            for(int i=ly; i<=ry; ++i)for(int j=lx; j<=rx; ++j)
            {
                if(i==ly || i==ry || j==lx || j==rx) out = min(out,e[i][j]);
                else in = max(in,e[i][j]);
            }

            if(in>=out) continue;

            int t = 0;
            for(int i=ly+1; i<ry; ++i)for(int j=lx+1; j<rx; ++j)
            {
                t += out-e[i][j];
            }

            ans = max(ans,t);
        }
        cout << ans << endl;
    }
    return 0;
}
