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

const int N = 5005;
const int INF = 19191919;
int dp[N][N][2];

int solve(){
    int A,B;
    string a,b;
    cin >>A >>B >>a >>b;

    rep(i,A+1)rep(j,B+1)rep(k,2) dp[i][j][k] = INF;
    dp[1][0][0] = 1;
    dp[0][1][1] = 1;
    rep(i,A+1)rep(j,B+1)rep(k,2)if(dp[i][j][k]<INF){
        char c;
        if(k==0) c = a[i-1];
        else c = b[j-1];

        if(i<A) dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][k]+(c!=a[i]));
        if(j<B) dp[i][j+1][1] = min(dp[i][j+1][1], dp[i][j][k]+(c!=b[j]));
    }

    return min(dp[A][B][0], dp[A][B][1]);
}

int main(){
    int T;
    cin >>T;
    while(T--) cout << solve() << endl;
    return 0;
}
