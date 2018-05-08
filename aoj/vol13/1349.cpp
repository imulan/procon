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

// ENWS
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};

int cv(char c){
    if(c=='E') return 0;
    if(c=='N') return 1;
    if(c=='W') return 2;
    if(c=='S') return 3;
}

const int N = 52;
bool road[N][N][4]={};
bool dp[N][N][4];
bool nxt[N][N][4];

const int T = 1010;
int md[T];

int main(){
    int n,x0,y0,t;
    cin >>n >>x0 >>y0 >>t;

    rep(i,n){
        int ax,ay,bx,by;
        cin >>ax >>ay >>bx >>by;

        if(ax==bx){
            int x = ax;
            int ly = min(ay,by), ry = max(ay,by);
            road[ly][x][1] = true;
            for(int y=ly+1; y<ry; ++y) road[y][x][1] = road[y][x][3] = true;
            road[ry][x][3] = true;
        }
        else{
            assert(ay==by);
            int y = ay;
            int lx = min(ax,bx), rx = max(ax,bx);
            road[y][lx][0] = true;
            for(int x=lx+1; x<rx; ++x) road[y][x][0] = road[y][x][2] = true;
            road[y][rx][2] = true;
        }
    }

    int d_sum = 0;
    memset(md,-1,sizeof(md));
    rep(i,t){
        int d;
        char c;
        cin >>d >>c;

        d_sum += d;
        md[d_sum] = cv(c);
    }

    rep(d,4) dp[y0][x0][d] = road[y0][x0][d];

    for(int i=1; i<=d_sum; ++i){

        rep(y,N)rep(x,N)rep(d,4)if(dp[y][x][d]){
            int ny = y+dy[d], nx = x+dx[d];
            for(int j=-1; j<=1; ++j){
                int nd = (d+j+4)%4;
                if(road[ny][nx][nd]){
                    if(md[i]==-1 || (d==md[i] || nd==md[i])) nxt[ny][nx][nd] = true;
                }
            }
        }

        rep(y,N)rep(x,N)rep(d,4){
            dp[y][x][d] = nxt[y][x][d];
            nxt[y][x][d] = false;
        }
    }

    vector<pi> ans;
    rep(y,N)rep(x,N)rep(d,4){
        if(dp[y][x][d]) ans.pb({x,y});
    }

    sort(all(ans));
    ans.erase(unique(all(ans)), ans.end());
    for(const auto &p:ans) cout << p.fi << " " << p.se << endl;
    return 0;
}
