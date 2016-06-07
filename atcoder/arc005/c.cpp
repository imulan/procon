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

int h,w;

inline bool in(int y, int x)
{
    return (0<=y&&y<h && 0<=x && x<w);
}

int main()
{
    cin >>h >>w;
    vector<string> c(h);
    rep(i,h) cin >>c[i];

    pi start,goal;
    rep(i,h)rep(j,w)
    {
        if(c[i][j]=='s')
        {
            start.fi=i;
            start.se=j;
        }
        if(c[i][j]=='g')
        {
            goal.fi=i;
            goal.se=j;
        }
    }

    int vs[500][500]={0};
    int vg[500][500]={0};

    int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

    queue<pi> que;

    //startから壁を壊さずに訪れられる場所
    que.push(start);
    vs[start.fi][start.se]=1;
    while(!que.empty())
    {
        pi now=que.front();
        que.pop();
        rep(i,4)
        {
            int ny=now.fi+dy[i], nx=now.se+dx[i];
            if(in(ny,nx) && !vs[ny][nx] && c[ny][nx]!='#')
            {
                vs[ny][nx]=1;
                que.push(pi(ny,nx));
            }
        }
    }

    //goalから壁を壊さずに訪れられる場所
    que.push(goal);
    vg[goal.fi][goal.se]=1;
    while(!que.empty())
    {
        pi now=que.front();
        que.pop();
        rep(i,4)
        {
            int ny=now.fi+dy[i], nx=now.se+dx[i];
            if(in(ny,nx) && !vg[ny][nx] && c[ny][nx]!='#')
            {
                vg[ny][nx]=1;
                que.push(pi(ny,nx));
            }
        }
    }

    int vs2[500][500]={0};
    int vg2[500][500]={0};

    //startから訪れられる場所に隣接している壁を壊してみる
    rep(i,h)rep(j,w) vs2[i][j]=vs[i][j];

    rep(i,h)rep(j,w)
    {
        if(vs[i][j])
        {
            rep(k,4)
            {
                int ny=i+dy[k], nx=j+dx[k];
                if(in(ny,nx) && c[ny][nx]=='#' && !vs2[ny][nx])
                {
                    vs2[ny][nx]=1;
                    que.push(pi(ny,nx));
                    while(!que.empty())
                    {
                        pi now=que.front();
                        que.pop();
                        rep(l,4)
                        {
                            int nny=now.fi+dy[l], nnx=now.se+dx[l];
                            if(in(nny,nnx) && !vs2[nny][nnx] && c[nny][nnx]!='#')
                            {
                                vs2[nny][nnx]=1;
                                que.push(pi(nny,nnx));
                            }
                        }
                    }


                }
            }
        }
    }

    //goalから訪れられる場所に隣接している壁を壊してみる
    rep(i,h)rep(j,w) vg2[i][j]=vg[i][j];

    rep(i,h)rep(j,w)
    {
        if(vg[i][j])
        {
            rep(k,4)
            {
                int ny=i+dy[k], nx=j+dx[k];
                if(in(ny,nx) && c[ny][nx]=='#' && !vg2[ny][nx])
                {
                    vg2[ny][nx]=1;
                    que.push(pi(ny,nx));
                    while(!que.empty())
                    {
                        pi now=que.front();
                        que.pop();
                        rep(l,4)
                        {
                            int nny=now.fi+dy[l], nnx=now.se+dx[l];
                            if(in(nny,nnx) && !vg2[nny][nnx] && c[nny][nnx]!='#')
                            {
                                vg2[nny][nnx]=1;
                                que.push(pi(nny,nnx));
                            }
                        }
                    }


                }
            }
        }
    }

    /*
    rep(i,h)
    {
        rep(j,w) printf("%d",vs2[i][j]);
        printf("\n");
    }
    printf("\n");
    rep(i,h)
    {
        rep(j,w) printf("%d",vg2[i][j]);
        printf("\n");
    }
    */

    bool ok=false;
    rep(i,h)rep(j,w)
    {
        if(!vs2[i][j]) continue;

        rep(k,4)
        {
            int ny=i+dy[k], nx=j+dx[k];
            if(in(ny,nx) && vg2[ny][nx]) ok=true;
        }

        if(ok) break;
    }

    string ans="NO";
    if(ok) ans="YES";
    cout << ans << endl;

    return 0;
}
