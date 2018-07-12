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

const int N = 200020;
int dp[N][3];

int main(){
    string s;
    cin >>s;

    rep(i,N)rep(j,3) dp[i][j] = -19191919;
    dp[0][0] = 0;

    int n = s.size();
    rep(i,n)rep(j,3){
        int nj = (j+s[i]-'0')%3;
        if(nj==0){
            dp[i+1][nj] = max(dp[i+1][nj], dp[i][j]+1);
        }
        else{
            dp[i+1][nj] = max(dp[i+1][nj], dp[i][j]);
            dp[i+1][0] = max(dp[i+1][0], dp[i][j]);
        }
    }

    int ans = 0;
    rep(i,3) ans = max(ans,dp[n][i]);
    cout << ans << endl;
    return 0;
}
