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
    int n,r[100][100];
    scanf(" %d", &n);
    rep(i,n)rep(j,n) scanf(" %d", &r[i][j]);

    int max_win=0,ans=-1;
    rep(i,n)
    {
        int ct=0;
        rep(j,n)if(r[i][j]==1) ++ct;
        rep(j,n)if(r[j][i]==2) ++ct;

        if(max_win<ct)
        {
            max_win=ct;
            ans=i;
        }
    }

    printf("%d\n", ans+1);
    return 0;
}
