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

struct Rect{ int lx,rx,ly,ry; };

int n,w,h;
int f[100][100];

const int N=1001;
Rect r[N];
bool pre[N]={};

vector<int> G[N];
vector<int> L;
bool vis[1001]={};
void dfs(int v)
{
    if(!vis[v])
    {
        vis[v]=true;
        for(const auto &e:G[v]) dfs(e);
        L.pb(v);
    }
}

int main()
{
    scanf(" %d %d %d", &n, &w, &h);
    rep(i,h)rep(j,w)
    {
        scanf(" %d", &f[i][j]);
        pre[f[i][j]]=true;
    }

    for(int j=w-1; j>=0; --j)rep(i,h) r[f[i][j]].lx=j;
    rep(j,w)rep(i,h) r[f[i][j]].rx=j;
    for(int i=h-1; i>=0; --i)rep(j,w) r[f[i][j]].ly=i;
    rep(i,h)rep(j,w) r[f[i][j]].ry=i;

    for(int i=1; i<=n; ++i)
    {
        if(!pre[i]) continue;
        for(int y=r[i].ly; y<=r[i].ry; ++y)for(int x=r[i].lx; x<=r[i].rx; ++x)
        {
            if(f[y][x]!=i && f[y][x]!=0) G[i].pb(f[y][x]);
        }
    }

    for(int i=1; i<=n; ++i) dfs(i);
    reverse(all(L));
    rep(i,L.size())
    {
        if(i) printf(" ");
        printf("%d", L[i]);
    }
    printf("\n");
    return 0;
}
