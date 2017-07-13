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
using P = pair<int,pi>;
struct edge{int to,type;};

const int N = 10000;
const int B = 143;
const int INF = 191919191;

int min_b[N];
int d[N][B];
vector<edge> G[N];

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);
    while(m--)
    {
        int c,a,b;
        scanf(" %d %d %d", &c, &a, &b);
        G[a].pb({b,c});
        G[b].pb({a,c});
    }

    fill(min_b,min_b+N,INF);
    min_b[0]=0;
    deque<pi> deq;
    deq.push_back({0,0});
    while(!deq.empty())
    {
        pi p = deq.front();
        deq.pop_front();

        int v = p.se;
        if(p.fi>min_b[v]) continue;
        for(const auto &e:G[v])
        {
            if(min_b[e.to] > min_b[v]+e.type)
            {
                min_b[e.to] = min_b[v]+e.type;
                if(e.type==0) deq.push_front(pi(min_b[e.to],e.to));
                else deq.push_back(pi(min_b[e.to],e.to));
            }
        }
    }

    fill(d[0],d[N],INF);
    d[0][0]=0;
    priority_queue<P,vector<P>,greater<P>> pq;
    pq.push(P(0,pi(0,0)));
    while(!pq.empty())
    {
        P p = pq.top(); pq.pop();
        int v = p.se.fi, b = p.se.se;
        if(p.fi>d[v][b]) continue;
        for(const auto &e:G[v])
        {
            int nb = b+e.type+min_b[v]-min_b[e.to];
            int add = 1;
            if(e.type==1) add += min_b[v]+b;

            if(nb<B && d[e.to][nb] > d[v][b]+add)
            {
                d[e.to][nb] = d[v][b]+add;
                pq.push(P(d[e.to][nb],pi(e.to,nb)));
            }
        }
    }

    rep(i,n)
    {
        int ans = INF;
        rep(j,B) ans = min(ans,d[i][j]);
        printf("%d\n", ans);
    }
    return 0;
}
