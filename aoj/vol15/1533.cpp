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

struct State{
    int y,x,t,b;
};

const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
const int M = (1<<10)-1;

int h,w,n;
string s[10];

const int INF = 19191919;
int dp[10][10][10][1<<10];

bool IN(int y, int x){
    return 0<=y && y<h && 0<=x && x<w;
}

int main(){
    cin >>h >>w >>n;
    rep(i,h) cin >>s[i];

    int sy=0,sx=0;
    int by[5],bx[5];
    rep(i,h)rep(j,w){
        if(s[i][j] == 'S'){
            sy = i;
            sx = j;
        }
        if(islower(s[i][j])){
            int ID = s[i][j]-'a';
            by[ID] = i;
            bx[ID] = j;
        }
    }

    int sb = 0;
    int py = sy, px = sx;
    rep(i,5){
        int d = 0;
        while(d<4){
            int ny = py+dy[d], nx = px+dx[d];
            if(ny == by[i] && nx == bx[i]) break;
            ++d;
        }
        sb |= d<<(2*i);
        py = by[i];
        px = bx[i];
    }

    rep(i,10)rep(j,10)rep(k,10)rep(l,1<<10) dp[i][j][k][l] = INF;
    queue<State> que;
    dp[sy][sx][0][sb] = 0;
    que.push({sy,sx,0,sb});
    while(!que.empty()){
        State c = que.front();
        que.pop();

        int D = dp[c.y][c.x][c.t][c.b];
        // printf(" %d %d %d %d == %d\n", c.y, c.x, c.t, c.b,D);

        int tmask = c.b;
        py = c.y, px = c.x;
        by[0] = py;
        bx[0] = px;
        rep(i,4){
            int dir = tmask&3;
            tmask >>= 2;
            py += dy[dir];
            px += dx[dir];
            by[i+1] = py;
            bx[i+1] = px;
        }

        rep(i,4){
            int ny = c.y+dy[i], nx = c.x+dx[i];
            if(!IN(ny,nx)) continue;
            if(s[ny][nx] == '#') continue;

            bool body = false;
            rep(j,5)if(ny==by[j] && nx==bx[j]) body = true;
            if(body) continue;

            int nb = c.b;
            nb <<= 2;
            nb |= (i^2);
            nb &= M;

            int nt = c.t;
            if(s[ny][nx] == '0'+1+c.t) ++nt;

            if(dp[ny][nx][nt][nb] > D+1){
                dp[ny][nx][nt][nb] = D+1;
                que.push({ny,nx,nt,nb});
            }
        }
    }

    int ans = INF;
    rep(i,h)rep(j,w)rep(mask,1<<10) ans = min(ans, dp[i][j][n][mask]);
    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}
