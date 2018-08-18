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

using vi = vector<int>;

const int N = 1000000;
vi G[N];

const int L = 21;

int par[L][N];
void dfs(int x){
    for(int c:G[x])if(c!=par[0][x]){
        par[0][c] = x;
        dfs(c);
    }
}

bool rem[N];
// xから既に残すことが確定している頂点までの距離
int calc_dist(int x){
    int ret = 0;
    for(int i=L-1; i>=0; --i){
        if(par[i][x]==-1) continue;

        if( !rem[par[i][x]] ){
            x = par[i][x];
            ret += 1<<i;
        }
    }
    return ret+1;
}

int main(){
    int n,k;
    scanf(" %d %d", &n, &k);

    rep(i,n-1){
        int a,b;
        scanf(" %d %d", &a, &b);
        --a;
        --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    int root = n-1;
    memset(par,-1,sizeof(par));
    dfs(root);

    for(int i=1; i<L; ++i){
        rep(j,n){
            if(par[i-1][j]!=-1) par[i][j] = par[i-1][par[i-1][j]];
        }
    }

    rem[root] = true;
    // iを残していいかcheck
    int num = 1;
    for(int i=n-2; i>=0; --i){
        if(rem[i]) continue;
        int d = calc_dist(i);

        if(num+d <= n-k){
            // 残す
            int tmp = i;
            while(!rem[tmp]){
                rem[tmp] = true;
                ++num;
                tmp = par[0][tmp];
            }
        }
    }

    vi ans;
    rep(i,n)if(!rem[i]) ans.pb(i+1);
    assert(ans.size()==k);
    rep(i,k) printf("%d%c", ans[i], " \n"[i==k-1]);
    return 0;
}
