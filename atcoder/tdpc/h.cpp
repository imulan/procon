#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;
typedef pair<int,pi> P;

const int INF=1010101010;

int dp[10001][51];
int X[10001][51],Y[10001][51];

inline void move1()
{
    rep(i,10001)rep(j,51) X[i][j]=max(X[i][j], Y[i][j]);
    fill(Y[0],Y[10001],-INF);
}

inline void move2()
{
    rep(i,10001)rep(j,51) Y[i][j]=max(Y[i][j], dp[i][j]);
}

int main()
{
    int N,W,C;
    scanf(" %d %d %d", &N, &W, &C);

    vector<P> t(N);
    rep(i,N) scanf(" %d %d %d", &t[i].se.fi, &t[i].se.se, &t[i].fi);
    sort(all(t));

    fill(X[0],X[10001],-INF);
    fill(Y[0],Y[10001],-INF);
    X[0][0]=0;

    int ans=0;
    rep(i,N)
    {
        int w=t[i].se.fi, v=t[i].se.se;
        for(int j=w; j<=W; ++j)for(int k=1; k<=C; ++k)
        {
            dp[j][k]=max(X[j-w][k-1], Y[j-w][k])+v;
            ans = max(ans,dp[j][k]);
        }

        move2();
        if(i+1<N && t[i].fi<t[i+1].fi) move1();
    }
    printf("%d\n", ans);
    return 0;
}
