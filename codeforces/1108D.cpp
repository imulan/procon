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

const int N = 200002;
const string c = "RGB";

int dp[N][3], par[N][3];

int main(){
    int n;
    string s;
    cin >>n >>s;

    // init
    fill(dp[0],dp[N],N);
    fill(par[0],par[N],-1);
    rep(i,3) dp[0][i] = 0;

    // calc
    rep(i,n)rep(j,3){
        rep(k,3)if(j!=k){
            int cost = (c[k]!=s[i]);
            if(dp[i+1][k] > dp[i][j]+cost){
                dp[i+1][k] = dp[i][j]+cost;
                par[i+1][k] = j;
            }
        }
    }

    // restore
    int ans = N;
    int idx = -1;
    rep(i,3)if(dp[n][i]<ans){
        ans = dp[n][i];
        idx = i;
    }
    assert(idx >= 0);

    string t = s;
    for(int i=n-1; i>=0; --i){
        t[i] = c[idx];
        idx = par[i+1][idx];
    }

    cout << ans << "\n";
    cout << t << "\n";
    return 0;
}
