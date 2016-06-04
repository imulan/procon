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

//SETTING

//型設定(int?long?ll?)
typedef int ff_t;

//辺を表す構造体(行き先、容量。逆辺)
struct edge {ff_t to, cap, rev;};

//ノードの数
const ff_t MAX_V = 2010;
//LIMIT
const ff_t FF_INF = 123456;
//グラフの隣接リスト表現
vector<edge> G[MAX_V];
//DFSですでに調べたかのフラグ
bool used[MAX_V];

//fromからtoへ向かう容量capの辺をグラフに追加する
void add_edge(ff_t from, ff_t to, ff_t cap=1){
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, 0, G[from].size()-1});
}

//増加パスを探す
ff_t ff_dfs(ff_t v, ff_t t, ff_t f){
    if(v==t) return f;
    used[v]=true;

    for(ff_t i=0; i<G[v].size(); ++i){
        edge &e=G[v][i];
        if(!used[e.to] && e.cap>0){
            ff_t d = ff_dfs(e.to, t, min(f,e.cap));
            if(d>0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }

    return 0;
}

//sからtへの最大流を求める
ff_t max_flow(ff_t s, ff_t t){
    ff_t flow=0;
    for(;;){
        memset(used,0,sizeof(used));
        ff_t f = ff_dfs(s,t,FF_INF);
        if(f==0) return flow;
        flow+=f;
    }
}

typedef pair<string,string> ps;

int main()
{
    int T;
    cin >>T;
    rep(t,T)
    {
        //initialize
        rep(i,MAX_V)
        {
            G[i].clear();
            used[i]=false;
        }

        int n;
        cin >>n;

        set<string> F,S;
        vector<ps> w(n);
        rep(i,n)
        {
            cin >>w[i].fi >>w[i].se;
            F.insert(w[i].fi);
            S.insert(w[i].se);
        }

        int a=F.size(),b=S.size();
        /*
        頂点番号
        0:source
        1~a:1番目の単語
        a+1~a+b:2番目の単語
        a+b+1:sink
        */

        //単語と頂点番号のひも付け
        map<string,int> df,ds;
        int ct=1;
        for(const auto& x:F) df[x]=ct++;
        for(const auto& x:S) ds[x]=ct++;

        //辺を張る(容量は全て1)
        //sourceから1番目の単語へ
        for(int i=1; i<=a; ++i) add_edge(0,i);
        //2番目の単語からsinkへ
        for(int i=a+1; i<=a+b; ++i) add_edge(i,a+b+1);
        //1番目の単語から2番目の単語へ
        rep(i,n) add_edge(df[w[i].fi],ds[w[i].se]);

        int min_cov=a+b-max_flow(0,a+b+1);
        int ans = n-min_cov;
        printf("Case #%d: %d\n", t+1, ans);
    }
    return 0;
}
