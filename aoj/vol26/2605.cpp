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

struct edge{ int to,cost; };

const int N = 2002;
const ll INF = LLONG_MAX/3;

vector<edge> G[N];
ll dp[N];
ll val[N][2][2], nv[N][2][2];

int main(){
    int n,m,K;
    cin >>n >>m >>K;

    rep(i,m){
        int a,b,c;
        cin >>a >>b >>c;
        --a; --b;
        G[a].pb({b,c});
        G[b].pb({a,c});
    }

    fill(dp,dp+N,-INF);
    dp[0] = 0;

    vector<bool> vis(n);
    rep(vv,n)if(!vis[vv]){
        // connected component
        vector<int> cc;
        queue<int> que;
        que.push(vv);
        vis[vv] = true;
        cc.pb(vv);
        while(!que.empty()){
            int now = que.front();
            que.pop();
            for(const auto &e:G[now]){
                if(!vis[e.to]){
                    que.push(e.to);
                    vis[e.to] = true;
                    cc.pb(e.to);
                }
            }
        }

        int C = cc.size();
        if(C == 1){
            for(int i=N-2; i>=0; --i) dp[i+1] = max(dp[i+1], dp[i]);
            continue;
        }

        // line or circle
        bool line = false;
        int now = cc[0], prev = -1;
        rep(i,C){
            int v = cc[i];
            if(G[v].size()==1){
                line = true;
                now = v;
            }
        }

        // calc
        rep(i,C+1)rep(j,2)rep(k,2){
            val[i][j][k] = -INF;
        }
        val[0][0][0] = 0;
        val[1][1][1] = 0;

        int start = now;
        rep(i,C-1){
            int nx = -1;
            int w;
            for(const auto &e:G[now])if(prev != e.to){
                nx = e.to;
                w = e.cost;
            }
            prev = now;
            now = nx;

            // printf(" i= %d: (%d - %d) w %d\n",i,prev,now,w);

            rep(j,C+1)rep(k,2)rep(l,2) nv[j][k][l] = -INF;

            for(int j=N-1; j>=0; --j)rep(k,2)rep(l,2){
                // select
                if(j+1<N && !(k==1 && w==0)){
                    nv[j+1][1][l] = max(nv[j+1][1][l], val[j][k][l]+(k==1?w:0));
                }

                // not select
                nv[j][0][l] = max(nv[j][0][l], val[j][k][l]);
            }

            rep(j,C+1)rep(k,2)rep(l,2) val[j][k][l] = nv[j][k][l];
        }

        if(!line){
            int nx = -1;
            int w;
            for(const auto &e:G[now])if(prev != e.to){
                nx = e.to;
                w = e.cost;
            }
            assert(start == nx);

            if(w==0) rep(i,N) val[i][1][1] = -INF;
            else rep(i,N) val[i][1][1] += w;
        }

        for(int i=n; i>=0; --i){
            rep(j,C+1){
                ll add = -INF;
                rep(k,2)rep(l,2) add = max(add, val[j][k][l]);

                if(i+j<N) dp[i+j] = max(dp[i+j], dp[i]+add);
            }
        }
    }

    ll ans = dp[K];
    if(ans < -22222222) cout << "Impossible" << endl;
    else cout << ans << endl;
    return 0;
}
