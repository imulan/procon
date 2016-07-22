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
typedef pair<pi,int> P;
typedef vector<int> vi;

const int INF=87654321;

int h,w;
int dist[500][500][2];

vector<vi> dx{ {1,2,2,1,-1,-2,-2,-1},
               {1,1,-1,-1} };
vector<vi> dy{ {-2,-1,1,2,2,1,-1,-2},
               {-1,1,1,-1} };

inline bool in(int y, int x)
{
    return (0<=x&&x<w && 0<=y&&y<h);
}

int main()
{
    cin >>h >>w;
    vector<string> s(h);
    rep(i,h) cin >>s[i];

    pi start,goal;
    rep(i,h)rep(j,w)
    {
        if(s[i][j]=='S') start=pi(i,j);
        if(s[i][j]=='G') goal=pi(i,j);
    }

    rep(i,h)rep(j,w)rep(k,2) dist[i][j][k]=INF;
    dist[start.fi][start.se][0]=0;

    queue<P> que;
    que.push(P(start,0));

    while(!que.empty())
    {
        P p=que.front();
        que.pop();

        pi now=p.fi;
        int st=p.se;
        rep(i,dx[st].size())
        {
            int nx=now.se+dx[st][i];
            int ny=now.fi+dy[st][i];
            if(in(ny,nx))
            {
                int nst=st;
                if(s[ny][nx]=='R') nst=!nst;

                if(dist[ny][nx][nst]>dist[now.fi][now.se][st]+1)
                {
                    dist[ny][nx][nst]=dist[now.fi][now.se][st]+1;
                    que.push(P(pi(ny,nx),nst));
                }
            }
        }
    }

    int ans=min(dist[goal.fi][goal.se][0],dist[goal.fi][goal.se][1]);
    if(ans==INF) ans=-1;
    cout << ans << endl;
    return 0;
}
