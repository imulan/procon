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

vector<int> divisor(int n)
{
    vector<int> ret;
    for(int i=1; i*i<=n; ++i)
    {
        if(n%i==0)
        {
            ret.pb(i);
            if(n/i!=i) ret.pb(n/i);
        }
    }
    sort(all(ret));
    return ret;
}

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

const int N = 100010;
int num[N] = {};

ll ct[N]={};

int main()
{
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    rep(i,n)
    {
        for(int j:divisor(a[i])) ++num[j];
    }

    rep(i,N) ct[i] = (mod_pow(2,num[i])+mod-1)%mod;

    for(int i=N-1; i>0; --i)
    {
        for(int j:divisor(i))if(j!=i)
        {
            ct[j] = (ct[j]-ct[i]+mod)%mod;
        }
    }

    // rep(i,N)if(ct[i]) printf("ct[%d] %lld\n", i,ct[i]);
    cout << ct[1] << endl;
    return 0;
}
