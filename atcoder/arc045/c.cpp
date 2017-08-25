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

const int MAX_V = 100000;

struct edge{int to,cost;};
vector<edge> g[MAX_V];
int d[MAX_V];

int main()
{
    int n,X;
    scanf(" %d %d", &n, &X);
    rep(i,n-1)
    {
        int x,y,c;
        scanf(" %d %d %d", &x, &y, &c);
        --x;
        --y;
        g[x].pb({y,c});
        g[y].pb({x,c});
    }

    memset(d,-1,sizeof(d));
    queue<int> que;
    que.push(0);
    d[0] = 0;
    while(!que.empty())
    {
        int v = que.front();
        que.pop();
        for(const auto &e:g[v])if(d[e.to]<0)
        {
            d[e.to] = d[v]^e.cost;
            que.push(e.to);
        }
    }

    map<int,int> ct;
    rep(i,n) ++ct[d[i]];

    ll ans = 0;
    rep(i,n) ans += ct[d[i]^X];
    if(X==0) ans -= n;
    printf("%lld\n", ans/2);
    return 0;
}
