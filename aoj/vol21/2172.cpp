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

const int N = 30;
const int dx[5]={1,-1,0,0,0};
const int dy[5]={0,0,1,-1,0};

int h,w;
string s[N];

bool IN(int y, int x){
    return 0<=y && y<h && 0<=x && x<w && s[y][x]!='#';
}

int dp[N][N][N][N];

using pi = pair<int,int>;
using P = pair<pi,pi>;

int main(){
    while(cin >>w >>h,w){
        rep(i,h) cin >>s[i];

        int qy,qx,ay,ax;
        rep(i,h)rep(j,w){
            if(s[i][j]=='Q'){
                qy = i;
                qx = j;
            }
            if(s[i][j]=='A'){
                ay = i;
                ax = j;
            }
        }

        memset(dp,-1,sizeof(dp));
        queue<P> que;

        // win
        rep(i,h)rep(j,w){
            if(s[i][j] != 'E') continue;
            rep(ii,h)rep(jj,w){
                int d = abs(i-ii) + abs(j-jj);
                if(d>0){
                    dp[i][j][ii][jj] = 1;
                    que.push({{i,j},{ii,jj}});
                }
            }
        }
        while(!que.empty()){
            P state = que.front();
            que.pop();
            pi queen = state.fi, army = state.se;
            // dbg(state);

            vector<P> check;
            rep(qd,5)rep(ad,5){
                int nqy = queen.fi + dy[qd];
                int nqx = queen.se + dx[qd];
                int nay = army.fi + dy[ad];
                int nax = army.se + dx[ad];
                if(!IN(nqy,nqx) || !IN(nay,nax) || dp[nqy][nqx][nay][nax]!=-1) continue;

                check.pb({{nqy,nqx},{nay,nax}});
            }

            for(const auto &ppp:check){
                pi nq = ppp.fi, na = ppp.se;

                int res = 0;
                rep(qd,5){
                    int nqy = nq.fi+dy[qd], nqx = nq.se+dx[qd];
                    if(!IN(nqy,nqx)) continue;

                    int tmp = 1;
                    rep(ad,5){
                        int nay = na.fi+dy[ad], nax = na.se+dx[ad];
                        if(!IN(nay,nax)) continue;
                        if(dp[nqy][nqx][nay][nax] != 1) tmp = 0;
                    }
                    if(tmp){
                        res = 1;
                        break;
                    }
                }

                if(res == 1){
                    dp[nq.fi][nq.se][na.fi][na.se] = 1;
                    que.push({nq,na});
                }
            }
        }

        // lose
        rep(i,h)rep(j,w){
            dp[i][j][i][j] = 0;
            que.push({{i,j},{i,j}});
        }
        while(!que.empty()){
            P state = que.front();
            que.pop();
            pi queen = state.fi, army = state.se;
            // dbg(state);

            vector<P> check;
            rep(qd,5)rep(ad,5){
                int nqy = queen.fi + dy[qd];
                int nqx = queen.se + dx[qd];
                int nay = army.fi + dy[ad];
                int nax = army.se + dx[ad];
                if(!IN(nqy,nqx) || !IN(nay,nax) || dp[nqy][nqx][nay][nax]!=-1) continue;

                check.pb({{nqy,nqx},{nay,nax}});
            }

            for(const auto &ppp:check){
                pi nq = ppp.fi, na = ppp.se;

                int res = 0;
                rep(qd,5){
                    int nqy = nq.fi+dy[qd], nqx = nq.se+dx[qd];
                    if(!IN(nqy,nqx)) continue;

                    int tmp = 1;
                    rep(ad,5){
                        int nay = na.fi+dy[ad], nax = na.se+dx[ad];
                        if(!IN(nay,nax)) continue;
                        if(dp[nqy][nqx][nay][nax] == 0){
                            tmp = 0;
                            break;
                        }
                    }

                    res |= tmp;
                }

                if(res == 0){
                    dp[nq.fi][nq.se][na.fi][na.se] = 0;
                    que.push({nq,na});
                }
            }
        }

        int res = dp[qy][qx][ay][ax];
        if(res == 0) printf("Army can catch Queen.\n");
        else if(res == 1) printf("Queen can escape.\n");
        else printf("Queen can not escape and Army can not catch Queen.\n");
    }
    return 0;
}
