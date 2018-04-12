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

const int dx[4] = {1,0,-1,0}, dy[4] = {0,-1,0,1};

const int INF = 123;
int d[100][100][4][11];

struct State{
    int y,x,dir,p;
};

int main(){
    int h,w,a;
    cin >>h >>w >>a;
    vector<string> s(h);
    rep(i,h) cin >>s[i];

    pair<int,int> start,goal;
    rep(i,h)rep(j,w){
        if(s[i][j] == 'S') start = {i,j};
        if(s[i][j] == 'G') goal = {i,j};
    }

    auto ok = [&](int y, int x){
        return (0<=y && y<h && 0<=x && x<w && s[y][x]!='#');
    };

    rep(i,100)rep(j,100)rep(k,4)rep(l,11) d[i][j][k][l] = INF;

    queue<State> que;
    if(ok(start.fi+1, start.se)){
        d[start.fi+1][start.se][3][0] = 0;
        que.push({start.fi+1, start.se, 3, 0});
    }

    while(!que.empty()){
        State c = que.front();
        que.pop();

        // printf("( %d %d %d %d)\n", c.y,c.x,c.dir,c.p);

        int D = d[c.y][c.x][c.dir][c.p];
        State t;

        // 鏡を使わず直進
        t = c;
        t.y += dy[t.dir];
        t.x += dx[t.dir];
        if(ok(t.y,t.x) && d[t.y][t.x][t.dir][t.p] > D){
            if(!(t.y==start.fi && t.x==start.se && t.dir==1)){
                d[t.y][t.x][t.dir][t.p] = D;
                que.push(t);
            }
        }

        // type-P mirror
        if(t.p<a && s[c.y][c.x]=='.'){
            t = c;
            t.dir = 3-t.dir;
            t.y += dy[t.dir];
            t.x += dx[t.dir];
            ++t.p;
            if(ok(t.y,t.x) && d[t.y][t.x][t.dir][t.p] > D){
                if(!(t.y==start.fi && t.x==start.se && t.dir==1)){
                    d[t.y][t.x][t.dir][t.p] = D;
                    que.push(t);
                }
            }
        }

        // type-Q mirror
        if(D<a && s[c.y][c.x]=='.'){
            t = c;
            t.dir ^= 1;
            t.y += dy[t.dir];
            t.x += dx[t.dir];
            if(ok(t.y,t.x) && d[t.y][t.x][t.dir][t.p] > D+1){
                if(!(t.y==start.fi && t.x==start.se && t.dir==1)){
                    d[t.y][t.x][t.dir][t.p] = D+1;
                    que.push(t);
                }
            }
        }
    }

    int ans = INF;
    rep(i,4)rep(j,a+1) ans = min(ans, d[goal.fi][goal.se][i][j]+j);
    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}
