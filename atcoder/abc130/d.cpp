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

    ll ans = 0;
    int r = 0;
    ll s = 0;
    rep(i,n){
        while(r<n && s<k) s += a[r++];
        if(s>=k) ans += n-r+1;
        s -= a[i];
    }
    cout << ans << endl;
    return 0;
}
