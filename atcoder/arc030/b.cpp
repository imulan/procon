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

int n,x;
int h[100];
vector<int> G[100];

//その頂点を訪れるべきかどうか
int vis[100]={0};

int dfs(int now, int p)
{
    int ret=0;
    if(h[now]) ret=1;

    rep(i,G[now].size())
    {
        int nx=G[now][i];
        if(nx==p) continue;

        ret|=dfs(nx,now);
    }

    return vis[now]=ret;
}

int main()
{
    cin >>n >>x;
    --x;
    rep(i,n) cin >>h[i];
    rep(i,n-1)
    {
        int a,b;
        cin >>a >>b;
        --a;
        --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    int tmp=dfs(x,x);
    //rep(i,n) printf("vis %d = %d\n",i+1,vis[i]);

    int ans=0;
    int v[100]={0};

    queue<int> que;
    que.push(x);
    v[x]=1;
    while(!que.empty())
    {
        int p=que.front();
        que.pop();
        rep(i,G[p].size())
        {
            int nx=G[p][i];
            if(nx==p) continue;

            if(vis[nx] && !v[nx])
            {
                v[nx]=1;
                que.push(nx);
                ans+=2;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
