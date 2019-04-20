/* Dinic */

// (行き先,容量,逆辺)
struct edge{ int to,cap,rev; };

const int MAX_V = ; // TODO:initialize
const int F_INF = ; // TODO:initialize
vector<edge> G[MAX_V];
int level[MAX_V]; // sからの距離
int iter[MAX_V]; // どこまで調べ終わったか

void add_edge(int from, int to, int cap){
    G[from].pb({to,cap,(int)G[to].size()});
    G[to].pb({from,0,(int)G[from].size()-1});
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
            if(e.cap>0 && level[e.to]<0){
                level[e.to] = level[v]+1;
                que.push(e.to);
            }
        }
    }
}

// 増加パスをdfsで探す
int dinic_dfs(int v, int t, int f){
    if(v==t) return f;
    for(int &i=iter[v]; i<(int)G[v].size(); ++i){
        edge &e=G[v][i];
        if(e.cap>0 && level[v]<level[e.to]){
            int d = dinic_dfs(e.to,t,min(f,e.cap));
            if(d>0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

// sからtへの最大流
int max_flow(int s, int t){
    int flow = 0;
    while(1){
        dinic_bfs(s);
        if(level[t]<0) return flow;
        memset(iter,0,sizeof(iter));
        int f;
        while( (f=dinic_dfs(s,t,F_INF)) > 0 ) flow+=f;
    }
}

// 辺に対して最小流量の制約がある場合
// u->v : 最大流量c, 最小流量b の 辺e について

// 旧source(s),sink(t)
// 新しいsource(S),sink(T)を作成
// 辺の張り方
// u->v : c-b / u->T : b / S->v : b
// S->s : INF / t->T

// 新しいグラフでの流量 maxflow(S,T) = F'
// 元のグラフの最大流量 F = F' - Σb

// 下限制約を満たせるとは限らない場合のチェック方法
// S->s,t->Tを張る前に、 t->s:INFを張ってmax_flow(S,T) = Σbになることを確認する必要がある

/*
"燃やす埋める"
「Xが赤でYが青だとZ円罰金」
X->Yに容量Zの辺を貼る

「Xが赤 or 青だとZ円罰金」
赤だと罰金:X->Tに容量Zの辺
青だと罰金:S->Xに容量Zの辺

「Xが赤でYが赤だとZ円報酬」
新たな頂点Wを考える
強制的にZ円もらう
Wが青だとZ円罰金
Wが赤でXが青だとINF円罰金
Wが赤でYが青だとINF円罰金

「Aが赤でBが赤でCが赤だとZ円報酬」
これも同じ
新たな頂点Wを考える
強制的にZ円もらう
Wが青だとZ円罰金
Wが赤でAが青だとINF円罰金
Wが赤でBが青だとINF円罰金
Wが赤でCが青だとINF円罰金
*/

// マッチングについて
// 孤立点のないグラフに対し、 |最大マッチング| + |最小辺カバー| = |V|
// |最大安定集合| + |最小点カバー| = |V|
// ""二部グラフの場合には"" |最大マッチング| = |最小点カバー|
