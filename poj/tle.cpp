#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int n;
vector<string> s;
int T;

const int INF=12345678;
int dp[15][1<<15];
// i,jの順に繋ぐ時の共通部分列の長さ
int com[15][15];

bool canReach[15][1<<15];

void dfs(int l, int mask, string now, string &ans, vector<string> &t)
{
    if(mask==(1<<T)-1)
    {
        ans=min(ans,now);
        return;
    }

    rep(i,T)if(!(mask>>i&1))
    {
        int nxmask=mask|(1<<i);
        if(canReach[i][nxmask])
        {
            int add=t[i].size()-com[l][i];
            if(dp[l][mask]+add==dp[i][nxmask])
            {
                string nx=now+t[i].substr(com[l][i]);
                if(nx<ans) dfs(i,nxmask,nx,ans,t);
            }
        }
    }
}

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);

    int S;
    cin >>S;
    rep(sce,S)
    {
        cin >>n;
        s=vector<string>(n);
        rep(i,n) cin >>s[i];

        vector<bool> use(n,true);
        rep(i,n)rep(j,n)
        {
            if(i==j) continue;

            int I=s[i].size(), J=s[j].size();
            if(I>J) continue;
            rep(k,J-I+1) if(s[i]==s[j].substr(k,I)) use[i]=false;
        }

        vector<string> t;
        rep(i,n) if(use[i]) t.pb(s[i]);
        T=t.size();

        memset(com,0,sizeof(com));
        rep(i,T)rep(j,T)
        {
            if(i==j) continue;
            int I=t[i].size(), J=t[j].size();

            rep(k,min(I,J))
            {
                int len=k+1;
                if(t[i].substr(I-len)==t[j].substr(0,len)) com[i][j]=len;
            }
        }

        fill(dp[0],dp[15],INF);

        // 最初
        rep(i,T) dp[i][1<<i]=t[i].size();

        for(int mask=1; mask<(1<<T); ++mask)
        {
            rep(before,T)if(mask>>before&1)
            {
                rep(i,T)if(!(mask>>i&1))
                {
                    int add=t[i].size()-com[before][i];
                    dp[i][mask|(1<<i)] = min(dp[i][mask|(1<<i)],dp[before][mask]+add);
                }
            }
        }

        int min_len=INF;
        rep(i,T) min_len=min(min_len, dp[i][(1<<T)-1]);

        memset(canReach,0,sizeof(canReach));
        rep(i,T)if(dp[i][(1<<T)-1]==min_len)
        {
            canReach[i][(1<<T)-1]=true;
        }

        for(int mask=(1<<T)-1; mask>0; --mask)
        {
            rep(i,T)if(canReach[i][mask])
            {
                rep(j,T)
                {
                    int add=t[i].size()-com[j][i];
                    if(dp[j][mask & ~(1<<i)]+add == dp[i][mask]) canReach[j][mask & ~(1<<i)]=true;
                }
            }
        }

        string ans="Z";
        rep(i,T)
        {
            if(canReach[i][1<<i])
            {
                // printf("start %d\n", i);
                dfs(i,1<<i,t[i],ans,t);
            }
        }

        cout << "Scenario #" << sce+1 << ":\n";
        cout << ans << "\n";
    }
    return 0;
}
