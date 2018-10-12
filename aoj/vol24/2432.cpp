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

const int LK = 20;
const int N = 150;

using pi = pair<int,int>;
using P = pair<pi,pi>;
using R = pair<int,pi>;

int a[LK][N][N];
// 復元用
P r[7][N][N];

const int INF = 19191919;
int dp[LK+1][N][2];
vector<R> dr[LK+1][N][2];

int main(){
    int V,E,K;
    scanf(" %d %d %d", &V, &E, &K);

    memset(a,-1,sizeof(a));

    rep(i,E){
        int from,to,c;
        scanf(" %d %d %d", &from, &to, &c);
        a[0][from][to] = max(a[0][from][to], c);
    }

    rep(i,V)rep(j,V){
        if(a[0][i][j]>0) r[0][i][j] = {{i,i},{j,j}};
    }

    for(int i=1; i<LK; ++i){
        rep(from,V)rep(to,V){
            rep(ch,V){
                int vf = a[i-1][from][ch];
                int vt = a[i-1][ch][to];
                if(vf == -1 || vt == -1) continue;

                int val = vf+vt;
                if(val > a[i][from][to]){
                    a[i][from][to] = val;
                    if(i<7) r[i][from][to] = {{from,ch},{ch,to}};
                }
            }
        }
    }

    vector<int> route;
    int ng=0, ok=K+1;
    while(ok-ng>1){
        int mid = (ng+ok)/2;

        rep(i,LK+1)rep(j,N)rep(k,2){
            dp[i][j][k] = -INF;
            dr[i][j][k].clear();
        }
        rep(i,V) dp[0][i][1] = 0;

        for(int b=LK-1; b>=0; --b){
            int i = LK-1 - b;
            int bb = mid>>b&1;

            rep(j,V)rep(k,2)if(dp[i][j][k]>=0){
                // printf(" %d %d %d  %d\n",i,j,k,dp[i][j][k]);

                // not move
                if(bb == 0){
                    if(dp[i+1][j][k] < dp[i][j][k]){
                        dp[i+1][j][k] = dp[i][j][k];
                        if(mid <= 100){
                            dr[i+1][j][k] = dr[i][j][k];
                        }
                    }
                }
                else{
                    if(dp[i+1][j][0] < dp[i][j][k]){
                        dp[i+1][j][0] = dp[i][j][k];
                        if(mid <= 100){
                            dr[i+1][j][0] = dr[i][j][k];
                        }
                    }
                }

                // move
                if(k==1 && bb==0) continue;
                rep(nx,V)if(a[b][j][nx]>0){
                    if(dp[i+1][nx][k] < dp[i][j][k]+a[b][j][nx]){
                        dp[i+1][nx][k] = dp[i][j][k]+a[b][j][nx];
                        if(mid <= 100){
                            dr[i+1][nx][k] = dr[i][j][k];
                            dr[i+1][nx][k].pb({b,{j,nx}});
                        }
                    }
                }
            }
        }

        int ans = -INF;
        rep(i,V)rep(j,2) ans = max(ans,dp[LK][i][j]);
        // dbg(mid); dbg(ans);

        // 復元
        vector<int> tmp;
        if(mid <= 100){
            rep(i,V)rep(j,2){
                if(ans == dp[LK][i][j]){
                    // printf(" --- %d %d\n",i,j);
                    tmp.clear();
                    bool is_first = true;
                    for(const auto dd:dr[LK][i][j]){
                        if(is_first){
                            tmp.pb(dd.se.fi);
                            is_first = false;
                        }

                        queue<R> que;
                        que.push(dd);
                        // dbg(dd);
                        while(!que.empty()){
                            R now = que.front();
                            que.pop();
                            // dbg(now);
                            int u = now.se.fi, v = now.se.se;
                            if(now.fi == 0) tmp.pb(v);
                            else{
                                pi tl = r[now.fi][u][v].fi;
                                que.push({now.fi-1,tl});
                                pi tr = r[now.fi][u][v].se;
                                que.push({now.fi-1,tr});
                            }
                        }
                    }
                }
            }
            // dbg(tmp);
        }

        if(ans >= K){
            ok = mid;
            route = tmp;
        }
        else ng = mid;
    }

    if(ok == K+1) printf("-1\n");
    else{
        printf("%d\n", ok);
        if(ok <= 100){
            assert(route.size() == ok+1);
            rep(i,ok+1) printf("%d%c", route[i], " \n"[i==ok]);
        }
    }
    return 0;
}
