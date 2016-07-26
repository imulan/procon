#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define x first
#define y second

typedef pair<int,int> pi;

int h,w;
int d[3000][3000];

//8近傍
int dx[8]={0,1,1,1,0,-1,-1,-1}, dy[8]={-1,-1,0,1,1,1,0,-1};

const int INF=12345678;

inline bool in(int x, int y)
{
    return (0<=x&&x<w && 0<=y&&y<h);
}

int main()
{
    cin >>h >>w;
    vector<string> s(h);
    rep(i,h) cin >>s[i];

    fill(d[0],d[3000],INF);

    //まず海からの距離が1のところを探す
    rep(i,h)rep(j,w)
    {
        //そこが海なら
        if(s[i][j]=='.')
        {
            d[i][j]=0;
            //8近傍にある陸の距離は1
            rep(k,8)
            {
                int nx=j+dx[k], ny=i+dy[k];
                if(in(nx,ny) && s[ny][nx]=='#') d[ny][nx]=1;
            }
        }
    }

    //外側は全て海なので，端にある陸も海との距離は1
    rep(i,h)
    {
        if(s[i][0]=='#') d[i][0]=1;
        if(s[i][w-1]=='#') d[i][w-1]=1;
    }
    rep(i,w)
    {
        if(s[0][i]=='#') d[0][i]=1;
        if(s[h-1][i]=='#') d[h-1][i]=1;
    }

    queue<pi> que;
    rep(i,h)rep(j,w) if(d[i][j]==1) que.push(pi(j,i));

    while(!que.empty())
    {
        pi now=que.front();
        que.pop();
        rep(i,8)
        {
            int nx=now.x+dx[i], ny=now.y+dy[i];
            if(in(nx,ny) && d[ny][nx]>d[now.y][now.x]+1)
            {
                d[ny][nx]=d[now.y][now.x]+1;
                que.push(pi(nx,ny));
            }
        }
    }

    int ans=0;
    rep(i,h)rep(j,w) ans=max(ans,d[i][j]);
    cout << ans << endl;
    return 0;
}
