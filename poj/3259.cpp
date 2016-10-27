#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int MAX_V =500; //頂点の数
const int MAX_E =5500; //辺の数
const int INF =123456789; //初期化

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
    dist[s]=0;
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

int main()
{
    int F;
    scanf(" %d", &F);
    while(F--)
    {
        int n,m,w;
        scanf(" %d %d %d", &n, &m, &w);
        V=n;
        E=2*m+w;

        rep(i,m)
        {
            int s,e,t;
            scanf(" %d %d %d", &s, &e, &t);
            --s;
            --e;
            edges[2*i]=edge{s,e,t};
            edges[2*i+1]=edge{e,s,t};
        }
        rep(i,w)
        {
            int s,e,t;
            scanf(" %d %d %d", &s, &e, &t);
            --s;
            --e;
            edges[2*m+i]=edge{s,e,-t};
        }

        string ans="YES";
        if(shortest_path(0)) ans="NO";
        cout << ans << endl;
    }
    return 0;
}
