#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int V=200000;
vector<int> G[V],R[V];

int main()
{
    int N,K,L;
    scanf(" %d %d %d", &N, &K, &L);

    rep(i,K)
    {
        int p,q;
        scanf(" %d %d", &p, &q);
        --p;
        --q;
        G[p].pb(q);
        G[q].pb(p);
    }

    rep(i,L)
    {
        int r,s;
        scanf(" %d %d", &r, &s);
        --r;
        --s;

        R[r].pb(s);
        R[s].pb(r);
    }

    vector<int> vis(N,-1);
    int con=0;
    rep(i,N)
    {
        if(vis[i]>=0) continue;

        vis[i]=con;
        queue<int> que;
        que.push(i);
        while(!que.empty())
        {
            int v=que.front();
            que.pop();
            rep(j,G[v].size())
            {
                int nx=G[v][j];
                if(vis[nx]==-1)
                {
                    vis[nx]=con;
                    que.push(nx);
                }
            }
        }

        ++con;
    }

    vector<int> ans(N,1);
    vector<bool> vis2(N,false);
    rep(i,N)
    {
        if(vis2[i]) continue;

        vis2[i]=true;
        vector<int> cc;
        cc.pb(i);
        queue<int> que;
        que.push(i);
        while(!que.empty())
        {
            int v=que.front();
            que.pop();
            rep(j,R[v].size())
            {
                int nx=R[v][j];
                if(!vis2[nx])
                {
                    vis2[nx]=true;
                    que.push(nx);
                    cc.pb(nx);
                }
            }
        }

        map<int,int> ct;
        rep(j,cc.size()) ++ct[vis[cc[j]]];
        rep(j,cc.size()) ans[cc[j]] = ct[vis[cc[j]]];
    }

    rep(i,N)
    {
        if(i) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
