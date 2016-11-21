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

int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

string s[1000];

ll ct[5];
vector<pi> p[5];

const int INF=123456789;
int d[5][1000][1000];

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);
    int w,h;
    while(cin >>w >>h,w)
    {
        rep(i,h) cin>>s[i];

        rep(i,5)
        {
            ct[i]=0;
            p[i].clear();
        }

        pi start,goal;
        rep(i,h)rep(j,w)
        {
            if(s[i][j]=='S') start=pi(i,j);
            else if(s[i][j]=='G') goal=pi(i,j);
            else if(s[i][j]!='.')
            {
                int num=s[i][j]-'1';
                ++ct[num];
                p[num].pb(pi(i,j));
            }
        }

        int ans=INF;
        int type=-1;

        #define IN(x,y) (0<=x && x<w && 0<=y && y<h)
        // first-select
        rep(i,5)
        {
            int nst,nxt;
            fill(d[0][0],d[5][0],INF);

            // start to (i+1)%5
            d[0][start.fi][start.se]=0;
            nxt=(i+1)%5;
            if(ct[nxt]>w*h)
            {
                // BFS
                queue<pi> que;
                que.push(start);
                while(!que.empty())
                {
                    pi now=que.front(); que.pop();
                    rep(dir,4)
                    {
                        int nx=now.se+dx[dir], ny=now.fi+dy[dir];
                        if(IN(nx,ny) && d[0][ny][nx]>d[0][now.fi][now.se]+1)
                        {
                            d[0][ny][nx]=d[0][now.fi][now.se]+1;
                            que.push(pi(ny,nx));
                        }
                    }
                }
            }
            else
            {
                for(const auto &pt:p[nxt]) d[0][pt.fi][pt.se]=abs(start.fi-pt.fi)+abs(start.se-pt.se);
            }

            // (i+j)%5 to (i+j%1)%5
            for(int j=1; j<=3; ++j)
            {
                nst=(i+j)%5;
                nxt=(i+j+1)%5;
                if(ct[nst]*ct[nxt]>w*h)
                {
                    // BFS
                    queue<pi> que;
                    for(const auto &pt:p[nst])
                    {
                        que.push(pt);
                        d[j][pt.fi][pt.se]=d[j-1][pt.fi][pt.se];
                    }
                    while(!que.empty())
                    {
                        pi now=que.front(); que.pop();
                        rep(dir,4)
                        {
                            int nx=now.se+dx[dir], ny=now.fi+dy[dir];
                            if(IN(nx,ny) && d[j][ny][nx]>d[j][now.fi][now.se]+1)
                            {
                                d[j][ny][nx]=d[j][now.fi][now.se]+1;
                                que.push(pi(ny,nx));
                            }
                        }
                    }
                }
                else
                {
                    for(const auto &pt:p[nst])for(const auto &qt:p[nxt])
                    {
                        d[j][qt.fi][qt.se] = min(d[j][qt.fi][qt.se], d[j-1][pt.fi][pt.se]+abs(pt.fi-qt.fi)+abs(pt.se-qt.se));
                    }
                }
            }

            // (i+4)%5 to goal
            nst=(i+4)%5;
            if(ct[nst]>w*h)
            {
                // BFS
                queue<pi> que;
                for(const auto &pt:p[nst])
                {
                    que.push(pt);
                    d[4][pt.fi][pt.se]=d[3][pt.fi][pt.se];
                    while(!que.empty())
                    {
                        pi now=que.front(); que.pop();
                        rep(dir,4)
                        {
                            int nx=now.se+dx[dir], ny=now.fi+dy[dir];
                            if(IN(nx,ny) && d[4][ny][nx]>d[4][now.fi][now.se]+1)
                            {
                                d[4][ny][nx]=d[4][now.fi][now.se]+1;
                                que.push(pi(ny,nx));
                            }
                        }
                    }
                }
            }
            else
            {
                for(const auto &pt:p[nst]) d[4][goal.fi][goal.se]=min(d[4][goal.fi][goal.se], d[3][pt.fi][pt.se]+abs(pt.fi-goal.fi)+abs(pt.se-goal.se));
            }

            if(d[4][goal.fi][goal.se]<ans)
            {
                ans=d[4][goal.fi][goal.se];
                type=i+1;
            }
        }

        if(ans==INF) printf("NA\n");
        else printf("%d %d\n", type, ans);
    }
    return 0;
}
