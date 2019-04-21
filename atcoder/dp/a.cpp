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

const int INF = 1000000010;

int main(){
    int n;
    cin >>n;
    vector<int> h(n);
    rep(i,n) cin >>h[i];

    vector<int> dp(n,INF);
    dp[0] = 0;
    rep(i,n){
        for(int j=1; j<=2; ++j)if(i+j<n){
            dp[i+j] = min(dp[i+j], dp[i]+abs(h[i]-h[i+j]));
        }
    }
    cout << dp[n-1] << "\n";
    return 0;
}
