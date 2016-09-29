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
    cin >>n;
    vector<string> s(n);
    rep(i,n) cin >>s[i];

    int ans=0;

    // center
    rep(i,n)rep(j,n)
    {
        if(s[i][j]=='*') continue;

        int maxr = min({i, j, n-1-i, n-1-j});
        vector<bool> ok(maxr*maxr+1, true);

        rep(y,n)rep(x,n)
        {
            int dist2 = (i-y)*(i-y) + (j-x)*(j-x);
            if(s[y][x] == '*' && dist2<=maxr*maxr) ok[dist2]=false;
        }

        int t=0;
        while(t<=maxr*maxr && ok[t]) t++;
        t--;

        int r=0;
        while(r*r<=t) r++;
        r--;

        // printf("%d,%d = %d : t= %d\n", i,j,r ,t );

        ans=max(ans,r);
    }

    cout << ans << endl;
    return 0;
}
