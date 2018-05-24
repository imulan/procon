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

const int dx[2]={1,0}, dy[2]={0,1};
const int ALP = 26;

const int N = 50;
bool reach[N][N][N][N];
int dp[N][N][N][N];

int main(){
    int h,w;
    while(cin >>h >>w,h){
        rep(i,N)rep(j,N)rep(k,N)rep(l,N){
            dp[i][j][k][l] = 0;
            reach[i][j][k][l] = false;
        }

        vector<string> c(h);
        rep(i,h) cin >>c[i];

        vector<pi> s[ALP],t[ALP];
        rep(i,h)rep(j,w){
            char f = c[i][j];
            if(islower(f)) s[f-'a'].pb({i,j});
            else if(isupper(f)) t[f-'A'].pb({i,j});
        }

        auto IN = [&](int y, int x){
            return 0<=y && y<h && 0<=x && x<w;
        };

        auto BFS = [&](pi start){
            vector<vector<bool>> vis(h,vector<bool>(w));
            vis[start.fi][start.se] = true;
            queue<pi> que;
            que.push(start);
            while(!que.empty()){
                pi now = que.front();
                que.pop();
                rep(d,2){
                    int ny = now.fi+dy[d], nx = now.se+dx[d];
                    if(IN(ny,nx) && c[ny][nx]!='#' && !vis[ny][nx]){
                        vis[ny][nx] = true;
                        que.push({ny,nx});
                    }
                }
            }
            return vis;
        };

        rep(i,h)rep(j,w){
            vector<vector<bool>> vis = BFS({i,j});
            rep(k,h)rep(l,w) reach[i][j][k][l] = vis[k][l];
        }

        if(!reach[0][0][h-1][w-1]){
            cout << -1 << endl;
            continue;
        }

        for(int y1=h-1; y1>=0; --y1)for(int x1=w-1; x1>=0; --x1){
            char f = c[y1][x1];
            if(f == '#') continue;
            for(int y2=y1; y2<h; ++y2)for(int x2=x1; x2<w; ++x2){
                if(c[y2][x2] == '#') continue;
                if(!reach[y1][x1][y2][x2]) continue;

                rep(d,2){
                    int ny = y1+dy[d], nx = x1+dx[d];
                    if(IN(ny,nx) && c[ny][nx]!='#' && reach[ny][nx][y2][x2]){
                        dp[y1][x1][y2][x2] = max(dp[y1][x1][y2][x2], dp[ny][nx][y2][x2]);
                    }
                }

                if(!islower(f)) continue;

                // use jewel
                int idx = f-'a';
                for(pi p:t[idx])if(y1<=p.fi && p.fi<=y2 && x1<=p.se && p.se<=x2){
                    if(abs(y1-p.fi)+abs(x1-p.se)==1){
                        if(reach[p.fi][p.se][y2][x2]) dp[y1][x1][y2][x2] = max(dp[y1][x1][y2][x2], dp[p.fi][p.se][y2][x2]+1);
                    }
                    else{
                        rep(pd,2)rep(qd,2){
                            int py = y1+dy[pd], px = x1+dx[pd];
                            int qy = p.fi-dy[qd], qx = p.se-dx[qd];
                            if(IN(py,px) && IN(qy,qx) && c[py][px]!='#' && c[qy][qx]!='#' && reach[py][px][qy][qx] && reach[qy][qx][y2][x2]){
                                dp[y1][x1][y2][x2] = max(dp[y1][x1][y2][x2], dp[py][px][qy][qx]+dp[p.fi][p.se][y2][x2]+1);
                            }
                        }
                    }
                }
            }
        }

        // rep(i,h)rep(j,w)for(int i2=i; i2<h;++i2)for(int j2=j;j2<w;++j2){
        //     printf("dp[%d][%d][%d][%d] = %d\n", i,j,i2,j2, dp[i][j][i2][j2]);
        // }
        cout << dp[0][0][h-1][w-1] << endl;
    }
    return 0;
}
