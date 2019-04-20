#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

#define X first
#define Y second

const ll INF = LLONG_MAX/3;

using P = pair<ll,ll>;

P READ(){
    ll x,y;
    scanf(" %lld %lld", &x, &y);
    return P(x,y);
}

int main(){
    P tv = READ();

    auto dist_tv = [&](P p){
        ll xx = p.X - tv.X;
        ll yy = p.Y - tv.Y;
        return xx*xx + yy*yy;
    };

    int n;
    scanf(" %d", &n);

    map<P,vector<P>> liz;
    rep(i,n){
        P p = READ();
        ll h;
        scanf(" %lld", &h);

        ll dx = p.X - tv.X;
        ll dy = p.Y - tv.Y;

        ll G = __gcd(abs(dx),abs(dy));
        dx /= G;
        dy /= G;

        ll dist = dist_tv(p);
        liz[{dx,dy}].pb({dist,h});
    }

    auto LIS = [&](const vector<ll> &x){
        int X = x.size();

        vector<ll> dp(X+1,INF);
        dp[0] = 0;
        rep(i,X){
            int idx = lower_bound(all(dp), x[i]) - dp.begin();
            dp[idx] = x[i];
        }

        int ans = 0;
        rep(i,X+1)if(dp[i]<INF) ans = i;
        return ans;
    };

    int ans = 0;
    for(const auto &pp:liz){
        vector<P> v = pp.se;
        sort(all(v));

        vector<ll> a;
        for(const auto l:v) a.pb(l.se);
        ans += LIS(a);
    }
    printf("%d\n", ans);
    return 0;
}