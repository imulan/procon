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

const int INF=12345678;

int cost[100][100];
int L[100][100];

int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

int main()
{
    int n,v,sx,sy,gx,gy;
    cin >>n >>v >>sx >>sy >>gx >>gy;
    --sx;
    --sy;
    --gx;
    --gy;
    rep(i,n)rep(j,n) scanf(" %d", &L[i][j]);

    fill(cost[0],cost[100],INF);
    cost[sy][sx]=0;

    int ans=-1;

    queue<P> que;
    que.push(P(pi(sx,sy),0));
    while(!que.empty())
    {
        P p=que.front();
        que.pop();

        pi now=p.fi;
        //printf("%d,%d : %d\n", now.fi,now.se,p.se);

        //コストv以下でゴールに辿り着いたのでおわり
        if(now==pi(gx,gy))
        {
            ans=p.se;
            break;
        }

        //4近傍
        rep(i,4)
        {
            int nx=now.fi+dx[i], ny=now.se+dy[i];
            if(0<=nx&&nx<n && 0<=ny&&ny<n)
            {
                if(cost[now.se][now.fi]+L[ny][nx]<v && cost[ny][nx]>cost[now.se][now.fi]+L[ny][nx])
                {
                    cost[ny][nx]=cost[now.se][now.fi]+L[ny][nx];
                    que.push(P(pi(nx,ny),p.se+1));
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
