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

int main(){
    int n;
    cin >>n;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    vector<ll> e(n+1);
    rep(i,n){
        if(a[i]==0) e[i] = 2;
        else if(a[i]%2==1) e[i] = 1;
    }
    rep(i,n) e[i+1] += e[i];

    auto EV = [&](int r){
        if(r==0) return 0LL;
        return e[r-1];
    };

    vector<ll> o(n+1);
    rep(i,n){
        if(a[i]%2==0) o[i]++;
    }
    rep(i,n) o[i+1] += o[i];

    auto OD = [&](int r){
        if(r==0) return 0LL;
        return o[r-1];
    };

    vector<ll> dp(n+1,0);
    ll s = 0;
    rep(i,n){
        s += a[i];
        dp[i+1] = s;
    }

    // 0 | ev
    vector<ll> nx(n+1,INF);
    ll val = INF;
    rep(i,n+1){
        val = min(val, dp[i]-EV(i));
        nx[i] = min(nx[i], val+EV(i));
    }
    dp = nx;

    // ev | od
    nx = vector<ll>(n+1,INF);
    val = INF;
    rep(i,n+1){
        val = min(val, dp[i]-OD(i));
        nx[i] = min(nx[i], val+OD(i));
    }
    dp = nx;

    // od | ev
    nx = vector<ll>(n+1,INF);
    val = INF;
    rep(i,n+1){
        val = min(val, dp[i]-EV(i));
        nx[i] = min(nx[i], val+EV(i));
    }
    dp = nx;

    // ev | 0
    ll ans = INF;
    s = 0;
    for(int i=n; i>=0; --i){
        ans = min(ans, dp[i]+s);
        if(i>0) s += a[i-1];
    }
    cout << ans << endl;
    return 0;
}
