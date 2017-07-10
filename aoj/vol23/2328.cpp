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

using vi = vector<int>;

// (行き先,容量,逆辺)
struct edge{
    int to;
    vi cap;
    int rev;
};

const int MAX_V = 50; // TODO:initialize
const vi F_INF = vi(51,19191919); // TODO:initialize
vector<edge> G[MAX_V];
int level[MAX_V]; // sからの距離
int iter[MAX_V]; // どこまで調べ終わったか

void show(vi f)
{
    string ans = "";
    for(int i=50; i>0; --i)if(f[i]!=0)
    {
        if(f[i]>0) ans += "+";
        else ans += "-";

        if(abs(f[i])>1) ans += to_string(abs(f[i]));

        if(i>0)
        {
            ans += "x";
            if(i>1) ans += "^" + to_string(i);
        }
    }

    if(f[0]!=0)
    {
        if(f[0]>0) ans += "+";
        else ans += "-";
        ans += to_string(abs(f[0]));
    }

    if(ans=="") ans = "0";
    if(ans[0]=='+') ans = ans.substr(1);
    cout << ans << endl;
}

void add_edge(int from, int to, vi cap){
    G[from].pb({to,cap,(int)G[to].size()});
    G[to].pb({from,cap,(int)G[from].size()-1});
}

inline bool positive(vi v)
{
    for(int i=50; i>=0; --i)if(v[i]!=0) return v[i]>0;
    return false;
}

inline vi ADD(vi a, vi b)
{
    vi ret(51);
    rep(i,51) ret[i]=a[i]+b[i];
    return ret;
}

inline vi SUB(vi a, vi b)
{
    vi ret(51);
    rep(i,51) ret[i]=a[i]-b[i];
    return ret;
}

inline vi vi_min(vi a, vi b)
{
    for(int i=50; i>=0; --i)
    {
        int d = a[i]-b[i];
        if(d>0) return b;
        else if(d<0) return a;
    }
    return a;
}

void dinic_bfs(int s){
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s]=0;
    que.push(s);
    while(!que.empty()){
        int v = que.front();
        que.pop();
        rep(i,G[v].size()){
            edge &e = G[v][i];
            if(positive(e.cap) && level[e.to]<0){
                level[e.to] = level[v]+1;
                que.push(e.to);
            }
        }
    }
}

// 増加パスをdfsで探す
vi dinic_dfs(int v, int t, vi f){
    if(v==t) return f;
    for(int &i=iter[v]; i<G[v].size(); ++i){
        edge &e=G[v][i];
        if(positive(e.cap) && level[v]<level[e.to]){
            vi d = dinic_dfs(e.to,t,vi_min(f,e.cap));
            if(positive(d)){
                e.cap = SUB(e.cap,d);
                G[e.to][e.rev].cap = ADD(G[e.to][e.rev].cap,d);
                return d;
            }
        }
    }
    return vector<int>(51,0);
}

// sからtへの最大流
vi max_flow(int s, int t){
    vi flow(51);
    while(1){
        dinic_bfs(s);
        if(level[t]<0) return flow;
        memset(iter,0,sizeof(iter));
        vi f;
        while( positive(f=dinic_dfs(s,t,F_INF)) ) flow = ADD(flow,f);
    }
}

vector<string> split(const string &s, char d)
{
    vector<string> ret;
    stringstream ss(s);
    string item;
    while(getline(ss,item,d))
    {
        if(!item.empty()) ret.pb(item);
    }
    return ret;
}

vi convert(string s)
{
    vi ret(51);
    for(const auto &t:split(s,'+'))
    {
        int idx = t.find("x");
        if(idx==-1) ret[0]=atoi(t.c_str());
        else
        {
            int n = 1;
            if(idx+2<t.size())
            {
                string i=t.substr(idx+2);
                n = atoi(i.c_str());
            }

            string a=t.substr(0,idx);
            int val = 1;
            if(a.size()) val = atoi(a.c_str());

            ret[n] = val;
        }
    }
    return ret;
}

int main()
{
    int n,m;
    while(cin >>n >>m,n)
    {
        rep(i,MAX_V) G[i].clear();
        rep(i,m)
        {
            int u,v;
            string s;
            cin >>u >>v >>s;
            add_edge(u-1,v-1,convert(s));
        }
        show(max_flow(0,n-1));
    }
    return 0;
}
