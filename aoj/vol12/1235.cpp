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

const int INF = 191919;

int main(){
    int n,c;
    while(cin >>n >>c,n){
        vector<vector<int>> a(n,vector<int>(n));
        rep(i,n)rep(j,i+1) cin >>a[i][j];

        map<pi,vector<pi>> G;
        auto ADD = [&](pi u, pi v){
            G[u].pb(v);
            G[v].pb(u);
        };

        rep(i,n){
            rep(j,i+1){
                pi u(i,j);

                if(i<n-1){
                    rep(k,2){
                        pi v(i+1,j+k);
                        ADD(u,v);
                    }
                }

                if(j<i){
                    pi v(i,j+1);
                    ADD(u,v);
                }
            }
        }

        auto CHECK = [&](){
            set<pi> vis;
            queue<pi> que;
            rep(i,n)rep(j,i+1){
                if(a[i][j]==0){
                    vis.insert({i,j});
                    for(const auto &p:G[{i,j}]){
                        vis.insert(p);
                        que.push(p);
                    }
                }
            }
            while(!que.empty()){
                pi p = que.front();
                que.pop();
                for(const auto &nx:G[p]){
                    if(!vis.count(nx) && a[nx.fi][nx.se]==a[p.fi][p.se]){
                        vis.insert(nx);
                        que.push(nx);
                    }
                }
            }

            int ret = 0;
            rep(i,n)rep(j,i+1){
                if(!vis.count({i,j})){
                    if(a[i][j]==c) --ret;
                    else ++ret;
                }
            }

            return ret;
        };

        int ans = -INF;
        rep(i,n)rep(j,i+1){
            if(a[i][j] != 0) continue;
            a[i][j] = c;
            ans = max(ans, CHECK());
            a[i][j] = 0;
        }
        cout << ans << endl;
    }
    return 0;
}
