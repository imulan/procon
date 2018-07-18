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

const ll mod = 998244353;

const int N = 1000010;
ll pw[N];

int main(){
    pw[0] = 1;
    for(int i=1; i<N; ++i) pw[i] = (pw[i-1]*2)%mod;

    int n;
    scanf(" %d", &n);
    vector<ll> a(n+1);
    rep(i,n) scanf(" %lld", &a[i+1]);

    rep(i,n) (a[i+1] += a[i]) %= mod;

    ll ans = 0;
    for(int i=1; i<n; ++i){
        ll c = n-1-i;

        ll m = 2*pw[n-1-i];
        if(n-2-i>=0) (m += c*pw[n-2-i]) %= mod;

        (ans += m*a[i]) %= mod;
    }
    (ans += a[n]) %= mod;

    cout << ans << endl;
    return 0;
}
