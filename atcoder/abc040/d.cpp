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

struct edge{int to,year;};

vector<edge> G[100000];

int main()
{
    int n,m;
    cin >>n >>m;
    rep(i,m)
    {
        int a,b,y;
        scanf(" %d %d %d",&a,&b,&y);
        --a;
        --b;
        G[a].pb(edge{b,y});
        G[b].pb(edge{a,y});
    }

    int Q;
    cin >>Q;
    rep(q,Q)
    {
        int v,w;
        cin >>v >>w;
        --v;

        int vis[1000]={0};

        queue<int> que;
        que.push(v);
        vis[v]=1;
        while(!que.empty())
        {
            int now=que.front();
            que.pop();
            rep(i,G[now].size())
            {
                int nx=G[now][i].to;
                int yy=G[now][i].year;
                if(!vis[nx] && yy>w)
                {
                    vis[nx]=1;
                    que.push(nx);
                }
            }
        }

        int ans=0;
        rep(i,n) ans+=vis[i];

        cout << ans << endl;
    }

    return 0;
}
