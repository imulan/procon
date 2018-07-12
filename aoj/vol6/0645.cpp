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

const int N = 32;
const ll INF = LLONG_MAX/3;
ll dp[N][N][N*N];

const int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

int main(){
    int h,w;
    cin >>h >>w;
    vector<vector<int>> a(h,vector<int>(w));
    rep(i,h)rep(j,w) cin >>a[i][j];

    rep(i,N)rep(j,N)rep(k,N*N) dp[i][j][k] = INF;

    auto IN = [&](int y, int x, int d){
        return 0<=y && y<h && 0<=x && x<w && d<N*N;
    };

    dp[0][0][0]=0;
    queue<State> que;
    que.push({0,0,0});
    while(!que.empty()){
        State s = que.front();
        que.pop();

        rep(i,4){
            int ny = s.y+dy[i], nx = s.x+dx[i], nd = s.d+1;
            if(!IN(ny,nx,nd)) continue;

            ll add = (2*s.d+1)*a[ny][nx];
            ll v = dp[s.y][s.x][s.d]+add;
            if(dp[ny][nx][nd] > v){
                dp[ny][nx][nd] = v;
                que.push({ny,nx,nd});
            }
        }
    }

    ll ans = INF;
    rep(i,N*N) ans = min(ans, dp[h-1][w-1][i]);
    cout << ans << endl;
    return 0;
}
