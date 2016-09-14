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

const int INF=12345678;
const int N=101010;
const int M=505050;

struct edge{int to, c;};

// 与えられる辺情報
vector<edge> G[N];
// 与えられる辺情報を元に拡張
vector<edge> exG[M];
//駅iにたどり着く直前に会社jの路線を使ったときにかかる料金の最小値
int dist[M];

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);

    // 拡張された頂点を連続する整数に変換
    map<pi,int> convert_pi_to_id;
    int idx=0;

    rep(i,m)
    {
        int p,q,company;
        scanf(" %d %d %d", &p, &q, &company);
        G[p].pb(edge{q,company});
        G[q].pb(edge{p,company});

        // 同じ鉄道会社間にはコスト0の辺を張る
        if(convert_pi_to_id.find(pi(p,company)) == convert_pi_to_id.end())
        {
            convert_pi_to_id[pi(p,company)] = idx++;
        }
        if(convert_pi_to_id.find(pi(q,company)) == convert_pi_to_id.end())
        {
            convert_pi_to_id[pi(q,company)] = idx++;
        }

        int id_p = convert_pi_to_id[pi(p,company)];
        int id_q = convert_pi_to_id[pi(q,company)];

        exG[id_p].pb(edge{id_q,0});
        exG[id_q].pb(edge{id_p,0});
    }

    // 駅iに関して
    for(int i=1; i<=n; ++i)
    {
        set<int> connected;
        rep(j,G[i].size()) connected.insert(G[i][j].c);

        convert_pi_to_id[pi(i,0)] = idx++;

        for(const int &company : connected)
        {
            int ent_id  = convert_pi_to_id[pi(i,company)];
            int exit_id = convert_pi_to_id[pi(i,0)];
            // 出場
            exG[ent_id].pb(edge{exit_id,0});
            // 入場
            exG[exit_id].pb(edge{ent_id,1});
        }
    }

    // dijkstra
    priority_queue<pi,vector<pi>,greater<pi>> pq;
    fill(dist,dist+M,INF);
    int start = convert_pi_to_id[pi(1,0)];
    dist[start]=0;
    pq.push(pi(0,start));
    while(!pq.empty())
    {
        pi now = pq.top();
        pq.pop();

        if(dist[now.se] < now.fi) continue;

        rep(i,exG[now.se].size())
        {
            edge e = exG[now.se][i];
            if(dist[e.to] > dist[now.se]+e.c)
            {
                dist[e.to] = dist[now.se]+e.c;
                pq.push(pi(dist[e.to], e.to));
            }
        }
    }

    int goal = convert_pi_to_id[pi(n,0)];
    int ans=dist[goal];
    if(ans==INF) ans=-1;
    cout << ans << endl;
    return 0;
}
