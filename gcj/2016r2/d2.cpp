#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int INF=12345678;
int dp[1<<17][26][26];

int main()
{
    int CASE;
    cin >>CASE;
    rep(T,CASE)
    {
        int ans=0, edge=0;

        //input
        int n;
        cin >>n;
        vector<string> s(n);
        rep(i,n) cin >>s[i];

        //グラフ構成
        vector<int> G[50];
        rep(i,n)rep(j,n)
        {
            if(s[i][j]=='1')
            {
                G[i].pb(n+j);
                G[n+j].pb(i);
                ++edge;
            }
        }

        //independent
        int lc=0, rc=0;
        //connected component
        int cc=0;
        int l[17], r[17];

        //連結成分をBFSで探索
        vector<bool> vis(2*n, false);
        rep(i,2*n)
        {
            if(vis[i]) continue;
            int L=0, R=0;

            queue<int> que;
            que.push(i);
            vis[i]=true;
            if(i<n) ++L;
            else ++R;
            while(!que.empty())
            {
                int v=que.front();
                que.pop();
                rep(j,G[v].size())
                {
                    int nx=G[v][j];
                    if(!vis[nx])
                    {
                        vis[nx]=true;
                        que.push(nx);
                        if(nx<n) ++L;
                        else ++R;
                    }
                }
            }

            if(L==1 && R==0) ++lc;
            else if(L==0 && R==1) ++rc;
            else if(L==R) ans+=L*R;
            else
            {
                l[cc]=L;
                r[cc]=R;
                ++cc;
            }
        }

        //DP
        rep(mask,1<<cc)rep(i,lc+1)rep(j,rc+1) dp[mask][i][j]=INF;
        dp[0][0][0]=0;
        //もらう感じで
        rep(mask,1<<cc)rep(i,lc+1)rep(j,rc+1)
        {
            //独立成分同士を繋ぐ
            if(i>0 && j>0) dp[mask][i][j] = min(dp[mask][i][j], dp[mask][i-1][j-1]+1);

            //部分集合を列挙
            int sub=mask;
            while(sub>0)
            {
                int Lnum=0,Rnum=0;
                rep(k,cc)
                {
                    if(sub&(1<<k))
                    {
                        Lnum += l[k];
                        Rnum += r[k];
                    }
                }

                //両者の個数を揃える
                int ti=i, tj=j;
                if(Lnum < Rnum) ti -= Rnum-Lnum;
                if(Lnum > Rnum) tj -= Lnum-Rnum;

                int cost=max(Lnum, Rnum);
                //更新
                if(ti>=0 && tj>=0) dp[mask][i][j]=min(dp[mask][i][j], dp[sub^mask][ti][tj]+cost*cost);

                sub = (sub-1)&mask;
            }
        }

        //output
        printf("Case #%d: %d\n", T+1, ans+dp[(1<<cc)-1][lc][rc]-edge);
    }
    return 0;
}
