#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;
const int INF = 19191919;

const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};

int solve(){
    int h,w,d;
    cin >>h >>w >>d;

    auto IN = [&](int y, int x){
        return 0<=y && y<h && 0<=x && x<w;
    };

    vector<string> s(h);
    rep(i,h) cin >>s[i];

    queue<pi> que;
    vector<vector<int>> dm(h,vector<int>(w,INF));
    pi start,goal;
    rep(i,h)rep(j,w){
        if(s[i][j]=='S') start={i,j};
        if(s[i][j]=='F') goal={i,j};
        if(s[i][j]=='M'){
            que.push({i,j});
            dm[i][j] = 0;
        }
    }

    while(!que.empty()){
        pi c = que.front();
        que.pop();
        int D = dm[c.fi][c.se];

        rep(i,4){
            int ny = c.fi+dy[i], nx = c.se+dx[i];
            if(IN(ny,nx) && dm[ny][nx] > D+1){
                dm[ny][nx] = D+1;
                que.push({ny,nx});
            }
        }
    }

    if(dm[start.fi][start.se]<=d || dm[goal.fi][goal.se]<=d) return -1;

    vector<vector<int>> dp(h,vector<int>(w,INF));
    dp[start.fi][start.se] = 0;
    que.push(start);
    while(!que.empty()){
        pi c = que.front();
        que.pop();
        int D = dp[c.fi][c.se];

        rep(i,4){
            int ny = c.fi+dy[i], nx = c.se+dx[i];
            if(IN(ny,nx) && dm[ny][nx]>d && dp[ny][nx] > D+1){
                dp[ny][nx] = D+1;
                que.push({ny,nx});
            }
        }
    }

    int ans = dp[goal.fi][goal.se];
    if(ans == INF) ans = -1;
    return ans;
}

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}