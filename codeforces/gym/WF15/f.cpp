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

const int N = 50;
const int M = 10010;
const int INF = 19191919;

const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};

int dp[M][N][N];

const pi NG = {-1,-1};
pi nxt[N][N][4];

struct State{
    int a,y,x;
};

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int h,w;
    cin >>h >>w;

    auto IN = [&](int y, int x){
        return 0<=y && y<h && 0<=x && x<w;
    };

    vector<string> s(h);
    rep(i,h) cin >>s[i];

    string t;
    cin >>t;
    t += '*';
    int T = t.size();

    // precalc
    rep(i,h)rep(j,w){
        char c = s[i][j];
        rep(d,4){
            nxt[i][j][d] = NG;
            int y=i, x=j;
            while(IN(y,x) && s[y][x] == c){
                y += dy[d];
                x += dx[d];
            }

            if(IN(y,x)) nxt[i][j][d] = {y,x};
        }
    }

    // BFS
    rep(i,M)rep(j,N)rep(k,N) dp[i][j][k] = INF;
    queue<State> que;
    dp[0][0][0] = 0;
    que.push({0,0,0});
    while(!que.empty()){
        State c = que.front();
        que.pop();
        int D = dp[c.a][c.y][c.x];
        // printf(" (%d %d %d) : %d\n", c.a,c.y,c.x,D);

        // move
        rep(d,4)if(nxt[c.y][c.x][d] != NG){
            int ny = nxt[c.y][c.x][d].fi;
            int nx = nxt[c.y][c.x][d].se;

            if(dp[c.a][ny][nx] > D+1){
                dp[c.a][ny][nx] = D+1;
                que.push({c.a,ny,nx});
            }
        }

        // sel
        if(c.a<T && t[c.a]==s[c.y][c.x]){
            int na = c.a+1;
            if(dp[na][c.y][c.x] > D+1){
                dp[na][c.y][c.x] = D+1;
                que.push({na,c.y,c.x});
            }
        }
    }

    int ans = INF;
    rep(i,h)rep(j,w) ans = min(ans, dp[T][i][j]);
    cout << ans << "\n";
    return 0;
}
