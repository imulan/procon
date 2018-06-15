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

const int N = 606;
int dp[N][N];

int main(){
    int n,T,L;
    while(cin >>n >>T >>L){
        if(n==0 && T==0 && L==0) break;

        int V = T+L;
        vector<vector<int>> G(2*V);

        rep(i,n){
            int x,y;
            string s;
            cin >>x >>y >>s;
            --x;
            --y;
            if(s=="yes"){
                G[x].pb(y);
                G[y].pb(x);
                G[V+x].pb(V+y);
                G[V+y].pb(V+x);
            }
            else{
                G[x].pb(V+y);
                G[V+y].pb(x);
                G[V+x].pb(y);
                G[y].pb(V+x);
            }
        }

        vector<bool> vis(2*V);
        vector<vector<int>> cc;
        rep(i,V){
            if(!vis[i]){
                vector<int> comp;
                queue<int> que;
                que.push(i);
                comp.pb(i);
                vis[i] = true;
                vis[V+i] = true;
                while(!que.empty()){
                    int now = que.front();
                    que.pop();
                    for(int e:G[now]){
                        if(!vis[e]){
                            que.push(e);
                            comp.pb(e);
                            vis[e] = true;
                            if(e>=V) vis[e-V] = true;
                            else vis[e+V] = true;
                        }
                    }
                }

                cc.pb(comp);
            }
        }

        int C = cc.size();

        vector<pi> p(C);
        rep(i,C){
            vector<int> v = cc[i];
            int t=0,l=0;
            for(int j:v){
                if(j<V) ++t;
                else ++l;
            }
            p[i] = {t,l};
        }

        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        rep(i,C){
            rep(j,N){
                if(j+p[i].fi<N){
                    dp[i+1][j+p[i].fi] += dp[i][j];
                    if(dp[i+1][j+p[i].fi]>1) dp[i+1][j+p[i].fi] = 2;
                }
                if(j+p[i].se<N){
                    dp[i+1][j+p[i].se] += dp[i][j];
                    if(dp[i+1][j+p[i].se]>1) dp[i+1][j+p[i].se] = 2;
                }
            }
        }

        if(dp[C][T]!=1){
            cout << "no" << endl;
        }
        else{
            int nt = T;
            set<int> ans;
            for(int i=C-1; i>=0; --i){
                if(nt-p[i].fi>=0){
                    int j = nt-p[i].fi;
                    if(dp[i][j]==1){
                        for(int v:cc[i])if(v<V) ans.insert(v);
                        nt = j;
                        continue;
                    }
                }
                if(nt-p[i].se>=0){
                    int j = nt-p[i].se;
                    if(dp[i][j]==1){
                        for(int v:cc[i])if(v>=V) ans.insert(v-V);
                        nt = j;
                        continue;
                    }
                }
                assert(false);
            }

            assert(ans.size()==T);
            for(int i:ans) cout << i+1 << endl;
            cout << "end" << endl;
        }
    }
    return 0;
}
