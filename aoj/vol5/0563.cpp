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

int main()
{
    int w,h,n;
    scanf(" %d %d %d", &w, &h, &n);

    vector<int> x(n),y(n);
    rep(i,n) scanf(" %d %d", &x[i], &y[i]);

    vector<int> sorted_x(x), sorted_y(y);
    sort(all(sorted_x));
    sort(all(sorted_y));

    vector<int> cx,cy;

    if(n%2==0)
    {
        cx.pb(sorted_x[n/2-1]);
        cy.pb(sorted_y[n/2-1]);
    }
    cx.pb(sorted_x[n/2]);
    cy.pb(sorted_y[n/2]);

    ll ans = LLONG_MAX;
    int ax,ay;
    for(const auto &X:cx)for(const auto &Y:cy)
    {
        ll s = 0;
        ll D = 0;
        rep(i,n)
        {
            ll d = abs(X-x[i])+abs(Y-y[i]);
            D = max(D,d);
            s += d*2;
        }
        s -= D;

        if(ans>s)
        {
            ans = s;
            ax = X;
            ay = Y;
        }
    }

    printf("%lld\n%d %d\n", ans,ax,ay);
    return 0;
}
