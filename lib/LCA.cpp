/******************************
 LCA.cpp  START
******************************/

/******************************
 Lowest Common Ancestor
 木において最も近い共通祖先を求める
******************************/

//SETTING

//型設定(int?long?ll?)
typedef int lca_t;

//ノードの個数
const lca_t MAX_V = ;
//ダブリングに必要なサイズ(log(MAX_V))
const lca_t MAX_LOG_V = ;
//木の隣接リスト表現
vector<lca_t> G[MAX_V];
//根のノード番号
lca_t root = ;

//親を2^k回辿って到達するノード(根を通り過ぎる場合,-1)
int parent[MAX_LOG_V][MAX_V];
//根からの深さ
int depth[MAX_V];

//現在vに注目、親はp、深さd
void lca_dfs(lca_t v, lca_t p, lca_t d){
  parent[0][v]=p;
  depth[v]=d;
  for(lca_t i=0; i<G[v].size(); ++i){
    if(G[v][i]!=p){ //親でなければ子
      lca_dfs(G[v][i], v, d+1);
    }
  }
}

//初期化
void lca_init(lca_t V){
  //parent[0]とdepthの初期化
  lca_dfs(root, -1, 0);
  //parentの初期化
  for(lca_t k=0; k+1<MAX_LOG_V; ++k){
    for(lca_t v=0; v<V; ++v){
      if(parent[k][v] < 0) parent[k+1][v]=-1;
      else parent[k+1][v] = parent[k][parent[k][v]];
    }
  }
}

//uとvのLCAを求める
lca_t lca(lca_t u, lca_t v){
  //uとvの深さが同じになるまで親を辿る
  if(depth[u] > depth[v]) swap(u,v);
  for(lca_t k=0; k<MAX_LOG_V; ++k){
    if((depth[v]-depth[u])>>k & 1){
      v = parent[k][v];
    }
  }

  if(u==v) return u;

  //二分探索でLCAを求める
  for(lca_t k=MAX_LOG_V-1; k>=0; --k){
    if(parent[k][u] != parent[k][v]){
      u=parent[k][u];
      v=parent[k][v];
    }
  }

  return parent[0][u];
}


/******************************
 LCA.cpp  END
******************************/
