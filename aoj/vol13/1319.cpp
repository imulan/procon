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

const int N = 230;
const int A = 108;

const int INF = 19191919;
const int F = 20;
int dp[N][N][F][F];

struct State{
    int x,y,b,s;
};

int nxt[20][3]={
    {5,1,4},
    {6,2,0},
    {7,3,1},
    {8,4,2},
    {9,0,3},
    {0,10,11}, //5
    {1,11,12},
    {2,12,13},
    {3,13,14},
    {4,14,10},
    {15,5,9}, //10
    {16,6,5},
    {17,7,6},
    {18,8,7},
    {19,9,8},
    {10,19,16}, //15
    {11,15,17},
    {12,16,18},
    {13,17,19},
    {14,18,15}
};

const int dx[2][3]={{0,1,-1},{0,-1,1}};
const int dy[2][3]={{1,0,0},{-1,0,0}};

const int LIM = 100;

int main(){
    rep(i,N)rep(j,N)rep(k,F)rep(l,F) dp[i][j][k][l] = INF;
    dp[A][A][0][5] = 0;
    queue<State> que;
    que.push({A,A,0,5});
    while(!que.empty()){
        State c = que.front();
        que.pop();
        if(dp[c.x][c.y][c.b][c.s]>=LIM) continue;

        // printf("NOW : %d %d %d %d   ::: %d\n",c.x,c.y,c.b,c.s,dp[c.x][c.y][c.b][c.s]);

        int ad = 0;
        while(nxt[c.b][ad] != c.s) ++ad;

        int oe = (c.x+c.y)%2;
        rep(i,3){
            int nx = c.x+dx[oe][i], ny = c.y+dy[oe][i];
            if(!(0<=nx && nx<N && 0<=ny && ny<N)) continue;
            int noe = (nx+ny)%2;

            int nb = nxt[c.b][(i+ad)%3];
            int ns = -1;
            rep(j,3){
                int xx = nx+dx[noe][j], yy = ny+dy[noe][j];
                if(xx == c.x && yy == c.y){
                    int idx = 0;
                    while(nxt[nb][idx] != c.b) ++idx;

                    idx = (idx-j+3)%3;
                    ns = nxt[nb][idx];
                    break;
                }
            }
            assert(ns != -1);

            // printf(" nx %d :: %d %d %d %d\n",i,nx,ny,nb,ns);
            if(dp[nx][ny][nb][ns] > dp[c.x][c.y][c.b][c.s]+1){
                dp[nx][ny][nb][ns] = dp[c.x][c.y][c.b][c.s]+1;
                que.push({nx,ny,nb,ns});
            }
        }
    }

    int x,y,n;
    while(cin >>x >>y >>n){
        if(x==0 && y==0 && n==0) break;
        int ans = INF;
        rep(i,F) ans = min(ans, dp[x+A][y+A][n][i]);
        cout << ans << endl;
    }
    return 0;
}
