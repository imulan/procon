#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

using pi = pair<int,int>;
struct edge{int to,cost;};

const int N = 1500;
const int INF = 19191919;
vector<edge> G[N];

int n;
int d[N][N];
bool can[N];

void dijkstra(int s)
{
    d[s][s] = 0;
    priority_queue<pi,vector<pi>,greater<pi>> pq;
    pq.push({0,s});
    while(!pq.empty())
    {
        pi now = pq.top();
        pq.pop();
        int v = now.se;
        if(now.fi>d[s][v]) continue;
        for(const auto &e:G[v])
        {
            if(d[s][e.to] > d[s][v]+e.cost)
            {
                d[s][e.to] = d[s][v]+e.cost;
                pq.push({d[s][e.to],e.to});
            }
        }
    }
}

void check(int s, int D)
{
    queue<int> que;
    vector<bool> vis(n);

    rep(i,n)if(d[s][i]==D)
    {
        que.push(i);
        vis[i] = true;
    }

    while(!que.empty())
    {
        int v = que.front();
        que.pop();
        vis[v] = true;
        can[v] = false;

        for(const auto &e:G[v])
        {
            if(!vis[e.to] && d[s][e.to]==d[s][v]-e.cost)
            {
                vis[e.to] = true;
                que.push(e.to);
            }
        }
    }
}

int main()
{
    int r;
    cin >>n >>r;
    while(r--)
    {
        int s,t,w;
        cin >>s >>t >>w;
        --s; --t;
        G[s].pb({t,w});
        G[t].pb({s,w});
    }

    fill(d[0],d[N],INF);
    fill(can,can+N,true);
    rep(i,n) dijkstra(i);

    int max_d = 0;
    rep(i,n)rep(j,n) max_d = max(max_d,d[i][j]);

    rep(i,n) check(i,max_d);

    vector<int> ans;
    rep(i,n)if(can[i]) ans.pb(i);

    cout << ans.size() << endl;
    for(const int &i:ans) cout << i+1 << endl;
    return 0;
}
