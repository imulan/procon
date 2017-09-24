#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(int)n; ++i)
#define all(x) (x).begin() (x).end()

int n;
int A;
int a[14],h[14][3];

double dp[1<<13]={};
double aiko[1<<13][3]={};

double f(int now, int nxt, int win, int lose)
{
    double ret = 1.0;
    rep(i,n)if(now>>i&1)
    {
        if(nxt>>i&1) ret *= h[i][win]/100.0;
        else ret *= h[i][lose]/100.0;
    }

    return ret;
}

double dfs(int mask)
{
    if(mask==0) return 1;
    if(dp[mask]>=0) return dp[mask];

    vector<int> alive;
    rep(i,n)if(mask>>i&1) alive.push_back(i);

    int enemy_max = 0;
    for(int id:alive) enemy_max = max(enemy_max,a[id]);

    // あいこの時勝者になれる
    bool winner = (A>enemy_max);

    double ret = 0;
    // r,p,s
    rep(i,3)
    {
        double tmp = 0;

        int sub = mask;
        sub = (sub-1) & mask;
        while(sub!=mask)
        {
            double F = f(mask,sub,i,(i+2)%3);
            tmp += F*dfs(sub);

            sub = (sub-1) & mask;
        }

        if(winner) tmp += aiko[mask][i];

        ret = max(ret,tmp);
    }

    assert(ret <= 1.0000001);

    return dp[mask] = ret;
}

int main(){
    cin >>n;
    cin >>A;

    n--;
    rep(i,n)
    {
        cin >>a[i];
        rep(j,3) cin >>h[i][j];
    }

    rep(mask,1<<n)
    {
        rep(i,3)
        {
            aiko[mask][i]=0;

            int sub = mask;
            sub = (sub-1) & mask;

            double F = 0;
            while(sub!=mask)
            {
                F += f(mask,sub,i,(i+2)%3) + f(mask,sub,i,(i+1)%3);

                sub = (sub-1) & mask;
            }

            // printf("F %.10f\n", F);
            assert(F>=0 && F<=1.000001);
            aiko[mask][i] = 1.0 - F;
        }
    }
    fill(dp,dp+(1<<13),-1);
    printf("%.10f\n", dfs((1<<n)-1));

    return 0;
}
