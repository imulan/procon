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

const ll mod=1e9+7;

ll f(int n)
{
    ll ret = 1;
    for(int i=1; i<=n; ++i) (ret*=i)%=mod;
    return ret;
}

ll solve(int n, int m)
{
    if(abs(n-m)>=2) return 0;

    ll ret = (f(n)*f(m))%mod;
    if(n==m) (ret*=2)%=mod;
    return ret;
}

int main()
{
    int n,m;
    cin >>n >>m;
    cout << solve(n,m) << endl;
    return 0;
}
