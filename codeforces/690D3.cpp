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

using vec = vector<ll>;
using mat = vector<vec>;

const int N = 110;
const ll mod = 1000003;

mat mul(const mat &A, const mat &B)
{
    int n = A.size();
    mat C(n,vec(n,0));
    rep(i,n)rep(j,n)
    {
        rep(k,n) (C[i][j]+=(A[i][k]*B[k][j])%mod)%=mod;
    }
    return C;
}

vec mul(const mat &A, const vec &B)
{
    int n = A.size();
    vec ret(n,0);
    rep(i,n)rep(j,n) (ret[i]+=(A[i][j]*B[j])%mod)%=mod;

    rep(i,n) dbg(ret[i]);
    return ret;
}

mat pow(const mat &A, int x)
{
    int n = A.size();
    mat r(n,vec(n,0));
    rep(i,n) r[i][i]=1;

    mat a(A);

    while(x)
    {
        dbg(x);
        if(x) r = mul(r,a);
        a = mul(a,a);
        x>>=1;
    }

    return r;
}

ll powh[N];

int main()
{
    int c,w,h;
    scanf(" %d %d %d", &c, &w, &h);

    powh[0] = 1;
    for(int i=1; i<N; ++i) powh[i] = (powh[i-1]*h)%mod;

    mat A(w+1,vec(w+1,0));

    for(int i=1; i<w+1; ++i) A[i][i-1] = 1;
    A[w][w] = 1;

    for(int i=w; i>=0; --i)
    {
        rep(j,w+1)
        {
            A[i][j] = powh[j-i+w-1];h
        }
    }

    rep(i,w-1) A[i][w] = powh[w-1-i];

    mat M = pow(A,c+1);

    vec b(w+1,0);
    b[w]=1;

    vec v = mul(M,b);
    printf("%lld\n",v[w]);
    return 0;
}
