#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))

using ll = long long;

const ll mod = 1e9+7;

using vl = vector<ll>;
using mat = vector<ll>;

mat mul(const mat &a, const mat &b)
{
    int n = a.size();
    mat c(n);

    rep(i,n)
    {
        c[i] = 0;
        rep(j,n) c[i] = (a[j]*b[(i-j+n)%n] + c[i]) %mod;
    }
    return c;
}

vl mul_v(const mat &a, const vl &b)
{
    int n = a.size();
    vl ret(n);
    rep(i,n)
    {
        rep(j,n)
        {
            ret[i] += (a[(j+i)%n]*b[j])%mod;
            ret[i] %= mod;
        }
    }

    return ret;
}


mat pow(const mat &a, int n)
{
    int N = a.size();
    mat r(N);
    // 単位
    r[0]=1;

    mat p(a);
    while(n)
    {
        if(n&1) r = mul(r,p);
        p = mul(p,p);
        n>>=1;
    }

    return r;
}

int main()
{
    int n,m,k;
    scanf(" %d %d %d", &n, &m, &k);

    mat A(n);
    A[0] = 1;

    rep(i,m)
    {
        int p;
        scanf(" %d", &p);

        ++A[p%n];
    }

    mat P = pow(A,k);
    vl b(n);
    b[0]=1;

    vl ans = mul_v(P,b);

    rep(i,n) printf("%lld\n", ans[i]);
    return 0;
}
