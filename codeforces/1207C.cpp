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

const ll INF = LLONG_MAX/3;

ll solve(){
    int n;
    ll a,b;
    string s;
    cin >>n >>a >>b >>s;
    s += '0';

    vector<ll> dp(2,INF);
    dp[0] = b;
    rep(i,n){
        vector<ll> nx(2,INF);

        int x = 1;
        if(s[i]=='0' && s[i+1]=='0') x = 0;

        rep(j,2)for(int k=x; k<2; ++k){
            ll cost = b*(k+1);
            if(j!=k) cost += a;
            cost += a;
            nx[k] = min(nx[k], dp[j]+cost);
        }

        dp = nx;
    }

    return dp[0];
}

int main(){
    int t;
    cin >>t;
    while(t--) cout << solve() << "\n";
    return 0;
}
