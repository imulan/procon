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

const int N = 100000;
vector<int> G[N];

int d[N],par[N],dp[N];
void dfs(int now, int p)
{
    par[now] = p;

    if(p==-1) d[now]=0;
    else d[now] = d[p]+1;

    dp[now] = 1;
    for(int nx:G[now])if(nx!=p)
    {
        dfs(nx,now);
        dp[now] += dp[nx];
    }
}

int main()
{
    int n;
    cin >>n;
    rep(i,n-1)
    {
        int a,b;
        cin >>a >>b;
        --a; --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    dfs(0,-1);

    int v=n-1;
    rep(i,(d[n-1]-1)/2) v = par[v];

    string ans = "Fennec";
    if((n+1)/2<=dp[v]) ans = "Snuke";
    cout << ans << endl;
    return 0;
}
