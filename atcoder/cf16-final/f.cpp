#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll mod=1e9+7;

const int N=300;
// i日目,訪れた頂点数j,町1と強連結成分をなす町の個数k
ll dp[N+1][N+1][N+1]={0};

int main()
{
    int n,m;
    cin >>n >>m;

    dp[0][1][1]=1;
    rep(i,m)for(int j=1; j<=N; ++j)for(int k=1; k<=j; ++k)
    {
        // 町1との強連結成分内の町に行く
        (dp[i+1][j][j]+=dp[i][j][k]*k)%=mod;
        // 町1との強連結成分外の訪問済みの町に行く
        (dp[i+1][j][k]+=dp[i][j][k]*(j-k))%=mod;
        // 未訪問の町に行く
        if(j<N) (dp[i+1][j+1][k]+=dp[i][j][k]*(n-j))%=mod;
    }

    cout << dp[m][n][n] << endl;
    return 0;
}
