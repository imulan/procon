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

const int N = 3003;
int dp[N][N];

int main(){
    string s,t;
    cin >>s >>t;
    int S = s.size(), T = t.size();

    rep(i,S+1)rep(j,T+1){
        if(i<S) dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        if(j<T) dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
        if(i<S && j<T && s[i]==t[j]) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1);
    }

    int x = S, y = T;
    string ans = "";
    while(x>0 || y>0){
        // printf(" x y %d %d\n", x, y);
        if(x>0 && y>0 && s[x-1]==t[y-1] && dp[x][y] == dp[x-1][y-1]+1){
            ans += s[x-1];
            --x;
            --y;
            continue;
        }

        if(x>0 && dp[x][y] == dp[x-1][y]){
            --x;
            continue;
        }
        if(y>0 && dp[x][y] == dp[x][y-1]){
            --y;
            continue;
        }
        assert(false);
    }

    reverse(all(ans));
    cout << ans << "\n";
    return 0;
}
