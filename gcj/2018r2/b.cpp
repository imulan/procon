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

const int SN = 33;
const int N = 501;

short dp[N][N][SN][SN];

short dfs(short r, short b, short d, short lim){
    if(dp[r][b][d][lim] >= 0) return dp[r][b][d][lim];

    short ret = 0;
    short ur = 0, ub = 0, add = 0;
    rep(i,lim+1){
        ur += d;
        if(r-ur<0) break;

        ub += i;
        if(b-ub<0) break;

        ++add;
        short t = add+dfs(r-ur, b-ub, d+1, i);
        if(ret < t) ret = t;
    }

    return dp[r][b][d][lim] = ret;
}

int solve(){
    int R,B;
    cin >>R >>B;
    return dfs(R,B,0,32) - 1;
}

int main(){
    memset(dp,-1,sizeof(dp));

    int T;
    cin >>T;
    rep(i,T){
        printf("Case #%d: %d\n", i+1, solve());
    }
    return 0;
}
