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

const int INF=123456789;
const int N=100000;
set<int> X[N+1],Y[N+1];

vector<int> G[N];
vector<vector<int>> connected;

int main()
{
    int n,w,h;
    scanf(" %d %d %d", &n, &w, &h);

    // point
    vector<pi> p(n);
    // point -> id
    map<pi,int> f;
    rep(i,n)
    {
        int x,y;
        scanf(" %d %d", &x, &y);
        X[x].insert(y);
        Y[y].insert(x);

        p[i] = pi(x,y);
        f[p[i]] = i;
    }

    // 隣接している位置に辺を張る
    rep(i,n)
    {
        int x=p[i].fi, y=p[i].se;

        // 下
        auto itrx = X[x].lower_bound(y);
        if(itrx != X[x].begin())
        {
            auto up = itrx;
            --up;
            int idx = f[pi(x,*up)];
            G[i].pb(idx);
        }

        // 上
        ++itrx;
        if(itrx != X[x].end())
        {
            int idx = f[pi(x,*itrx)];
            G[i].pb(idx);
        }

        // 左
        auto itry = Y[y].lower_bound(x);
        if(itry != Y[y].begin())
        {
            auto lf = itry;
            --lf;
            int idx = f[pi(*lf,y)];
            G[i].pb(idx);
        }

        // 右
        ++itry;
        if(itry != Y[y].end())
        {
            int idx = f[pi(*itry,y)];
            G[i].pb(idx);
        }

    }

    // 連結要素を探す
    vector<bool> vis(n,false);
    rep(i,n)
    {
        if(vis[i]) continue;

        vector<int> con;
        queue<int> que;

        que.push(i);
        con.pb(i);
        vis[i]=true;
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
                    con.pb(nx);
                    que.push(nx);
                }
            }
        }

        connected.pb(con);
    }

    int ans=INF;

    if(connected.size()==1) ans=n-1;
    else
    {
        // 上下左右に寄せる場合を考慮
        vector<int> W({1,w}), H({1,h});
        for(auto &x:W)
        {
            int tmp=0;
            rep(i,connected.size())
            {
                int add=connected[i].size()+2;
                rep(j,connected[i].size())
                {
                    int idx = connected[i][j];
                    if(p[idx].fi==x)
                    {
                        --add;
                        break;
                    }
                }
                tmp+=add-1;
            }
            ans=min(ans,tmp-1);
        }
        for(auto &y:H)
        {
            int tmp=0;
            rep(i,connected.size())
            {
                int add=connected[i].size()+2;
                rep(j,connected[i].size())
                {
                    int idx = connected[i][j];
                    if(p[idx].se==y)
                    {
                        --add;
                        break;
                    }
                }
                tmp+=add-1;
            }
            ans=min(ans,tmp-1);
        }
    }

    printf("%d\n", ans);
    return 0;
}
