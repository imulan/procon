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

struct edge{int to; ll cost;};
const ll INF = LLONG_MAX/3;

int main()
{
    int n;
    scanf(" %d", &n);

    vector<vector<edge>> g(n);
    rep(i,n-1)
    {
        int a,b,c;
        scanf(" %d %d %d", &a, &b, &c);
        --a;
        --b;
        g[a].pb({b,c});
        g[b].pb({a,c});
    }

    int Q,K;
    scanf(" %d %d", &Q, &K);
    --K;

    vector<ll> d(n,INF);
    d[K] = 0;
    queue<int> que;
    que.push(K);
    while(!que.empty())
    {
        int v = que.front();
        que.pop();
        for(const auto &e:g[v])
        {
            if(d[e.to] > d[v]+e.cost)
            {
                d[e.to] = d[v]+e.cost;
                que.push(e.to);
            }
        }
    }

    while(Q--)
    {
        int x,y;
        scanf(" %d %d", &x, &y);
        --x;
        --y;
        printf("%lld\n", d[x]+d[y]);
    }
    return 0;
}
