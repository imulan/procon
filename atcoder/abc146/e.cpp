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

ll solve(){
    int n;
    ll k;
    cin >>n >>k;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    if(k==1) return 0;

    vector<ll> s(a);
    for(int i=1; i<n; ++i) (s[i] += s[i-1]) %= k;

    map<ll,int> ct;
    rep(i,n) s[i] = (s[i] - (i+1)%k + k)%k;
    rep(i,min(n,(int)k-1)) ++ct[s[i]];

    ll ans = 0;
    ll x = 0;
    rep(i,n){
        if(ct.count(x)) ans += ct[x];

        if(i+k-1<n) ++ct[s[i+k-1]];
        --ct[s[i]];

        (x += a[i]-1) %= k;
    }
    return ans;
}

int main(){
    cout << solve() << "\n";
    return 0;
}
