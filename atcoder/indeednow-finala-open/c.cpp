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

const int N = 105;
int dp[N][N][N];

int main(){
    int n,m;
    cin >>n >>m;

    rep(i,n){
        int a,b,c,w;
        cin >>a >>b >>c >>w;
        dp[a][b][c] = max(dp[a][b][c], w);
    }

    rep(i,N)rep(j,N)rep(k,N){
        if(i+1<N) dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
        if(j+1<N) dp[i][j+1][k] = max(dp[i][j+1][k], dp[i][j][k]);
        if(k+1<N) dp[i][j][k+1] = max(dp[i][j][k+1], dp[i][j][k]);
    }

    rep(i,m){
        int x,y,z;
        cin >>x >>y >>z;
        cout << dp[x][y][z] << endl;
    }
    return 0;
}
