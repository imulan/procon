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

const int N=6002,M=302;
const int INF=123456789;

struct edge{int to,cost;};
vector<edge> G[N], g[M];

int d[N];
void dijkstra(int start)
{
    fill(d,d+N,INF);

    priority_queue<pi,vector<pi>,greater<pi>> que;
    d[start]=0;
    que.push(pi(0,start));
    while(!que.empty()){
        pi p=que.top();
        que.pop();
        int v=p.se;
        if(d[v]<p.fi) continue;
        rep(i,G[v].size())
        {
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost)
            {
                d[e.to]=d[v]+e.cost;
                que.push(pi(d[e.to],e.to));
            }
        }
    }
}

int solve()
{
    fill(d,d+M,INF);

    priority_queue<pi,vector<pi>,greater<pi>> que;
    d[0]=0;
    que.push(pi(0,0));
    while(!que.empty()){
        pi p=que.top();
        que.pop();
        int v=p.se;
        if(d[v]<p.fi) continue;
        rep(i,g[v].size())
        {
            edge e=g[v][i];
            if(d[e.to]>d[v]+e.cost)
            {
                d[e.to]=d[v]+e.cost;
                que.push(pi(d[e.to],e.to));
            }
        }
    }

    return d[1];
}

void init()
{
    rep(i,N) G[i].clear();
    rep(i,M) g[i].clear();
}

int main()
{
    int n,m,cap;
    while(cin >>n >>m >>cap,n)
    {
        init();

        string src,dest;
        cin >>src >>dest;

        map<string,int> name_to_id;
        name_to_id[src]=0;
        name_to_id[dest]=1;

        int now=2;
        rep(i,n)
        {
            string a,b;
            int D;
            cin >>a >>b >>D;

            if(name_to_id.find(a) == name_to_id.end()) name_to_id[a]=now++;
            if(name_to_id.find(b) == name_to_id.end()) name_to_id[b]=now++;

            int A=name_to_id[a], B=name_to_id[b];
            G[A].pb(edge{B,D});
            G[B].pb(edge{A,D});
        }

        vector<string> st(m);
        rep(i,m) cin >>st[i];

        dijkstra(0);
        rep(i,m)
        {
            int s=name_to_id[st[i]];
            if(s<=1) continue;

            if(d[s] <= cap*10) g[0].pb(edge{i+2,d[s]});

        }
        if(d[1] <= cap*10) g[0].pb(edge{1,d[1]});

        rep(i,m)
        {
            int s=name_to_id[st[i]];
            if(s<=1) continue;

            dijkstra(s);
            rep(j,m)
            {
                int t=name_to_id[st[j]];
                if(t<=1) continue;

                if(d[t] <= cap*10) g[i+2].pb(edge{j+2,d[t]});
            }
            if(d[1] <= cap*10) g[i+2].pb(edge{1,d[1]});
        }

        int ans=solve();
        if(ans==INF) ans=-1;
        cout << ans << endl;
    }
    return 0;
}
