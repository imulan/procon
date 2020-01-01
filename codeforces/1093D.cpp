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

const int INF = 1010101;
const ll mod = 998244353;

ll solve(){
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<vector<int>> G(n);
    rep(i,m){
        int u,v;
        scanf(" %d %d", &u, &v);
        --u;
        --v;
        G[u].pb(v);
        G[v].pb(u);
    }

    ll ans = 1;
    vector<int> d(n,INF);
    rep(s,n)if(d[s] == INF){
        d[s] = 0;
        vector<int> cc({s});
        queue<int> que({s});
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(int e:G[v])if(d[e] > d[v]+1){
                d[e] = d[v]+1;
                cc.pb(e);
                que.push(e);
            }
        }

        for(int i:cc)for(int j:G[i]){
            if(abs(d[i]-d[j])%2 == 0) return 0;
        }

        int ct[2]={};
        for(int i:cc) ++ct[d[i]%2];

        ll t = 0;
        rep(i,2){
            ll a = 1;
            rep(j,ct[i]) (a *= 2) %= mod;
            t += a;
        }

        (ans *= t) %= mod;
    }
    return ans;
}

int main(){
    int t;
    scanf(" %d", &t);
    while(t--) printf("%lld\n", solve());
    return 0;
}
