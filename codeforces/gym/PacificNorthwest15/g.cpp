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

// X = y + rx
// Y = y - rx

using pl = pair<ll,ll>;

int main(){
    int n,r,w,h;
    cin >>n >>r >>w >>h;

    vector<pl> p(n);
    rep(i,n){
        ll x,y;
        cin >>x >>y;
        p[i] = {y+x*r, y-x*r};
    }
    sort(all(p));

    vector<ll> dp(n,INF);
    rep(i,n){
        ll Y = p[i].se;
        int idx = upper_bound(all(dp), Y) - dp.begin();
        dp[idx] = Y;
    }

    int ans = n-1;
    while(dp[ans] == INF) --ans;
    cout << ans+1 << endl;
    return 0;
}
