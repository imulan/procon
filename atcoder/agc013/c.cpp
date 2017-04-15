#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<ll,int> pl;

int main()
{
    int n;
    ll L,T;
    scanf(" %d %lld %lld", &n, &L, &T);

    vector<ll> x(n);
    vector<int> w(n);
    rep(i,n) scanf(" %lld %d", &x[i], &w[i]);

    vector<pl> ant_pos(n);
    rep(i,n)
    {
        if(w[i]==1) ant_pos[i] = pl((x[i]+T)%L,i);
        else ant_pos[i] = pl((x[i]-T+L*1000000000LL)%L,-i);
    }
    sort(all(ant_pos));

    for(int i=1; i<n; ++i)
    {
        if(w[0] != w[i])
        {
            ll d;
            if(w[0]==1) d=x[i]-x[0];
            else d=x[0]+L-x[i];

            ll add = 0;

            ll dist = 2*T;
            dist -= d;

            if(dist<0) continue;

            ++add;
            add += dist/L;

            if(w[0]==1) (ct+=add)%=n;
            else ct = (ct-add+n*1000000000LL)%n;
        }
    }

    int idx=0;
    while(idx<n && ant_pos[idx].se!=0) ++idx;

    idx = (idx-ct+n)%n;

    rep(i,n) printf("%lld\n", ant_pos[(i+idx)%n].fi);
    return 0;
}
