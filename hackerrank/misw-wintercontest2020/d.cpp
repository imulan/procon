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

const int N = 1001;
int a[N][N];
int dp[N][N][2];

int main(){
    int h,w;
    scanf(" %d %d", &h, &w);
    rep(i,h)rep(j,w) scanf(" %d", &a[i][j]);

    memset(dp,-1,sizeof(dp));
    dp[0][0][0] = dp[0][0][1] = a[0][0];
    rep(y,h)rep(x,w)rep(d,2)if(dp[y][x][d]>=0){
        int val = dp[y][x][d];
        int add = 0;
        if(d == 0){
            for(int i=1; i<=2; ++i){
                int nx = x+i;
                if(nx >= w) continue;
                add += a[y][nx];
                dp[y][nx][1] = max(dp[y][nx][1], val+add);
            }
        }
        else{
            for(int i=1; i<=2; ++i){
                int ny = y+i;
                if(ny >= h) continue;
                add += a[ny][x];
                dp[ny][x][0] = max(dp[ny][x][0], val+add);
            }
        }
    }

    int ans = max(dp[h-1][w-1][0],dp[h-1][w-1][1]);
    printf("%d\n", ans);
    return 0;
}
