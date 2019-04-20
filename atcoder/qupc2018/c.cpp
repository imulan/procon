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

const int INF = 19191919;

using pi = pair<int,int>;

const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};

int main(){
    int h,w,X;
    cin >>h >>w >>X;
    vector<string> s(h);
    rep(i,h) cin >>s[i];

    pi start,goal;
    rep(i,h)rep(j,w){
        if(s[i][j]=='S') start = {i,j};
        if(s[i][j]=='G') goal = {i,j};
    }

    auto IN = [&](int y, int x){
        return (0<=y && y<h && 0<=x && x<w && s[y][x]!='#');
    };

    queue<pi> que;

    vector<vector<int>> d(h, vector<int>(w,INF));
    rep(i,h)rep(j,w){
        if(s[i][j]=='@'){
            d[i][j] = 0;
            que.push({i,j});
        }
    }
    while(!que.empty()){
        pi now = que.front();
        que.pop();
        rep(i,4){
            int ny = now.fi+dy[i], nx = now.se+dx[i];
            if(IN(ny,nx) && d[ny][nx] > d[now.fi][now.se]+1){
                d[ny][nx] = d[now.fi][now.se]+1;
                que.push({ny,nx});
            }
        }
    }

    vector<vector<int>> dp(h, vector<int>(w,INF));
    dp[start.fi][start.se] = 0;
    que.push(start);
    while(!que.empty()){
        pi now = que.front();
        que.pop();
        rep(i,4){
            int ny = now.fi+dy[i], nx = now.se+dx[i];
            if(IN(ny,nx) && d[ny][nx]>X && dp[ny][nx] > dp[now.fi][now.se]+1){
                dp[ny][nx] = dp[now.fi][now.se]+1;
                que.push({ny,nx});
            }
        }
    }

    int ans = dp[goal.fi][goal.se];
    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}
