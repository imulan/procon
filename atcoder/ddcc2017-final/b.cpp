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

inline ll lcm(ll x, ll y)
{
    return x/__gcd(x,y)*y;
}

int main()
{
    int n;
    ll z;
    cin >>n >>z;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    ll ans = 1;
    rep(i,n)
    {
        ll g = __gcd(z,a[i]);
        ans = lcm(ans,g);
    }

    cout << ans << endl;
    return 0;
}
