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

ll mod_pow(ll x, ll n)
{
    ll ret = 1;
    while(n)
    {
        if(n&1) (ret*=x)%=mod;
        (x*=x)%=mod;
        n>>=1;
    }
    return ret;
}

ll solve(ll n)
{
    if(n==1) return 2;

    ll ret = 1;
    if(n%2==1)
    {
        --n;
        ret = 3;
    }
    n-=2;
    ret*=4;
    (ret*=mod_pow(5,n/2))%=mod;
    return ret;
}

int main()
{
    ll n;
    cin >>n;
    cout << solve(n) << endl;
    return 0;
}
