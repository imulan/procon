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
    int l,k;
    cin >>l >>k;

    vector<ll> dp(l+1);
    dp[1] = 1;
    if(k<=l) dp[k] = 1;
    for(int i=1; i<l; ++i){
        if(i+2<=l) dp[i+2] += dp[i];
        if(i+1+k<=l) dp[i+1+k] += dp[i];
    }

    ll ans = 0;
    rep(i,l+1) ans += dp[i];
    cout << ans << endl;
    return 0;
}
