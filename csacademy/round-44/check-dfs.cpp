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

int n,m;
int p[N],f[N];
set<int> G[N];

bool vis[N]={};
int now = 0;
int ans = 1;
bool goal = false;

void dfs(int v)
{
    if(vis[v]) return;
    vis[v] = true;

    // printf("v %d now %d\n", v,now);

    if(v==n-1)
    {
        goal = true;
        return;
    }

    bool not_vis = false;
    bool next = false;
    for(int nx:G[v])
    {
        if(!vis[nx])
        {
            not_vis = true;
            if(nx==now+1)
            {
                next = true;
                ++now;
                dfs(nx);
            }

        }
    }

    if(not_vis && !next) ans = 0;
}

int main()
{
    cin >>n >>m;
    rep(i,n)
    {
        cin >>p[i];
        --p[i];
        f[p[i]]=i;
    }
    rep(i,m)
    {
        int a,b;
        cin >>a >>b;
        --a;
        --b;
        a = f[a];
        b = f[b];
        // printf("  %d %d\n", a,b);
        G[a].insert(b);
        G[b].insert(a);
    }

    dfs(0);
    if(ans==1 && !goal) ans = 0;
    cout << ans << endl;
    return 0;
}
