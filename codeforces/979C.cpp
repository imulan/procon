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

const int N = 300003;
vector<int> G[N];

ll sz[N];
int par[N];
void dfs(int x){
    sz[x] = 1;
    for(int c:G[x])if(c!=par[x]){
        par[c] = x;
        dfs(c);
        sz[x] += sz[c];
    }
}

int main(){
    int n,x,y;
    cin >>n >>x >>y;
    --x;
    --y;

    rep(i,n-1){
        int a,b;
        cin >>a >>b;
        --a;
        --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    par[x] = -1;
    dfs(x);

    int py=y;
    while(par[py]!=x) py = par[py];

    ll ans = (ll)n*(n-1);
    // 禁止パターン
    ans -= (n-sz[py])*sz[y];

    cout << ans << endl;
    return 0;
}
