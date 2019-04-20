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

inline ll mul(ll a, ll b){return (a*b)%mod;}

ll solve()
{
    int X,Y,Z;
    scanf(" %d %d %d", &X, &Y, &Z);
    vector<ll> x(X),y(Y),z(Z);
    rep(i,X) scanf(" %lld", &x[i]);
    rep(i,Y) scanf(" %lld", &y[i]);
    rep(i,Z) scanf(" %lld", &z[i]);

    sort(all(x));
    sort(all(y));
    sort(all(z));

    vector<ll> sumx(X+1),sumz(Z+1);
    rep(i,X) sumx[i+1] = (sumx[i]+x[i])%mod;
    rep(i,Z) sumz[i+1] = (sumz[i]+z[i])%mod;

    ll ans=0;

    rep(i,Y)
    {
        int xidx = upper_bound(all(x),y[i])-x.begin();
        int zidx = upper_bound(all(z),y[i])-z.begin();

        (ans += mul(mul(mul(y[i],y[i]),xidx),zidx)) %= mod;
        (ans += mul(mul(zidx,y[i]),sumx[xidx])) %= mod;
        (ans += mul(mul(xidx,y[i]),sumz[zidx])) %= mod;
        (ans += mul(sumx[xidx],sumz[zidx])) %=mod;
    }

    return ans;
}

int main()
{
    int T;
    cin >>T;
    while(T--) cout << solve() << endl;
    return 0;
}
