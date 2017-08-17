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
    int n;
    cin >>n;

    vector<ll> a(n+1);
    a[1] = 1;

    ll odd = 1, even = 0;
    for(ll i=2; i<=n; ++i)
    {
        if(i%2==0)
        {
            a[i] = (i*odd)%mod;
            (even += a[i])%=mod;
        }
        else
        {
            a[i] = (i*even)%mod;
            (odd += a[i])%=mod;
        }
    }

    cout << a[n] << endl;
    return 0;
}
