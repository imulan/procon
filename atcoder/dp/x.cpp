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

const ll INF = LLONG_MAX/3;
const int W = 20010;

int main(){
    int n;
    cin >>n;
    vector<int> w(n),s(n),v(n);
    rep(i,n) cin >>w[i] >>s[i] >>v[i];

    vector<pair<int,int>> o(n);
    rep(i,n) o[i] = {s[i]+w[i], i};
    sort(all(o));

    vector<ll> dp(W,-INF);
    dp[0] = 0;
    rep(oidx,n){
        int idx = o[oidx].se;

        vector<ll> nx(dp);
        rep(i,W)if(dp[i] > -INF){
            int ni = i+w[idx];
            if(s[idx]<i || ni>=W) break;
            nx[ni] = max(nx[ni], dp[i]+v[idx]);
        }
        swap(dp,nx);
    }

    ll ans = 0;
    rep(i,W) ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}
