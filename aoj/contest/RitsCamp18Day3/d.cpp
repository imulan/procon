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

const int N = 1001000;
bool prime[N];

const ll mod = 1e9+7;

int main(){
    fill(prime,prime+N,true);
    prime[0] = prime[1] = false;
    for(int i=2; i<N; ++i){
        if(prime[i]) for(int j=2*i; j<N; j+=i) prime[j] = false;
    }

    int n;
    cin >>n;
    vector<int> q(n);
    rep(i,n) cin >>q[i];
    q.pb(1000999);

    vector<ll> dp(n+1);
    dp[0] = 1;
    rep(i,n)if(prime[q[i]]){
        // 1個
        if(i+1<=n && prime[q[i+1]] && q[i]<q[i+1]) (dp[i+1] += dp[i]) %= mod;

        // 2個
        if(i+2<=n && prime[q[i+2]] && q[i]<q[i+2]) (dp[i+2] += dp[i]) %= mod;
    }
    cout << dp[n] << endl;

    return 0;
}
