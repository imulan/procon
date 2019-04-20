#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(int)n; ++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    int n;
    cin >>n;
    vector<int> p(n);
    rep(i,n) cin >>p[i];

    map<ll,ll> m;
    rep(i,n) ++m[p[i]];

    auto itr = m.end();
    --itr;

    ll ans = ((*itr).fi)*((*itr).se);
    rep(i,n)if(p[i]>0)
    {
        for(int j:vector<int>({-1,1}))
        {
            int nx = i+j;
            if(nx<0 || n<=nx) continue;

            --m[p[i]];
            if(m[p[i]]==0) m.erase(p[i]);

            --m[p[nx]];
            if(m[p[nx]]==0) m.erase(p[nx]);
            ++m[p[i]-1];
            ++m[p[nx]+1];

            itr = m.end();
            --itr;

            ll t = ((*itr).fi)*((*itr).se);
            // printf(" ! %d %d %lld\n", i,j,t);

            // for(const auto &pp:m) printf(" [%d %d]", pp.fi,pp.se);
            // printf("\n");

            ans = min(ans,t);

            ++m[p[i]];
            ++m[p[nx]];
            --m[p[i]-1];
            if(m[p[i]-1]==0) m.erase(p[i]-1);
            --m[p[nx]+1];
            if(m[p[nx]+1]==0) m.erase(p[nx]+1);
        }
    }

    cout << ans << endl;
}
