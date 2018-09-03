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

const int mod = 998244353;
const int N = 505;

// 今i番目の色に注目, 最大で連続しているのはj個, 今はk個連続中, 直前の色はl
int dp[N][N][2];
int nx[N][N][2];

// 最大で連続している個数がi個の1行の塗り方
int row[N];

// 今i行目に注目, 直前まで連続しているパターンはj行
int dp2[N];
int nx2[N];

int main(){
    int n,lim;
    cin >>n >>lim;

    dp[0][0][0] = 1;
    rep(i,n){
        memset(nx,0,sizeof(nx));
        rep(j,i+1)rep(k,N)rep(l,2)if(dp[j][k][l]){
            // 同じ色で塗る
            if(k+1<N) (nx[max(j,k+1)][k+1][l] += dp[j][k][l]) %= mod;
            // 別の色で塗る
            (nx[max(j,k)][1][!l] += dp[j][k][l]) %= mod;
        }
        swap(dp,nx);
    }

    rep(i,n+1){
        rep(j,N)rep(k,2) (row[i] += dp[i][j][k]) %= mod;
    }

    int ans = 0;
    for(int w=1; w<=n; ++w){
        // 最大の幅w
        // h*w < lim でないといけない
        int h = (lim-1)/w;
        if(h==0) continue;

        memset(dp2,0,sizeof(dp2));
        dp2[1]=1;
        rep(i,n-1){
            memset(nx2,0,sizeof(nx2));
            rep(j,i+1+1){
                // 同じパターン
                if(j+1<=h) (nx2[j+1] += dp2[j]) %= mod;
                // 違うパターン
                (nx2[1] += dp2[j]) %= mod;
            }
            swap(dp2,nx2);
        }

        ll pat = 0;
        rep(i,n+1) (pat += dp2[i]) %= mod;
        (pat *= row[w]) %= mod;

        (ans += pat) %= mod;
    }
    cout << ans << endl;
    return 0;
}
