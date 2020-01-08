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

using pi = pair<int,int>;

const int INF = 10101010;
const pi I = {INF,INF};

pi dp[100][10][10][3];

struct State{int z,y,x,p;};

int main(){
    int n;
    cin >>n;

    vector<pi> pos(n*n);
    rep(i,n)rep(j,n){
        int a;
        cin >>a;
        pos[a-1] = {i,j};
    }

    auto IN = [&](int y, int x){
        return 0<=y && y<n && 0<=x && x<n;
    };

    queue<State> que;
    rep(i,100)rep(j,10)rep(k,10)rep(l,3) dp[i][j][k][l] = I;
    rep(i,3){
        dp[0][pos[0].fi][pos[0].se][i] = {0,0};
        que.push({0, pos[0].fi, pos[0].se, i});
    }

    auto handle = [&](int ny, int nx, State s, pi nv){
        if(!IN(ny,nx)) return;

        State ns = s;
        ns.y = ny;
        ns.x = nx;
        if(pos[ns.z+1] == pi(ny,nx)) ++ns.z;

        if(dp[ns.z][ns.y][ns.x][ns.p] > nv){
            dp[ns.z][ns.y][ns.x][ns.p] = nv;
            que.push(ns);
        }
    };

    while(!que.empty()){
        State s = que.front();
        que.pop();
        if(s.z == n*n-1) continue;

        pi val = dp[s.z][s.y][s.x][s.p];
        // printf(" (%d %d %d %d) : ",s.z,s.y,s.x,s.p); dbg(val);

        // change
        rep(i,3){
            State ns = s;
            ns.p = i;

            pi nv = {val.fi+1, val.se+1};
            if(dp[ns.z][ns.y][ns.x][ns.p] > nv){
                dp[ns.z][ns.y][ns.x][ns.p] = nv;
                que.push(ns);
            }
        }

        // move
        pi nv = {val.fi+1, val.se};

        if(s.p==0){
            // knight
            int a=1, b=2;
            rep(loop,2){
                for(int ga:{-1,1})for(int gb:{-1,1}){
                    int dy = a*ga, dx = b*gb;
                    int ny = s.y+dy, nx = s.x+dx;
                    handle(ny,nx,s,nv);
                }
                swap(a,b);
            }
        }
        else if(s.p==1){
            // bishop
            for(int dy:{-1,1})for(int dx:{-1,1})rep(L,n){
                int ny = s.y+dy*L, nx = s.x+dx*L;
                handle(ny,nx,s,nv);
            }
        }
        else{
            // rook
            for(int dy=-n; dy<=n; ++dy){
                int ny = s.y+dy, nx = s.x;
                handle(ny,nx,s,nv);
            }
            for(int dx=-n; dx<=n; ++dx){
                int ny = s.y, nx = s.x+dx;
                handle(ny,nx,s,nv);
            }
        }
    }

    pi ans = I;
    pi goal = pos[n*n-1];
    rep(i,3) ans = min(ans, dp[n*n-1][goal.fi][goal.se][i]);
    cout << ans.fi << " " << ans.se << "\n";
    return 0;
}
