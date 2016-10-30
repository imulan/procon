#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int f[61][100000]={0};

int main()
{
    int n;
    scanf(" %d", &n);

    vector<int> x(n);
    rep(i,n) scanf(" %d", &x[i]);

    int m;
    ll k;
    scanf(" %d %lld", &m, &k);

    vector<int> a(m);
    rep(i,m)
    {
        scanf(" %d", &a[i]);
        --a[i];
    }

    rep(i,n-1) f[0][i]=i;
    rep(i,m) swap(f[0][a[i]],f[0][a[i]-1]);
    for(int i=1; i<=60; ++i)rep(j,n-1) f[i][j]=f[i-1][f[i-1][j]];

    vector<ll> d(n-1);
    rep(i,n-1) d[i]=x[i+1]-x[i];

    vector<int> pos(n-1);
    rep(i,n-1) pos[i]=i;

    for(int i=60; i>=0; --i)
    {
        if(k-(1LL<<i)>=0)
        {
            vector<int> newpos(n-1);
            rep(j,n-1) newpos[j]=f[i][pos[j]];

            k-=(1LL<<i);
            pos=newpos;
        }
    }

    vector<ll> E(n,0);
    E[0]=x[0];
    rep(i,n-1) E[i+1]=E[i]+d[pos[i]];

    rep(i,n) printf("%lld\n", E[i]);
    return 0;
}
