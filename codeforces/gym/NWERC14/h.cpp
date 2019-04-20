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

const int N = 10000;
vector<int> G[N];
pi f[N];

int now = 3;

void dfs(int v, int p){
    int ch = 0;
    for(int nx:G[v])if(nx!=p) ++ch;
    if(ch==0) f[v] = f[p];

    bool flg = true;
    for(int nx:G[v])if(nx!=p){
        if(flg) f[nx] = {f[v].se, now++};
        else f[nx] = {f[v].fi, now++};
        flg = !flg;

        dfs(nx, v);
    }
}

int main(){
    int n;
    scanf(" %d", &n);
    rep(i,n-1){
        int a,b;
        scanf(" %d %d", &a, &b);
        --a; --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    f[0] = {1,2};
    dfs(0,-1);

    rep(i,n) printf("%d %d\n", f[i].fi, f[i].se);
    return 0;
}
