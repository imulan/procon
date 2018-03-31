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

struct State{
    // (y,x), floor f, bit b
    int y,x,f,b;
};

inline int switch_num(char c){
    if('a'<=c && c<='j') return c-'a';
    if('A'<=c && c<='J') return c-'A';
    return -1;
}

const int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

const int INF = 19191919;
const int N = 50, M = 1<<10;
int d[N][N][2][M];

int main(){
    int w,h;
    cin >>w >>h;

    vector<string> m(h);
    rep(i,h) cin >>m[i];

    int s;
    cin >>s;
    vector<vector<string>> ms(s);
    rep(i,s){
        ms[i] = vector<string>(h);
        rep(j,h) cin >>ms[i][j];
    }

    rep(i,N)rep(j,N)rep(k,2)rep(l,M) d[i][j][k][l] = INF;

    pi start, goal;
    rep(i,h)rep(j,w){
        if(m[i][j] == '%') start = {i,j};
        if(m[i][j] == '&') goal = {i,j};
    }

    auto IN = [&](int y, int x){ return 0<=y && y<h && 0<=x && x<w; };
    auto FLOOR = [&](int y, int x, int bit){
        int ret = 0;
        if(m[y][x]=='^' || ('A'<=m[y][x] && m[y][x]<='J')) ret = 1;
        rep(i,s)if(bit>>i&1){
            if(ms[i][y][x]=='*') ret = !ret;
        }
        return ret;
    };

    queue<State> que;
    d[start.fi][start.se][0][0] = 0;
    que.push({start.fi, start.se, 0, 0});
    while(!que.empty()){
        State c = que.front();
        que.pop();

        // move another floor
        if(m[c.y][c.x]=='|'){
            State nc(c);
            nc.f = !nc.f;
            if(d[nc.y][nc.x][nc.f][nc.b] > d[c.y][c.x][c.f][c.b]+1){
                d[nc.y][nc.x][nc.f][nc.b] = d[c.y][c.x][c.f][c.b]+1;
                que.push({nc});
            }
        }

        // operate switch
        int sn = switch_num(m[c.y][c.x]);
        if(sn!=-1){
            State nc(c);
            nc.b ^= (1<<switch_num(m[c.y][c.x]));
            if(ms[sn][c.y][c.x] == '*') nc.f = !nc.f;

            if(d[nc.y][nc.x][nc.f][nc.b] > d[c.y][c.x][c.f][c.b]+1){
                d[nc.y][nc.x][nc.f][nc.b] = d[c.y][c.x][c.f][c.b]+1;
                que.push({nc});
            }
        }

        // move adjacent
        rep(i,4){
            State nc(c);
            nc.y += dy[i];
            nc.x += dx[i];
            if(!IN(nc.y, nc.x) || m[nc.y][nc.x]=='#') continue;

            if(m[nc.y][nc.x]=='|' || nc.f==FLOOR(nc.y,nc.x,nc.b)){
                if(d[nc.y][nc.x][nc.f][nc.b] > d[c.y][c.x][c.f][c.b]+1){
                    d[nc.y][nc.x][nc.f][nc.b] = d[c.y][c.x][c.f][c.b]+1;
                    que.push({nc});
                }
            }
        }
    }

    int ans = INF;
    rep(i,2)rep(j,1<<s) ans = min(ans, d[goal.fi][goal.se][i][j]);
    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}
