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
    cin >>n;

    ll x = 0, y = 0, z = 0;
    vector<ll> a(n);
    rep(i,n){
        cin >>a[i];
        x = max(x,a[i]);
    }

    rep(i,n) z = __gcd(z,x-a[i]);
    rep(i,n) y += (x-a[i])/z;
    cout << y << " " << z << "\n";
    return 0;
}
