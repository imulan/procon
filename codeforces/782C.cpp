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

int n;
vector<int> G[N];
int col[N]={};
int use[N+1]={};

int main()
{
    scanf(" %d", &n);
    rep(i,n-1)
    {
        int x,y;
        scanf(" %d %d", &x, &y);
        --x;
        --y;

        G[x].pb(y);
        G[y].pb(x);
    }

    queue<pi> que;
    queue<int> tmp_use;

    que.push(pi(0,-1));
    col[0]=1;
    while(!que.empty())
    {
        pi p = que.front();
        que.pop();
        int now = p.fi;
        int par = p.se;

        use[col[now]]=1;
        if(par!=-1) use[col[par]]=1;

        int idx=1;
        rep(i,G[now].size())
        {
            int nx = G[now][i];
            if(nx==par) continue;

            while(use[idx]) ++idx;
            tmp_use.push(idx);
            use[idx]=1;
            col[nx]=idx;
            que.push(pi(nx,now));
        }

        while(!tmp_use.empty())
        {
            int v = tmp_use.front();
            tmp_use.pop();
            use[v]=0;
        }
        use[col[now]]=0;
        if(par!=-1) use[col[par]]=0;
    }

    int ans = 0;
    rep(i,n) ans = max(ans,col[i]);

    printf("%d\n", ans);
    rep(i,n)
    {
        if(i) printf(" ");
        printf("%d", col[i]);
    }
    printf("\n");
    return 0;
}
