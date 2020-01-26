#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

using pi = pair<int,int>;

int main(){
    int n;
    cin >>n;

    vector<vector<int>> G(n);
    map<pi,int> e2id;
    rep(i,n-1){
        int a,b;
        cin >>a >>b;
        --a;
        --b;
        e2id[{a,b}] = i;
        e2id[{b,a}] = i;
        G[a].pb(b);
        G[b].pb(a);
    }

    vector<int> par;
    auto BFS = [&](int root){
        par = vector<int>(n,-1);
        vector<bool> vis(n);

        vis[root] = true;
        queue<int> que({root});
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(int e:G[v])if(!vis[e]){
                vis[e] = true;
                que.push(e);
                par[e] = v;
            }
        }
    };

    int m;
    cin >>m;

    vector<vector<bool>> c(m, vector<bool>(n-1));
    rep(i,m){
        int a,b;
        cin >>a >>b;
        --a;
        --b;

        BFS(a);
        int t = b;
        while(par[t]!=-1){
            int p = par[t];
            int idx = e2id[{t,p}];
            c[i][idx] = true;
            t = p;
        }
    }

    vector<ll> dp(1<<m);
    dp[0] = 1;
    rep(i,n-1){
        vector<ll> nx(1<<m);

        int bb = 0;
        rep(j,m)if(c[j][i]) bb |= (1<<j);

        // black
        rep(mask,1<<m) nx[mask|bb] += dp[mask];
        // white
        rep(mask,1<<m) nx[mask] += dp[mask];

        swap(dp,nx);
    }
    cout << dp[(1<<m)-1] << "\n";
    return 0;
}
