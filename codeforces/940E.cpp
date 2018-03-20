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

const int N = 100010;
const ll INF = LLONG_MAX/3;
ll dp[N];

ll solve(){
    int n,c;
    cin >>n >>c;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    if(n<c){
        ll ret = 0;
        rep(i,n) ret += a[i];
        return ret;
    }

    multiset<ll> m;
    ll sa = 0;
    rep(i,c-1){
        m.insert(a[i]);
        sa += a[i];
    }

    fill(dp,dp+N,INF);
    dp[0] = 0;
    rep(i,n){
        dp[i+1] = min(dp[i+1], dp[i]+a[i]);

        if(i+c<=n){
            m.insert(a[i+c-1]);
            sa += a[i+c-1];

            dp[i+c] = min(dp[i+c], dp[i]+sa-(*m.begin()));

            m.erase(m.find(a[i]));
            sa -= a[i];
        }
    }
    return dp[n];
}

int main(){
    cout << solve() << endl;
    return 0;
}
