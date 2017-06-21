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
const int F=100010;
ll f[F];

inline ll mod_pow(ll x, ll n)
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

inline ll mod_inv(ll x)
{
    return mod_pow(x,mod-2);
}

inline ll C(int n, int r)
{
    if(n<r) return 0;
    ll ret = f[n];
    (ret*=mod_inv(f[r]))%=mod;
    (ret*=mod_inv(f[n-r]))%=mod;
    return ret;
}

struct Point{
    int x, y;
};

ll cross(Point a, Point b, Point c, Point d)
{
    ll Ax = b.x-a.x, Ay = b.y-a.y;
    ll Bx = d.x-c.x, By = d.y-c.y;
    return Ax*By-Ay*Bx;
}

int main()
{
    f[0]=1;
    for(int i=1; i<F; ++i) f[i]=(f[i-1]*i)%mod;

    int n,k;
    cin >>n >>k;

    vector<Point> p(3*n);
    rep(i,n)
    {
        int X,Y;
        cin >>X >>Y;
        p[i]=p[n+i]=p[2*n+i]={X,Y};
    }

    Point P;
    cin >>P.x >>P.y;

    vector<ll> sum(n+1);
    for(int i=1; i<=n; ++i) sum[i]=(sum[i-1]+C(i,k-2))%mod;

    ll U = C(n,k);
    ll ct = 0;
    int idx = 0;
    rep(i,n)
    {
        while(idx+1<3*n)
        {
            // printf(" CROSS %d & %d  = %lld\n",i,idx+1, cross(p[i],P,p[i],p[idx+1]));
            if(cross(p[i],P,p[i],p[idx+1])>0) break;
            ++idx;
        }

        int s = idx-i;
        if(s>0) (ct+=sum[s-1])%=mod;
    }

    ll ans = (U-ct+mod)%mod;
    cout << ans << endl;
    return 0;
}
