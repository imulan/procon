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
    int y,x,d;
};

const int N = 1000;
const int INF = 19191919;

const int dx[4]={0,1,0,-1}, dy[4]={-1,0,1,0};

int d[N][N][4];
vector<int> dir[4];



int main(){
    int h,w,n;
    while(cin >>h >>w >>n,h){
        // initialize
        rep(i,N)rep(j,N)rep(k,4) d[i][j][k]=INF;
        rep(i,4) dir[i].clear();

        string c;
        cin >>c;
        vector<string> f(h);
        rep(i,h) cin >>f[i];

        int nd = 0;
        rep(i,n){
            dir[nd].pb(i);
            if(c[i]=='L') nd = (nd+3)%4;
            else nd = (nd+1)%4;
        }
        dir[nd].pb(n);
        rep(i,4) dir[i].pb(INF);

        int sy,sx,gy,gx;
        rep(i,h)rep(j,w){
            if(f[i][j]=='S'){
                sy = i;
                sx = j;
            }
            if(f[i][j]=='G'){
                gy = i;
                gx = j;
            }
        }

        auto IN = [&](int y, int x){ return 0<=y && y<h && 0<=x && x<w; };

        queue<State> que;
        que.push({sy,sx,0});
        d[sy][sx][0] = 0;
        while(!que.empty()){
            State now = que.front();
            que.pop();

            if(now.y==gy && now.x==gx) break;

            int D = d[now.y][now.x][now.d];

            // 今向いてる方に進む
            int ny = now.y+dy[now.d], nx = now.x+dx[now.d];
            if(IN(ny,nx) && f[ny][nx]!='#'){
                if(d[ny][nx][now.d] > D){
                    d[ny][nx][now.d] = D;
                    que.push({ny,nx,now.d});
                }
            }

            rep(i,4)if(i!=now.d){
                int dd = *lower_bound(all(dir[i]), D);
                if(d[now.y][now.x][i] > dd){
                    d[now.y][now.x][i] = dd;
                    que.push({now.y,now.x,i});
                }
            }
        }

        int ans = INF;
        rep(i,4) ans = min(ans, d[gy][gx][i]);
        cout << (ans<INF?"Yes":"No") << endl;
    }
    return 0;
}
