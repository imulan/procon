#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int main()
{
    int h,w;
    cin >>h >>w;

    vector<string> f(h);
    rep(i,h) cin >>f[i];

    int ans[100][100];
    fill(ans[0],ans[100],-1);

    rep(i,h)rep(j,w) if(f[i][j]=='c') ans[i][j]=0;

    rep(j,w)rep(i,h)
    {
        if(ans[i][j]==0)
        {
            int ct=1;
            for(int x=j+1; x<w; ++x)
            {
                if(ans[i][x]==-1) ans[i][x]=ct;
                else ans[i][x]=min(ans[i][x],ct);

                ++ct;
            }
        }
    }

    rep(i,h)
    {
        rep(j,w)
        {
            if(j) printf(" ");
            printf("%d", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}
