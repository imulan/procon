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
const int F=9000000;

ll f[F+1]={};
int a[3000][3000]={};

ll dp[3001][3001]={};

inline ll mod_pow(ll x, ll n)
{
    ll ret = 1;
    while(n>0)
    {
        if(n&1) (ret*=x)%=mod;
        (x*=x)%=mod;
        n>>=1;
    }
    return ret;
}

inline ll mod_inv(ll x)
{
    return mod_pow(x,mod-2);
}

inline ll C(int lx, int rx, int ly, int ry)
{
    int X = lx+rx ,Y = ly+ry;
    ll ret = (f[X]*f[Y])%mod;
    (ret*=mod_inv(f[lx]))%=mod;
    (ret*=mod_inv(f[rx]))%=mod;
    (ret*=mod_inv(f[ly]))%=mod;
    (ret*=mod_inv(f[ry]))%=mod;
    return ret;
}

int main()
{
    f[0]=1;
    for(ll i=1; i<=F; ++i) f[i] = (f[i-1]*i)%mod;

    int r,c,n;
    scanf(" %d %d %d", &r, &c, &n);

    vector<int> x(n),y(n);
    rep(i,n)
    {
        scanf(" %d %d", &y[i], &x[i]);
        --x[i];
        --y[i];
        a[y[i]][x[i]]=1;
    }

    int lx = *min_element(all(x));
    int rx = *max_element(all(x));
    int ly = *min_element(all(y));
    int ry = *max_element(all(y));

    int ct = 0;
    for(int i=ly; i<=ry; ++i)for(int j=lx; j<=rx; ++j) ct += !a[i][j];

    int bx = rx-lx+1, by = ry-ly+1;
    dp[0][0] = f[ct];
    rep(i,r-by+1)rep(j,c-bx+1)
    {
        if(j<c-bx) (dp[i][j+1]+=dp[i][j]*f[by+i])%=mod;
        if(i<r-by) (dp[i+1][j]+=dp[i][j]*f[bx+j])%=mod;
    }

    ll ans = dp[r-by][c-bx];
    (ans*=C(lx,c-1-rx,ly,r-1-ry))%=mod;
    printf("%lld\n", ans);
    return 0;
}
