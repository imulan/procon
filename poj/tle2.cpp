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

typedef pair<int,int> pi;

int n;
vector<string> s,t;
int T;

const int INF=12345678;
int dp[15][1<<15];
pi par[15][1<<15];

// i,jの順に繋ぐ時の共通部分列の長さ
int com[15][15];

string make_string(int now, int mask)
{
    pi p=par[now][mask];
    if(p.fi==-1) return t[now];
    return make_string(p.fi,p.se)+t[now].substr(com[p.fi][now]);
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

        sort(all(s));
        s.erase(unique(all(s)),s.end());
        n=s.size();

        vector<bool> use(n,true);
        rep(i,n)rep(j,n)
        {
            if(i==j) continue;

            int I=s[i].size(), J=s[j].size();
            if(I>J) continue;
            rep(k,J-I+1) if(s[i]==s[j].substr(k,I)) use[i]=false;
        }

        t.clear();
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
        rep(i,T)
        {
            dp[i][1<<i]=t[i].size();
            par[i][1<<i]=pi(-1,-1);
        }

        for(int mask=1; mask<(1<<T); ++mask)
        {
            rep(before,T)if(mask>>before&1)
            {
                rep(i,T)if(!(mask>>i&1))
                {
                    int add=t[i].size()-com[before][i];
                    if(dp[i][mask+(1<<i)]>dp[before][mask]+add)
                    {
                        dp[i][mask+(1<<i)]=dp[before][mask]+add;
                        par[i][mask+(1<<i)]=pi(before,mask);
                    }
                    else if(dp[i][mask+(1<<i)]==dp[before][mask]+add)
                    {
                        string old_s=make_string(i,mask+(1<<i));
                        string new_s=make_string(before,mask)+t[i].substr(com[before][i]);

                        if(new_s<old_s) par[i][mask+(1<<i)] = pi(before,mask);
                    }
                }
            }
        }


        int min_len=INF;
        rep(i,T) min_len=min(min_len, dp[i][(1<<T)-1]);

        string ans="#";
        rep(i,T)
        {
            if(dp[i][(1<<T)-1]==min_len)
            {
                if(ans=="#") ans=make_string(i,(1<<T)-1);
                else ans=min(ans,make_string(i,(1<<T)-1));
            }
        }

        cout << "Scenario #" << sce+1 << '\n';
        cout << ans << '\n';
    }
    return 0;
}
