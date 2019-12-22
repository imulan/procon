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

const ll mod = 1e9+7;

int main(){
    string s;
    cin >>s;
    int n = s.size();

    vector<ll> dp(n+3,0);
    dp[0] = 1;
    rep(i,n){
        (dp[i+1] += dp[i]) %= mod;
        (dp[i+2] += dp[i]) %= mod;
    }

    ll ans = 1;
    int st = 0;
    while(st<n){
        int nx = st;
        char c = s[st];
        while(nx<n && s[nx]==c) ++nx;

        if(c=='n' || c=='u'){
            ll w = nx-st;
            (ans *= dp[w]) %= mod;
        }
        if(c=='m' || c=='w') ans = 0;

        st = nx;
    }

    cout << ans << "\n";
    return 0;
}
