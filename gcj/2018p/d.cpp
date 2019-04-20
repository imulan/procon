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

using P = pair<ll,ll>;

map<P,P> dp;
P dfs(ll n, ll k){
    if(n==0) return {INF,INF};
    if(dp.count({n,k})) return dp[{n,k}];

    printf(" %lld %lld\n", n, k);

    --k;
    if(k==0){
        P ret(n/2,n/2);
        if(n%2==0) --ret.fi;
        return ret;
    }

    P ret(INF,INF);

    ll ln = n/2, rn = n/2;
    if(n%2==0) --ln;

    ll lk = k/2 ,rk = k/2;
    if(k%2==1) ++rk;

    // if(ln>0) ret = min(ret, dfs(ln,lk));
    if(rn>0) ret = min(ret, dfs(rn,rk));
    return dp[{n,k}] = ret;

}

void solve(){
    ll n,k;
    cin >>n >>k;
    dp.clear();
    P ans = dfs(n,k);
    printf("%lld %lld\n", ans.se, ans.fi);
}

int main(){
    int T;
    cin >>T;
    rep(i,T){
        printf("Case #%d: ",i+1);
        solve();
    }
    return 0;
}
