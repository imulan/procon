#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()

const ll INF = LLONG_MAX/3;

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<ll> a(n);
    rep(i,n) scanf(" %lld", &a[i]);

    vector<ll> aa(2*n);
    rep(i,n){
        aa[i] = a[i];
        aa[n+i] = a[i];
    }

    vector<ll> pa(2*n+1);
    rep(i,2*n) pa[i+1] = pa[i]+aa[i];

//    rep(i,2*n+1) printf(" %d: %lld\n", i,pa[i]);

    auto calc = [&](int s){
//        printf("  CALC %lld\n",pa[s+n/2] - pa[s]);
        return pa[s+n/2] - pa[s];
    };

    ll ans = calc(0);
    int x = 0;

    rep(i,m){
        int k;
        scanf(" %d", &k);

        x += k-1;
        x %= n;
//        printf(" x %d\n",x);
        ans = max(ans, calc(x));
    }

    printf("%lld\n", ans);
    return 0;
}