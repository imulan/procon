const int MAX_V =; //頂点の数
const int MAX_E =; //辺の数
const int INF =; //初期化

// 有向辺
struct edge{int from, to, cost;};
edge edges[MAX_E];
// 最短距離
int dist[MAX_V];

int V,E;

// falseで負の閉路検出
bool shortest_path(int s)
{
    // 閉路検出
    memset(dist,0,sizeof(dist));
    for(int i=0; i<V; ++i)
    {
        for(int j=0; j<E; ++j)
        {
            edge e=edges[j];
            if(dist[e.to]>dist[e.from]+e.cost)
            {
                dist[e.to]=dist[e.from]+e.cost;
                // V回目にも更新がある時、負の閉路が存在
                if(i==V-1) return false;
            }
        }
    }

    // 最短経路
    for(int i=0; i<V; ++i) dist[i]=INF;
    d[s]=0;
    while(1)
    {
        bool update=false;
        for(int i=0; i<E; ++i)
        {
            edge e=edges[i];
            if(dist[e.from]!=INF && dist[e.to]>dist[e.from]+e.cost)
            {
                dist[e.to]=dist[e.from]+e.cost;
                update=true;
            }
        }
        if(!update) break;
    }

    return true;
}
