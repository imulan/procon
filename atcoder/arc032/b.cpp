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

vector<int> G[100000];

int main()
{
    int n,m;
    cin >>n >>m;
    rep(i,m)
    {
        int a,b;
        scanf(" %d %d", &a, &b);
        --a;
        --b;

        G[a].pb(b);
        G[b].pb(a);
    }

    int ans=0;
    int vis[100000]={0};
    rep(i,n)
    {
        if(vis[i]) continue;

        ++ans;
        queue<int> que;
        que.push(i);
        vis[i]=1;
        while(!que.empty())
        {
            int v=que.front();
            que.pop();
            rep(j,G[v].size())
            {
                if(!vis[G[v][j]])
                {
                    vis[G[v][j]]=1;
                    que.push(G[v][j]);
                }
            }
        }
    }

    cout << ans-1 << endl;
    return 0;
}
