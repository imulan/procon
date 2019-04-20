#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define pb push_back

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<ll> t(n),b(m);
    rep(i,n) scanf(" %lld", &t[i]);
    rep(i,m) scanf(" %lld", &b[i]);

    ll ans = 0;

    int idx = 0;
    if(b[0]<=t[0]){
        ans += 2*(t[0]-b[0]);
        while(idx<m && b[idx]<=t[0]) ++idx;
    }

    for(int i=1; i<n; ++i){
        vector<ll> pos;
        pos.pb(t[i-1]);
        while(idx<m && b[idx]<=t[i]){
            pos.pb(b[idx]);
            ++idx;
        }
        pos.pb(t[i]);

        int P = pos.size();
        ll add = t[i]-t[i-1];
        rep(j,P-1){
            ll tmp = 2*(pos[j]-t[i-1]) + 2*(t[i]-pos[j+1]);
            add = min(add, tmp);
        }
        ans += add;
    }

    if(t[n-1] < b[m-1]) ans += 2*(b[m-1]-t[n-1]);
    printf("%lld\n", ans);
    return 0;
}