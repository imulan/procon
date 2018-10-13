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

int main(){
    int n;
    while(cin >>n,n){
        vector<int> w(n);
        rep(i,n) cin >>w[i];

        vector<vector<int>> ok(n,vector<int>(n));
        rep(i,n-1) ok[i][i+1] = (abs(w[i]-w[i+1]) <= 1);

        for(int b=4; b<=n; b+=2){
            for(int l=0; l+b-1<n; ++l){
                int r = l+b-1;
                for(int i=l+1; i<r; ++i) ok[l][r] |= (ok[l][i] & ok[i+1][r]);
                ok[l][r] |= ((abs(w[l]-w[r])<=1) & ok[l+1][r-1]);
            }
        }

        vector<int> dp(n+1,-n);
        dp[0] = 0;
        rep(i,n){
            for(int j=i; j<n; ++j){
                if(ok[i][j]) dp[j+1] = max(dp[j+1], dp[i]+(j-i+1));
            }
            dp[i+1] = max(dp[i+1],dp[i]);
        }
        cout << dp[n] << endl;
    }
    return 0;
}
