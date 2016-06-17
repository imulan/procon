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

typedef pair<int,int> pi;

int dp[5001][5001]={0};

int main()
{
    int n,m;
    cin >>n >>m;

    vector<int> x(n),y(n);
    vector<pi> p(n);

    //the number of points
    map<pi,int> s;

    rep(i,n)
    {
        scanf(" %d %d", &x[i], &y[i]);

        p[i]=pi(x[i],y[i]);
        if(s.find(p[i])==s.end()) s[p[i]]=1;
        else ++s[p[i]];
    }

    //eliminate same value
    sort(all(x));
    sort(all(y));
    x.erase( unique(all(x)), x.end());
    y.erase( unique(all(y)), y.end());

    int X=x.size();
    int Y=y.size();

    //make DPtable
    rep(i,n)
    {
        int idx=lower_bound(all(x),p[i].fi)-x.begin()+1;
        int idy=lower_bound(all(y),p[i].se)-y.begin()+1;
        ++dp[idy][idx];
    }
    /*
    for(int i=Y; i>=0; --i)
    {
        rep(j,X+1) printf(" %d", dp[i][j]);
        printf("\n");
    }
    */

    for(int i=1; i<=Y; ++i)for(int j=1; j<=X; ++j)
    {
        dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
    }

    /*
    for(int i=Y; i>=0; --i)
    {
        rep(j,X+1) printf(" %d", dp[i][j]);
        printf("\n");
    }
    */

    rep(Q,m)
    {
        int x1,y1,x2,y2;
        scanf(" %d %d %d %d",&x1,&y1,&x2,&y2);

        int rx=upper_bound(all(x),x2)-x.begin();
        int ry=upper_bound(all(y),y2)-y.begin();
        int lx=lower_bound(all(x),x1)-x.begin();
        int ly=lower_bound(all(y),y1)-y.begin();

        //printf("%d,%d, %d,%d\n", lx,ly,rx,ry);
        //printf("%d - %d - %d + %d\n", dp[ry][rx],dp[ry][lx],dp[ly][rx],dp[ly][lx]);
        printf("%d\n", dp[ry][rx]-dp[ry][lx]-dp[ly][rx]+dp[ly][lx]);
    }

    return 0;
}
