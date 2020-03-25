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

int main(){
    int n;
    ll k;
    cin >>n >>k;

    vector<ll> a(n);
    rep(i,n) cin >>a[i];
    sort(all(a));

    int c = n/2;
    ll med = a[c];
    ll s = 0;
    rep(i,n) s += abs(med-a[i]);

    if(s<=k){
        cout << 0 << "\n";
        return 0;
    }

    vector<ll> w(n);
    int widx = 1;
    rep(i,c){
        w[widx] += a[i+1]-a[i];
        ++widx;
    }

    widx = 1;
    for(int i=n-1; i>c; --i){
        w[widx] += a[i]-a[i-1];
        ++widx;
    }

    ll ans = a[n-1]-a[0];
    for(int i=1; i<n; ++i){
        ll num = min(w[i], k/i);
        k -= num*i;
        ans -= num;
    }
    cout << ans << "\n";
    return 0;
}
