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

// (行き先, 容量, コスト, 逆辺)
struct edge{ int to,cap,cost,rev; };

int V; // TODO:initialize
const int MAX_V = 1000; // TODO:initialize
const int INF = 1010101010; // TODO:initialize
vector<edge> G[MAX_V];
int h[MAX_V]; // ポテンシャル
int dist[MAX_V];
int prevv[MAX_V], preve[MAX_V]; // 直前の頂点と辺

void add_edge(int from, int to, int cap, int cost){
    G[from].pb({to,cap,cost,(int)G[to].size()});
    G[to].pb({from,0,-cost,(int)G[from].size()-1});
}

// sからtへの流量fの最小費用流(不可能なら-1)
int min_cost_flow(int s, int t, int f, bool neg = false){
    int res = 0;
    fill(h,h+V,0);
    while(f>0){
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        fill(dist,dist+V,INF);
        dist[s]=0;
        if(neg)
        {
            // bellman-fordでhを更新
            neg = false;
            bool update;
            do{
                update = false;
                rep(v,V){
                    if(dist[v] == INF) continue;
                    rep(i,G[v].size()){
                        edge &e = G[v][i];
                        if(e.cap>0 && dist[e.to]>dist[v]+e.cost){
                            dist[e.to]=dist[v]+e.cost;
                            prevv[e.to] = v;
                            preve[e.to] = i;
                            update = true;
                        }
                    }
                }
            }while(update);
        }
        else
        {
            // dijkstraでhを更新
            pq.push(pi(0,s));
            while(!pq.empty()){
                pi p = pq.top();
                pq.pop();
                int v = p.se;
                if(p.fi>dist[v]) continue;
                rep(i,G[v].size()){
                    edge &e = G[v][i];
                    if(e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
                        dist[e.to] = dist[v]+e.cost+h[v]-h[e.to];
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        pq.push(pi(dist[e.to],e.to));
                    }
                }
            }
        }

        // これ以上流せない
        if(dist[t]==INF) return -1;

        rep(v,V) h[v] += dist[v];

        // s-t間の最短路に沿って目一杯流す
        int d=f;
        for(int v=t; v!=s; v=prevv[v]) d = min(d,G[prevv[v]][preve[v]].cap);
        f -= d;
        res += d*h[t];

        for(int v=t; v!=s; v=prevv[v]){
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}

vector<string> split(const string &str, char sep){
    vector<string> v;
    stringstream ss(str);
    string buffer;
    while( getline(ss,buffer,sep ) ) v.pb(buffer);
    return v;
}

int edit_dist(const string &x, const string &y)
{
    int X = x.size(), Y = y.size();

    int dp[21][21];
    rep(i,21)rep(j,21) dp[i][j]=19191919;

    dp[0][0]=0;
    rep(i,X+1) dp[i][0]=i;
    rep(i,Y+1) dp[0][i]=i;
    for(int i=1; i<=X; ++i)for(int j=1; j<=Y; ++j)
    {
        if(j>=1) dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
        if(i>=1) dp[i][j] = min(dp[i][j],dp[i-1][j]+1);
        if(i>=1 && j>=1) dp[i][j] = min(dp[i][j],dp[i-1][j-1]+(x[i-1]!=y[j-1]));
    }
    return dp[X][Y];
}

int main()
{
    int n,m;
    cin >>n >>m;
    cin.ignore();

    map<string,int> web;
    rep(i,n)
    {
        string s;
        getline(cin,s);
        for(const auto &word:split(s,' '))
        {
            if(!web.count(word)) web[word]=0;
            ++web[word];
        }
    }

    vector<string> d(m);
    rep(i,m) cin >>d[i];

    int WEB = web.size();

    V = WEB+m+2;
    int S = WEB+m, T = S+1;
    rep(i,WEB) add_edge(S,i,1,0);
    rep(i,m) add_edge(WEB+i,T,1,0);

    int ct = 0;
    for(const auto &p:web)
    {
        rep(i,m)
        {
            int ed = edit_dist(p.fi,d[i]);
            // cout <<"("<<p.fi<<","<<d[i]<<") = "<<ed<<endl;
            add_edge(ct,WEB+i,1,ed*p.se);
        }
        ++ct;
    }

    cout << min_cost_flow(S,T,WEB) << endl;
    return 0;
}
