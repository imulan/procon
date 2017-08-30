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

const ll mod = 1e9+7;

int main()
{
    int n,m;
    cin >>n >>m;

    ll ans = 0;
    for(int i=1; i<=min(n,m); ++i)
    {
        ll window = (ll)(n-i+1)*(m-i+1)%mod;
        ans += (window*i)%mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
