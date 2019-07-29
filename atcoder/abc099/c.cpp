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

int main(){
    int n;
    cin >>n;

    vector<int> dp(n+1,n);
    dp[0] = 0;
    rep(i,n){
        dp[i+1] = min(dp[i+1], dp[i]+1);

        for(int p:{6,9}){
            for(int j=p; i+j<=n; j*=p) dp[i+j] = min(dp[i+j], dp[i]+1);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
