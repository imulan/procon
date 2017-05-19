#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int n;
string name[40];
vector<string> neighbor[40];
map<string,int> name2id;
int a[40],b[40],c[40];
int G[40][40];

const int N=1<<20;
int dp[N];
int NG[40],OK[40];

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);

    while(cin >>n,n)
    {
        // initialize
        name2id.clear();
        rep(i,40) neighbor[i].clear();
        memset(G,0,sizeof(G));
        memset(dp,0,sizeof(dp));
        memset(NG,0,sizeof(NG));
        memset(OK,0,sizeof(OK));

        // input
        rep(i,n)
        {
            cin >>name[i] >>b[i] >>c[i];
            neighbor[i].resize(c[i]);
            rep(j,c[i]) cin >>neighbor[i][j];

            a[i] = i;
            name2id[name[i]] = i;
        }

        rep(i,n)rep(j,c[i]) G[i][name2id[neighbor[i][j]]] = 1;

        int X=n/2, Y=n-X;

        // make NG mask
        rep(i,X)rep(j,X)if(G[i][j]) NG[i] |= 1<<j;
        rep(i,Y)rep(j,Y)if(G[X+i][X+j]) NG[X+i] |= 1<<j;

        // make OK mask
        rep(i,X)rep(j,Y)if(G[i][X+j]==0) OK[i] |= 1<<j;

        // 実際にこの頂点を選ぶ
        rep(mask,1<<Y)
        {
            bool ok=true;
            int sum=0;
            rep(i,Y)if(mask>>i&1)
            {
                ok &= ((NG[X+i]&mask) == 0);
                sum += b[X+i];
            }

            if(ok) dp[mask] = sum;
        }

        rep(mask,1<<Y)rep(i,Y)if(!(mask>>i&1))
        {
            int nmask = mask|(1<<i);
            dp[nmask] = max(dp[nmask],dp[mask]);
        }

        int ans=0;
        // 実際にこの頂点を選ぶ
        for(int mask=1; mask<(1<<X); mask+=2)
        {
            bool ok=true;
            int val = 0, t = (1<<Y)-1;
            rep(i,X)if(mask>>i&1)
            {
                ok &= ((NG[i]&mask) == 0);
                val += b[i];
                t &= OK[i];
            }
            if(!ok) continue;

            ans = max(ans, val+dp[t]);
        }

        cout << ans << endl;
    }
    return 0;
}
