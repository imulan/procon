#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(int)n; ++i)
#define all(x) (x).begin() (x).end()

const ll INF = 1000000000000001LL;

int h,w;
string a[50];

ll mul(ll x, ll y)
{
    if(x==0 || y==0) return 0;
    // x*y>INF
    if(x > INF/y) return INF;
    else return x*y;
}

ll COST[51][51][51][51];
ll cost(int ly, int lx, int ry, int rx)
{
    // printf("CALL %d %d %d %d\n", ly,lx,ry,rx);

    if(COST[ly][lx][ry][rx]>=0) return COST[ly][lx][ry][rx];

    int val = a[ry][rx]-'0';
    if(ly==ry && lx==rx) return val;

    ll ret = 0;
    if(ry>0 && a[ry-1][rx]=='*')
    {
        if(rx>0) ret = max(ret, mul(val,cost(ly,lx,ry-1,rx-1)));
        if(ry-2>=0) ret = max(ret, mul(val,cost(ly,lx,ry-2,rx)));
    }

    if(rx>0 && a[ry][rx-1]=='*')
    {
        if(ry>0) ret = max(ret, mul(val,cost(ly,lx,ry-1,rx-1)));
        if(rx-2>=0) ret = max(ret, mul(val,cost(ly,lx,ry,rx-2)));
    }

    return COST[ly][lx][ry][rx] = ret;
}

ll dp[51][51];

int main()
{
    cin >>h >>w;
    rep(i,h) cin>>a[i];

    memset(COST,-1,sizeof(COST));
    // printf(" c %lld\n", cost(0,0,2,2));

    fill(dp[0], dp[51], -100);
    dp[0][0] = 0;
    rep(i,h)rep(j,w) if((i+j)%2==0){
        auto upd = [&](int x, int y){
            if(x<h && y<w){
                dp[x][y] = max(dp[x][y], dp[i][j]+a[i][j]-'0');
            }
        };
        if(i+1<h && a[i+1][j]=='+'){
            upd(i+2, j);
            upd(i+1,j+1);
        }
        if(j+1<w && a[i][j+1]=='+'){
            upd(i, j+2);
            upd(i+1, j+1);
        }

        for(int ii=i; ii<h; ii++){
            for(int jj=j; jj<w; jj++)if(!(i==ii&&j==jj) && (ii+jj)%2==0){

                dp[ii][jj] = max(dp[ii][jj], dp[i][j] + cost(i,j,ii,jj) - (a[ii][jj]-'0'));
                if(dp[ii][jj] > INF){
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }

    // rep(i,h){
    //     rep(j,w) cout << dp[i][j] << ",";
    //     cout << endl;
    // }

    dp[h-1][w-1] += a[h-1][w-1]-'0';

    if(dp[h-1][w-1] >= INF) cout << -1 << endl;
    else cout << dp[h-1][w-1] << endl;

}
