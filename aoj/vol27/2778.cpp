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

using vl = vector<ll>;
using mat = vector<vl>;

const ll mod = 1e9+7;

mat mul(const mat &a, const mat &b)
{
    int n = a.size();
    mat c(n,vl(n));
    rep(i,n)rep(j,n)rep(k,n) (c[i][j]+=a[i][k]*b[k][j])%=mod;
    return c;
}

vl mul(const mat &a, const vl &b)
{
    int n = a.size();
    vl c(n);
    rep(i,n)rep(j,n) (c[i]+=a[i][j]*b[j])%=mod;
    return c;
}

mat mat_pow(const mat &a, int T)
{
    int n = a.size();
    mat ret(n,vl(n));
    rep(i,n) ret[i][i] = 1;

    mat p(a);
    while(T)
    {
        if(T&1) ret = mul(ret,p);
        p = mul(p,p);
        T>>=1;
    }
    return ret;
}

int main()
{
    int n,k,C,T;
    cin >>n >>k >>C >>T;
    --C;

    vector<int> a(k),b(k),t(k);
    rep(i,k)
    {
        cin >>a[i] >>b[i] >>t[i];
        --a[i];
    }

    int SZ = 5*n;

    mat A(SZ,vl(SZ));
    // make A
    for(int i=n; i<5*n; ++i) A[i-n][i] += 1;
    rep(i,k)
    {
        rep(j,n)
        {
            int idx = (t[i]-1)*n+j;
            if(j<a[i]) idx += b[i];
            else if(j<a[i]+b[i]) idx -= a[i];

            A[idx][j] += 1;
        }
    }

    vl B(SZ);
    B[C] = 1;

    vl res = mul(mat_pow(A,T),B);
    cout << res[0] << endl;
    return 0;
}
