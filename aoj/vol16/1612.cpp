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

const ll INF = LLONG_MAX/3;

struct edge{
    int to;
    ll cost;
};

const int N = 2000;
vector<edge> G[N];

int main(){
    int n,k,s;
    while(scanf(" %d %d %d", &n, &k, &s),n){
        rep(i,N) G[i].clear();

        vector<int> x(n),y(n),z(n);
        rep(i,n) scanf(" %d %d %d", &x[i], &y[i], &z[i]);

        if(k==1){
            printf("%d\n", 6*s*s);
            continue;
        }

        rep(i,n)rep(j,i){
            if(abs(x[i]-x[j])<s && abs(y[i]-y[j])<s && abs(z[i]-z[j])<s){
                ll X = min(x[i],x[j])+s - max(x[i],x[j]);
                ll Y = min(y[i],y[j])+s - max(y[i],y[j]);
                ll Z = min(z[i],z[j])+s - max(z[i],z[j]);

                ll w = 2*(X*Y+Y*Z+Z*X);
                G[i].pb({j,w});
                G[j].pb({i,w});
            }
        }

        rep(i,n) assert(G[i].size()<=2);

        vector<bool> vis(n);
        ll ans = INF;
        rep(cand,n){
            if(vis[cand]) continue;
            vis[cand] = true;

            queue<int> que;
            vector<int> cc;
            que.push(cand);
            cc.pb(cand);
            while(!que.empty()){
                int now = que.front();
                que.pop();
                for(const auto &e:G[now]){
                    if(!vis[e.to]){
                        vis[e.to] = true;
                        que.push(e.to);
                        cc.pb(e.to);
                    }
                }
            }

            int C = cc.size();
            if(C<k) continue;

            bool line = false;
            int now = cc[0];
            int prev = -1;
            for(int v:cc){
                if(G[v].size()==1){
                    line = true;
                    now = v;
                    break;
                }
            }

            vector<ll> w;
            int start = now;
            while(1){
                bool out = true;
                for(const auto &e:G[now]){
                    if(e.to != prev){
                        w.pb(e.cost);
                        if(e.to == start){
                            out = true;
                            break;
                        }
                        prev = now;
                        now = e.to;
                        out = false;
                        break;
                    }
                }
                if(out) break;
            }

            int W = w.size();
            ll base = (ll)6*s*s*k;
            if(line){
                rep(i,W-k+2){
                    ll a = 0;
                    rep(j,k-1) a += w[i+j];
                    ans = min(ans, base - a);
                }
            }
            else{
                if(C == k){
                    ll a = 0;
                    rep(i,W) a += w[i];
                    ans = min(ans, base - a);
                }
                else{
                    rep(i,W){
                        ll a = 0;
                        rep(j,k-1) a += w[(i+j)%W];
                        ans = min(ans, base - a);
                    }
                }
            }
        }

        if(ans == INF) ans = -1;
        printf("%lld\n", ans);
    }
    return 0;
}
