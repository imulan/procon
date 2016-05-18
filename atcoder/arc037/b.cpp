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

int main()
{
    int n,m;
    cin >>n >>m;

    vector<vector<int>> G(n,vector<int>(n,0));

    rep(i,m)
    {
        int u,v;
        scanf(" %d %d",&u,&v);
        --u;
        --v;
        G[u][v]=G[v][u]=1;
    }

    int ans=0;
    vector<bool> vis(n,false);

    rep(i,n)
    {
        if(!vis[i])
        {
            vector<bool> v(n,false);
            queue<int> que;
            que.push(i);
            v[i]=true;
            while(!que.empty())
            {
                int now=que.front();
                que.pop();
                rep(j,n)
                {
                    if(G[now][j] && !v[j])
                    {
                        v[j]=true;
                        que.push(j);
                    }
                }
            }

            int num=0;
            rep(j,n) if(v[j]) ++num;

            int ct=0;
            rep(j,n)rep(k,j)
            {
                if(v[j] && v[k] && G[j][k]) ++ct;
            }

            if(num-1==ct) ++ans;

            rep(j,n) if(v[j]) vis[j]=true;
        }
    }

    printf("%d\n", ans);
    return 0;
}
