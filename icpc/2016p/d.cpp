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

const int MAX_N=100;

int n;
//寝坊する確率
double p[MAX_N];

vector<int> G[MAX_N];
vector<int> rG[MAX_N];
vector<int> vs;
bool used[MAX_N];
int cmp[MAX_N];

void add_edge(int from, int to)
{
    G[from].pb(to);
    rG[to].pb(from);
}

void dfs(int v)
{
    used[v]=true;
    rep(i,G[v].size())
    {
        if(!used[G[v][i]]) dfs(G[v][i]);
    }
    vs.pb(v);
}

void rdfs(int v,int k)
{
    used[v]=true;
    cmp[v]=k;
    rep(i,rG[v].size())
    {
        if(!used[rG[v][i]]) rdfs(rG[v][i],k);
    }
}

int scc()
{
    memset(used,0,sizeof(used));
    vs.clear();
    rep(i,n)
    {
        if(!used[i]) dfs(i);
    }

    memset(used,0,sizeof(used));
    int k=0;
    for(int i=vs.size()-1; i>=0; --i)
    {
        if(!used[vs[i]]) rdfs(vs[i],k++);
    }
    return k;
}

int main()
{
    while(cin >>n,n)
    {
        //初期化
        rep(i,MAX_N)
        {
            G[i].clear();
            rG[i].clear();
        }

        //input
        rep(i,n)
        {
            scanf(" %lf", &p[i]);

            int m;
            cin >>m;
            rep(j,m)
            {
                int a;
                cin >>a;
                --a;
                add_edge(i,a);
            }
        }

        int num=scc();
        /*
        printf("num= %d\n", num);
        rep(i,n) printf("cmp[%d]=%d\n", i,cmp[i]);
        */
        vector<int> s[MAX_N];
        rep(i,n) s[cmp[i]].pb(i);

        double ans=1;
        int now=0;
        int visit[100]={0};

        while(now<num)
        {
            if(visit[now])
            {
                ++now;
                continue;
            }

            visit[now]=true;
            //printf("now=%d\n", now);
            double t=1;
            rep(i,s[now].size()) t*=p[s[now][i]];
            ans*=1-t;

            int vis[100]={0};
            queue<int> que;
            rep(i,s[now].size())
            {
                que.push(s[now][i]);
                vis[s[now][i]]=1;
                //printf("push %d\n",s[now][i]);
            }

            while(!que.empty())
            {
                int c=que.front();
                que.pop();
                //printf("c=%d\n",c );
                rep(i,G[c].size())
                {
                    int nx=G[c][i];
                    if(!vis[nx])
                    {
                        vis[nx]=1;
                        que.push(nx);
                    }
                }

            }

            for(int i=now+1; i<num; ++i)
            {
                bool con=false;
                rep(j,s[i].size())
                {
                    if(vis[s[i][j]]) con=true;
                }
                if(con) visit[i]=true;
            }

        }


        printf("%.10lf\n", ans);
    }
    return 0;
}
