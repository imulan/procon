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

const int N=100000;
const int INF=123456789;

vector<pi> X[1000];
int n,m,d,k;
int x[N],y[N];

inline int d2(int a, int b)
{
    return (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
}

vector<int> G[N];
int dist[N];

int main()
{
    scanf(" %d %d %d %d", &n, &m, &d, &k);
    rep(i,n)
    {
        scanf(" %d %d", &x[i], &y[i]);
        X[x[i]].pb(pi(y[i],i));
    }

    rep(i,1000) sort(all(X[i]));

    rep(i,n)
    {
        for(int p=max(0,x[i]-d); p<=min(999,x[i]+d); ++p)
        {
            if(X[p].size()==0) continue;

            int idx = lower_bound(all(X[p]),pi(y[i]-d,-1)) - X[p].begin();

            while(idx < X[p].size() && X[p][idx].fi<=y[i]+d)
            {
                int z = X[p][idx].se;
                if(d2(i,z) <= d*d) G[i].pb(z);
                ++idx;
            }
        }
    }

    fill(dist,dist+N,INF);
    dist[0]=0;
    queue<int> que;
    que.push(0);
    while(!que.empty())
    {
        int v = que.front();
        que.pop();
        for(const auto &nx:G[v])
        {
            if(dist[nx]>dist[v]+1)
            {
                dist[nx] = dist[v]+1;
                que.push(nx);
            }
        }
    }

    int ans = 0;
    rep(i,n) ans += (dist[i]<=k && k<dist[i]+m);
    printf("%d\n", ans);
    return 0;
}
