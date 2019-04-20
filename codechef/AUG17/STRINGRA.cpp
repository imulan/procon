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

// 大体320くらいまでしか許されない
const int N = 320;
set<int> s[N];

const int V = 100010;
vector<int> G[V];

void solve()
{
    rep(i,V) G[i].clear();
    rep(i,N) s[i].clear();

    int n,m;
    scanf(" %d %d", &n, &m);

    vector<pi> e(m);
    set<pi> edges;
    rep(i,m)
    {
        int x,y;
        scanf(" %d %d", &x, &y);
        e[i] = {x,y};
        edges.insert(e[i]);
    }
    sort(all(e));

    rep(i,m)
    {
        int x = e[i].fi, y = e[i].se;
        G[x].pb(y);
    }

    vector<int> a(n,-1);
    bool ok = true;

    int t = 1;
    for(const auto &i:G[0]) a[i-1] = t++;

    // (0 1)は絶対ある
    if(G[0][0]!=1)
    {
        printf("-1\n");
        return;
    }







    if(!ok)
    {
        printf("-1\n");
        return;
    }

    // ok
    rep(i,n) printf("%d%c", a[i],(i==n-1?'\n':' '));
}

int main()
{
    int T;
    cin >>T;
    while(T--) solve();
    return 0;
}
