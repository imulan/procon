#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct edge{int to,cost;};
struct State
{
    int pos,rem,temp;
    bool operator<(const State &r) const {
        if(pos == r.pos)
        {
            if(rem == r.rem) return temp<r.temp;
            else return rem<r.rem;
        }
        else return pos<r.pos;
    }
};

using P = pair<int,State>;

const int V=10000;
const int INF=123456789;

vector<edge> G[V];
int d[V][201][3];

int main()
{
    int N,M,X;
    scanf(" %d %d %d", &N, &M, &X);
    vector<int> T(N);
    rep(i,N) scanf(" %d", &T[i]);
    rep(i,M)
    {
        int a,b,c;
        scanf(" %d %d %d", &a, &b, &c);
        --a;
        --b;
        G[a].pb({b,c});
        G[b].pb({a,c});
    }

    fill_n((int*)d, V*201*3, INF);
    d[0][X][0] = 0;
    priority_queue<P,vector<P>,greater<P>> pq;
    pq.push(P(0,{0,X,0}));
    while(!pq.empty())
    {
        P p = pq.top();
        pq.pop();
        State s = p.se;
        if(p.fi>d[s.pos][s.rem][s.temp]) continue;

        for(const auto &e:G[s.pos])
        {
            int nr = max(0, s.rem-e.cost);
            int nt = s.temp;
            if(nr==0) nt=1;

            if(T[e.to]!=1)
            {
                int ban = (T[e.to]==0)?2:0;
                if(nt==ban) continue;
                nr = X;
                nt = T[e.to];
            }

            if(d[e.to][nr][nt] > d[s.pos][s.rem][s.temp]+e.cost)
            {
                d[e.to][nr][nt] = d[s.pos][s.rem][s.temp]+e.cost;
                pq.push(P(d[e.to][nr][nt],{e.to,nr,nt}));
            }
        }
    }

    int ans=INF;
    rep(i,3)rep(j,X+1) ans = min(ans,d[N-1][j][i]);
    printf("%d\n", ans);
    return 0;
}
