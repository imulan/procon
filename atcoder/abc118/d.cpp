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

using vi = vector<int>;

int num[10] = {0,2,5,5,4,5,6,3,7,6};

int main(){
    int n,m;
    cin >>n >>m;
    vi a(m);
    rep(i,m) cin >>a[i];

    sort(all(a), greater<int>());

    vi NG(m+1,-1);
    vector<vector<vi>> dp(n+1,vector<vi>(m,NG));
    dp[n][0] = vi(m+1,0);

    for(int i=n; i>0; --i)rep(j,m)if(dp[i][j] != NG){
        if(j<m-1) dp[i][j+1] = max(dp[i][j+1], dp[i][j]);

        int ni = i-num[a[j]];
        if(ni>=0){
            vi nx = dp[i][j];
            ++nx[0];
            ++nx[j+1];
            dp[ni][j] = max(dp[ni][j], nx);
        }
    }

    vi ans = NG;
    rep(i,m) ans = max(ans, dp[0][i]);

    rep(i,m)rep(j,ans[i+1]) cout << a[i];
    cout << endl;
    return 0;
}
