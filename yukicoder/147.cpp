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

using vl = vector<ll>;
using mat = vector<vl>;

mat mul(const mat &a, const mat &b)
{
    int n = a.size();
    mat c(n,vl(n));
    rep(i,n)rep(j,n)rep(k,n) (c[i][j]+=(a[i][k]*b[k][j])%mod)%=mod;
    return c;
}

vl mul(const mat &a, const vl &b)
{
    int n = a.size();
    vl ret(n);
    rep(i,n)rep(j,n) (ret[i]+=(a[i][j]*b[j])%mod)%=mod;
    return ret;
}

mat mat_pow(const mat &a, ll n)
{
    mat p(a);

    int A = a.size();
    mat r(A,vl(A));
    rep(i,A) r[i][i]=1;

    while(n)
    {
        if(n&1) r = mul(r,p);
        p = mul(p,p);
        n>>=1;
    }

    return r;
}

ll seat(ll x)
{
    mat A(2,vl(2));
    A[0][0] = A[0][1] = A[1][0] = 1;
    mat P = mat_pow(A,x);

    vl b(2);
    rep(i,2) b[i] = 1;

    vl ans = mul(P,b);
    return ans[0];
}

ll mod_pow(ll x, ll n)
{
    ll r = 1;
    while(n)
    {
        if(n&1) (r*=x)%=mod;
        (x*=x)%=mod;
        n>>=1;
    }
    return r;
}

ll POW(ll x, string n)
{
    if(x%mod==0) return 0;

    ll nn = 0;
    rep(i,n.size())
    {
        nn = 10*nn+n[i]-'0';
        nn %= (mod-1);
    }
    return mod_pow(x,nn);
}

ll s()
{
    ll c;
    string d;
    cin >>c >>d;

    return POW(seat(c),d);
}

int main()
{
    // for(int i=1; i<=10; ++i) dbg(seat(i));

    int n;
    cin >>n;

    ll ans = 1;
    rep(i,n) (ans *= s()) %= mod;
    cout << ans << endl;
    return 0;
}
