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

int main()
{
    int n;
    while(cin >>n,n)
    {
        vector<int> x,y;

        vector<int> l(n),t(n),r(n),b(n);
        rep(i,n)
        {
            cin >>l[i] >>t[i] >>r[i] >>b[i];
            x.pb(l[i]);
            x.pb(r[i]);
            y.pb(t[i]);
            y.pb(b[i]);
        }

        sort(all(x));
        x.erase(unique(all(x)),x.end());
        sort(all(y));
        y.erase(unique(all(y)),y.end());

        int X=x.size(), Y=y.size();

        vector<double> cx,cy;
        cx.pb(x[0]-1);
        rep(i,X-1) cx.pb((x[i]+x[i+1])/2.0);
        cx.pb(x[X-1]+1);
        cy.pb(y[0]-1);
        rep(i,Y-1) cy.pb((y[i]+y[i+1])/2.0);
        cy.pb(y[Y-1]+1);

        int CX=cx.size(), CY=cy.size();
        vector<vector<bool>> vis(CY,vector<bool>(CX,false));

        int ans=0;
        #define IN(x,y) (0<=x && x<CX && 0<=y && y<CY)
        rep(i,CY)rep(j,CX)
        {
            if(vis[i][j]) continue;

            vis[i][j]=true;
            ++ans;
            queue<pi> que;
            que.push(pi(i,j));
            while(!que.empty())
            {
                pi now=que.front();
                que.pop();

                // 右
                if(now.se<CX-1)
                {
                    if(!vis[now.fi][now.se+1])
                    {
                        bool wall=false;
                        rep(k,n)
                        {
                            if(l[k]==x[now.se] || r[k]==x[now.se])
                            {
                                if(b[k]<cy[now.fi] && cy[now.fi]<t[k]) wall=true;
                            }
                        }
                        if(!wall)
                        {
                            vis[now.fi][now.se+1]=true;
                            que.push(pi(now.fi,now.se+1));
                        }
                    }
                }
                // 左
                if(now.se>0)
                {
                    if(!vis[now.fi][now.se-1])
                    {
                        bool wall=false;
                        rep(k,n)
                        {
                            if(l[k]==x[now.se-1] || r[k]==x[now.se-1])
                            {
                                if(b[k]<cy[now.fi] && cy[now.fi]<t[k]) wall=true;
                            }
                        }
                        if(!wall)
                        {
                            vis[now.fi][now.se-1]=true;
                            que.push(pi(now.fi,now.se-1));
                        }
                    }
                }
                // 上
                if(now.fi<CY-1)
                {
                    if(!vis[now.fi+1][now.se])
                    {
                        bool wall=false;
                        rep(k,n)
                        {
                            if(t[k]==y[now.fi] || b[k]==y[now.fi])
                            {
                                if(l[k]<cx[now.se] && cx[now.se]<r[k]) wall=true;
                            }
                        }
                        if(!wall)
                        {
                            vis[now.fi+1][now.se]=true;
                            que.push(pi(now.fi+1,now.se));
                        }
                    }
                }
                // 下
                if(now.fi>0)
                {
                    if(!vis[now.fi-1][now.se])
                    {
                        bool wall=false;
                        rep(k,n)
                        {
                            if(t[k]==y[now.fi-1] || b[k]==y[now.fi-1])
                            {
                                if(l[k]<cx[now.se] && cx[now.se]<r[k]) wall=true;
                            }
                        }
                        if(!wall)
                        {
                            vis[now.fi-1][now.se]=true;
                            que.push(pi(now.fi-1,now.se));
                        }
                    }
                }
            }

        }
        cout << ans << endl;
    }
    return 0;
}
