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
    ll a,b;
    cin >>a >>b;

    const ll g = __gcd(a,b);
    ll t = g;
    ll ans = 1;
    for(ll i=2; i*i<=g; ++i){
        if(t%i == 0){
            ++ans;
            while(t%i == 0) t/=i;
        }
    }
    if(t>1) ++ans;

    cout << ans << "\n";
    return 0;
}
