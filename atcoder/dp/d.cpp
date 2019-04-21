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
    int n,W;
    cin >>n >>W;
    vector<int> v(n),w(n);
    rep(i,n) cin >>w[i] >>v[i];

    vector<ll> dp(W+1);
    rep(i,n){
        for(int j=W; j>=0; --j){
            int nj = j+w[i];
            if(nj>W) continue;
            dp[nj] = max(dp[nj], dp[j]+v[i]);
        }
    }

    ll ans = 0;
    rep(i,W+1) ans = max(ans, dp[i]);
    cout << ans << "\n";
    return 0;
}
