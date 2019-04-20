#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll mod = 1e9+7;

ll mod_pow(ll x, ll n){
    ll ret = 1;
    while(n){
        if(n&1) (ret*=x)%=mod;
        (x*=x)%=mod;
        n >>= 1;
    }
    return ret;
}

ll mod_inv(ll x){
    return mod_pow(x,mod-2);
}

int main(){
    int n,m,c;
    cin >>n >>m >>c;

    ll one_side = mod_pow(c,n*n);

    vector<int> p(m);
    rep(i,m) p[i] = i;

    ll ans = 0;
    rep(i,m){
        vector<int> q(m);
        rep(j,m) q[j]=(j+i)%m;

        vector<vector<int>> G(m);
        rep(j,m){
            G[p[j]].pb(q[j]);
            G[q[j]].pb(p[j]);
        }

        int cc=0;
        vector<bool> vis(m);
        rep(j,m)if(!vis[j]){
            ++cc;
            vis[j]=true;
            queue<int> que;
            que.push(j);
            while(!que.empty()){
                int v = que.front();
                que.pop();
                for(int e:G[v])if(!vis[e]){
                    vis[e] = true;
                    que.push(e);
                }
            }
        }

        ans += mod_pow(one_side, cc);
        ans %= mod;
    }

    ans *= mod_inv(m);
    ans %= mod;
    cout << ans << endl;
    return 0;
}