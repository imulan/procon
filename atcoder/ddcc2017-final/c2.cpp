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

const int N = 300;
const ll INF = LLONG_MAX/4;
ll g[N][N];

int n;

vector<int> cycle,tc;
bool zero;
bool update_cycle = true;

void dfs(int v, vector<bool> &vis, ll s, int start)
{
    vis[v] = true;
    tc.pb(v);
    rep(i,n)if(g[v][i]!=INF)
    {
        if(i==start && s+g[v][i]!=0)
        {
            zero = false;
            if(update_cycle && tc.size()<cycle.size()) cycle = tc;
        }

        if(!vis[i]) dfs(i,vis,s+g[v][i],start);
    }

    tc.pop_back();
}

string solve()
{
    fill(g[0],g[N],INF);

    int m;
    cin >>n >>m;
    while(m--)
    {
        int a,b,c;
        cin >>a >>b >>c;
        --a; --b;
        g[a][b] = c;
    }

    // 大きさが最小のサイクルを探す
    cycle = vector<int>(n+1);
    rep(i,n)
    {
        vector<bool> vis(n);
        dfs(i,vis,0,i);
    }
    if(cycle.size() == n+1) return "Yes";

    update_cycle = false;

    int C = cycle.size();
    ll c_sum = 0;
    rep(i,C) c_sum += g[cycle[i]][cycle[(i+1)%C]];

    rep(i,C)
    {
        g[cycle[i]][cycle[(i+1)%C]] -= c_sum;

        rep(j,n)
        {
            zero = true;
            vector<bool> vis(n);
            dfs(j,vis,0,j);
            if(!zero) break;
        }

        if(zero) return "Yes";
        g[cycle[i]][cycle[(i+1)%C]] += c_sum;
    }

    return "No";
}

int main()
{
    cout << solve() << endl;
    return 0;
}
