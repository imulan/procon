#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct area
{
    ll x1,y1,z1,x2,y2,z2;

    bool inside(ll a1, ll a2, ll b1, ll b2, ll c1, ll c2)
    {
        return (x1<=a1 && a2<=x2 && y1<=b1 && b2<=y2 && z1<=c1 && c2<=z2);
    }
};

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<area> f(n);
    vector<ll> X,Y,Z;
    rep(i,n)
    {
        scanf(" %lld %lld %lld %lld %lld %lld", &f[i].x1, &f[i].y1, &f[i].z1, &f[i].x2, &f[i].y2, &f[i].z2);

        X.pb(f[i].x1);
        X.pb(f[i].x2);
        Y.pb(f[i].y1);
        Y.pb(f[i].y2);
        Z.pb(f[i].z1);
        Z.pb(f[i].z2);
    }

    sort(all(X));
    X.erase(unique(all(X)),X.end());
    sort(all(Y));
    Y.erase(unique(all(Y)),Y.end());
    sort(all(Z));
    Z.erase(unique(all(Z)),Z.end());

    ll ans=0;

    rep(i,X.size()-1)rep(j,Y.size()-1)rep(k,Z.size()-1)
    {
        int ct=0;
        rep(l,n) if(f[l].inside(X[i],X[i+1],Y[j],Y[j+1],Z[k],Z[k+1])) ++ct;
        if(ct>=m) ans+=(X[i+1]-X[i])*(Y[j+1]-Y[j])*(Z[k+1]-Z[k]);
    }

    printf("%lld\n", ans);
    return 0;
}
