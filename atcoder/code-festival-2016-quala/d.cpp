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

const int N=200000;
const ll INF=1234567890123456LL;

struct edge{int to,cost;};
vector<edge> G[N];
ll val[N];

int main()
{
    int R,C;
    scanf(" %d %d", &R, &C);
    int n;
    scanf(" %d", &n);

    vector<int> r(n), c(n), a(n);
    rep(i,n)
    {
        scanf(" %d %d %d", &r[i], &c[i], &a[i]);
        --r[i];
        --c[i];
        G[r[i]].pb(edge{R+c[i],a[i]});
        G[R+c[i]].pb(edge{r[i],a[i]});
    }

    // 隣り合う辺同士で値を決めていく
    fill(val,val+N,INF);
    rep(i,R+C)
    {
        if(val[i]!=INF) continue;

        val[i]=0;
        queue<int> que;
        que.push(i);
        while(!que.empty())
        {
            int v=que.front();
            que.pop();
            rep(j,G[v].size())
            {
                edge e=G[v][j];
                if(val[e.to]==INF)
                {
                    val[e.to] = (ll)e.cost-val[v];
                    que.push(e.to);
                }
            }

        }
    }

    bool valid=true;

    // 正当性のチェック
    rep(i,n)
    {
        if(val[r[i]]+val[R+c[i]] != (ll)a[i])
        {
            valid=false;
            break;
        }
    }

    if(valid)
    {
        vector<bool> vis(R+C, false);
        rep(i,R+C)
        {
            if(vis[i]) continue;

            queue<int> que;
            vis[i]=true;
            que.push(i);

            ll minr=INF, minc=INF;
            if(i<R) minr=min(minr,val[i]);
            else minc=min(minc,val[i]);

            while(!que.empty())
            {
                int v=que.front();
                que.pop();
                rep(j,G[v].size())
                {
                    edge e=G[v][j];
                    if(!vis[e.to])
                    {
                        vis[e.to]=true;
                        que.push(e.to);

                        if(e.to<R) minr=min(minr,val[e.to]);
                        else minc=min(minc,val[e.to]);
                    }
                }
            }

            if(minr+minc<0)
            {
                valid=false;
                break;
            }
        }
    }

    cout << (valid?"Yes":"No") << endl;
    return 0;
}
