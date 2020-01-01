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

const int INF = 19191919;
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};

int main(){
    int h,w,k;
    cin >>h >>w >>k;
    vector<string> f(h);
    rep(i,h) cin >>f[i];

    vector<pi> a;
    pi start,goal;
    rep(i,h)rep(j,w){
        if(f[i][j]=='a') a.pb({i,j});
        if(f[i][j]=='s') start = {i,j};
        if(f[i][j]=='e') goal = {i,j};
    }
    int A = a.size();

    auto IN = [&](int y, int x){
        return 0<=y && y<h && 0<=x && x<w;
    };

    auto BFS = [&](pi s){
        vector<vector<int>> d(h,vector<int>(w,INF));
        d[s.fi][s.se] = 0;
        queue<pi> que({s});
        while(!que.empty()){
            pi now = que.front();
            que.pop();
            rep(i,4){
                int ny = now.fi+dy[i], nx = now.se+dx[i];
                if(IN(ny,nx) && f[ny][nx]!='#' && d[ny][nx] > d[now.fi][now.se]+1){
                    d[ny][nx] = d[now.fi][now.se]+1;
                    que.push({ny,nx});
                }
            }
        }
        return d;
    };

    vector<vector<int>> ds = BFS(start), dg = BFS(goal);

    vector<vector<int>> da(A, vector<int>(A,INF));
    rep(i,A){
        vector<vector<int>> d = BFS(a[i]);
        rep(j,A) da[i][j] = d[a[j].fi][a[j].se];
    }

    vector<vector<int>> dp(1<<A,vector<int>(A,INF));
    rep(i,A) dp[1<<i][i] = ds[a[i].fi][a[i].se];

    rep(mask,1<<A)rep(i,A)if(mask>>i&1){
        rep(j,A)if(!(mask>>j&1)){
            int nx = mask|(1<<j);
            dp[nx][j] = min(dp[nx][j], dp[mask][i]+da[i][j]);
        }
    }

    int ans = INF;
    rep(mask,1<<A)rep(i,A)if((mask>>i&1) && __builtin_popcount(mask)>=k){
        int t = dp[mask][i];
        t += dg[a[i].fi][a[i].se];
        ans = min(ans, t);
    }

    if(ans == INF) ans = -1;
    cout << ans << "\n";
    return 0;
}
