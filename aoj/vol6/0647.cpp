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

int main(){
    int n,k;
    cin >>n >>k;

    vector<ll> t(n);
    rep(i,n) cin >>t[i];

    vector<ll> d(n-1);
    rep(i,n-1) d[i] = t[i+1]-(t[i]+1);
    sort(all(d), greater<ll>());

    ll ans = t[n-1]+1 - t[0];
    rep(i,k-1) ans -= d[i];
    cout << ans << "\n";
    return 0;
}
