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

ll a,b,c,d;

ll lcm(ll x, ll y){
    ll g = __gcd(x,y);
    return x/g*y;
}

ll f(ll n){
    ll L = lcm(c,d);
    return n - n/c - n/d + n/L;
}

int main(){
    cin >>a >>b >>c >>d;
    cout << f(b) - f(a-1) << endl;
    return 0;
}
