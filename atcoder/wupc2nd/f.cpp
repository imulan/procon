#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

//現在位置(x,y),now文字目まで完了,
struct state{ int x,y,now,dir; };

const int INF=12345678;
int d[100][100][100][4];

//上,右,下,左
int dx[4]={0,1,0,-1}, dy[4]={-1,0,1,0};

int n,m;

inline bool in(int x, int y)
{
    return (0<=x && x<m && 0<=y && y<n);
}

int main()
{
    int L;
    string s;
    cin >>n >>m >>L >>s;

    vector<string> c(n);
    rep(i,n) cin >>c[i];

    rep(i,100)rep(j,100)rep(k,100)rep(l,4) d[i][j][k][l]=INF;

    rep(y,n)rep(x,m)rep(dir,4)
    {
        for(int a=1; a<=100; ++a)
        {
            int nx=x+a*dx[dir], ny=y+a*dy[dir];
            if(in(nx,ny))
            {
                if(c[ny][nx]==s[0])
                {
                    d[ny][nx][0][dir] = min(d[ny][nx][0][dir], a);
                    break;
                }
            }
            else break;
        }
    }

    queue<state> que;
    rep(y,n)rep(x,m)rep(dir,4)
    {
        if(d[y][x][0][dir]<INF) que.push(state{x,y,0,dir});
    }

    while(!que.empty())
    {
        state st=que.front();
        que.pop();

        if(st.now==L-1) continue;

        rep(dir,4)
        {
            if(dir==st.dir) continue;
            for(int a=1; a<=100; ++a)
            {
                int nx=st.x+a*dx[dir], ny=st.y+a*dy[dir];
                if(in(nx,ny))
                {
                    if(c[ny][nx]==s[st.now+1])
                    {
                        if(d[ny][nx][st.now+1][dir] > d[st.y][st.x][st.now][st.dir]+a)
                        {
                            d[ny][nx][st.now+1][dir] = d[st.y][st.x][st.now][st.dir]+a;
                            que.push(state{nx,ny,st.now+1,dir});
                        }

                        break;
                    }
                }
                else break;
            }
        }
    }

    int ans=INF;
    rep(y,n)rep(x,m)
    {
        if(c[y][x]==s[L-1])
        {
            rep(dir,4) ans=min(ans,d[y][x][L-1][dir]);
        }
    }
    if(ans==INF) ans=-1;
    cout << ans << endl;
    return 0;
}
