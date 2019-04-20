#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll mod = (1LL<<31) - 1;

const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};

int main(){
    int n;
    cin >>n;
    vector<string> s(n);
    rep(i,n) cin >>s[i];

    auto OK = [&](int y, int x){
        return (0<=y && y<n && 0<=x && x<n && s[y][x]=='.');
    };

    auto reach = [&](int dlim){
        using pi = pair<int,int>;
        vector<vector<bool>> vis(n,vector<bool>(n));
        queue<pi> que;
        que.push({0,0});
        vis[0][0] = true;
        while(!que.empty()){
            pi c = que.front();
//            printf(" %d %d\n",c.fi,c.se);
            que.pop();
            rep(d,dlim){
                int ny = c.fi+dy[d], nx = c.se+dx[d];
                if(OK(ny,nx) && !vis[ny][nx]){
                    que.push({ny,nx});
                    vis[ny][nx] = true;
                }
            }
        }
        return vis[n-1][n-1];
    };

    if(!reach(4)){
        cout << "INCONCEIVABLE" << endl;
        return 0;
    }
    if(!reach(2)){
        cout << "THE GAME IS A LIE" << endl;
        return 0;
    }

    vector<vector<ll>> dp(n,vector<ll>(n));
    dp[0][0] = 1;
    rep(i,n)rep(j,n){
        rep(k,2){
            int ny = i+dy[k], nx = j+dx[k];
            if(OK(ny,nx)) (dp[ny][nx] += dp[i][j]) %= mod;
        }
    }
    cout << dp[n-1][n-1] << endl;
    return 0;
}


