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

const int INF=12345678;

typedef pair<int,int> pi;

struct edge
{
    int to,dist,enem;
};

vector<edge> G[100];

int main()
{
    int n,m,l;
    while(cin >>n >>m >>l,n)
    {
        rep(i,100) G[i].clear();

        rep(i,m)
        {
            int a,b,d,e;
            scanf(" %d %d %d %d",&a,&b,&d,&e);
            --a;
            --b;
            G[a].pb(edge{b,d,e});
            G[b].pb(edge{a,d,e});
        }

        //iに予算jを持った状態で出会う盗賊の数の最小値
        int cost[100][101];

        fill(cost[0],cost[100],INF);
        cost[0][l]=0;

        queue<pi> que;
        que.push(pi(0,l));
        while(!que.empty())
        {
            pi v=que.front();
            que.pop();

            int now=v.fi;
            int money=v.se;
            rep(i,G[now].size())
            {
                edge E=G[now][i];

                //護衛を雇い通行
                if(money>=E.dist)
                {
                    if(cost[E.to][money-E.dist]>cost[now][money])
                    {
                        cost[E.to][money-E.dist]=cost[now][money];
                        que.push(pi(E.to,money-E.dist));
                    }
                }

                //護衛を雇わず通行
                if(cost[E.to][money]>cost[now][money]+E.enem)
                {
                    cost[E.to][money]=cost[now][money]+E.enem;
                    que.push(pi(E.to,money));
                }
            }
        }

        int ans=INF;
        rep(i,l+1) ans=min(ans,cost[n-1][i]);
        printf("%d\n", ans);
    }
    return 0;
}
