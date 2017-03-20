#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef vector<ll> vi;
typedef vector<vi> mat;

const ll mod = 1e9+7;

int H,R;
int g[16][16];

int a[16][1<<16];

mat mul(const mat &A, const mat &B)
{
    int n = A.size();
    mat ret(n,vi(n,0));
    rep(i,n)rep(j,n)
    {
        rep(k,n) (ret[i][j]+=(A[i][k]*B[k][j])%mod)%=mod;
    }
    return ret;
}

vi mul(const mat &A, const vi &B)
{
    int n = A.size();
    vi ret(n,0);
    rep(i,n)rep(j,n) (ret[i]+=A[i][j]*B[j])%=mod;
    return ret;
}

int main()
{
    scanf(" %d %d", &H, &R);
    rep(i,R)rep(j,R) scanf(" %d", &g[i][j]);

    mat M[31];
    M[0] = mat(R,vi(R,0));

    rep(start,R)
    {
        fill(a[0],a[16],0);
        a[start][1<<start]=1;

        rep(mask,1<<R)rep(last,R)if(mask>>last&1)
        {
            rep(nx,R)if(!(mask>>nx&1) && g[last][nx])
            {
                (a[nx][mask+(1<<nx)]+=a[last][mask])%=mod;
            }
        }

        int s[16]={};
        rep(i,R)rep(mask,1<<R) (s[i]+=a[i][mask])%=mod;;

        rep(i,R) M[0][start][i]=s[i];
    }

    for(int i=1; i<31; ++i) M[i] = mul(M[i-1],M[i-1]);

    mat A(R,vi(R,0));
    rep(i,R) A[i][i]=1;

    rep(i,31)if(H>>i&1) A=mul(A,M[i]);

    vi b(R,0);
    b[0]=1;

    vi c = mul(A,b);
    printf("%lld\n", c[0]);
    return 0;
}
