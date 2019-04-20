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

const int N = 500000;
vector<pi> G[N];

inline pi E(int x, int y){
    return {min(x,y), max(x,y)};
}

int main(){
    int n;
    scanf(" %d", &n);

    map<ll,int> val2id;
    vector<ll> val;
    int V = 0;

    vector<ll> s(n),t(n);
    rep(i,n){
        scanf(" %lld %lld", &s[i], &t[i]);
        for(ll j:{s[i],t[i]}){
            if(!val2id.count(j)){
                val.pb(j);
                val2id[j] = V;
                ++V;
            }
        }

        int u = val2id[s[i]], v = val2id[t[i]];
        G[u].pb({v,i});
        G[v].pb({u,i});
    }

    ll ans = 0;
    vector<bool> vis(V);
    rep(i,V){
        if(vis[i]) continue;

        int C = 1;
        set<int> edges;
        vector<int> cc({i});
        queue<int> que({i});
        vis[i] = true;
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(pi e:G[v]){
                edges.insert(e.se);
                if(!vis[e.fi]){
                    ++C;
                    vis[e.fi] = true;
                    cc.pb(e.fi);
                    que.push(e.fi);
                }
            }
        }

        int esz = edges.size();
        // dbg(cc);dbg(esz);
        if(C-1 == esz){
            ll mx = 0;
            for(int idx:cc) mx = max(mx, val[idx]);

            for(int idx:cc){
                int deg = G[idx].size();
                if(val[idx] == mx) ans += val[idx]*deg;
                else ans += val[idx]*(deg-1);
            }
        }
        else{
            assert(C == esz);
            for(int idx:cc){
                int deg = G[idx].size();
                ans += val[idx]*(deg-1);
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
