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

const ll LIM = 100000000000000LL; // 10^14

int main()
{
    int n,k;
    scanf(" %d %d", &n, &k);
    vector<ll> a(n);
    rep(i,n) scanf(" %lld", &a[i]);

    vector<ll> sa(n);
    sa[0] = a[0];
    for(int i=1; i<n; ++i) sa[i] = sa[i-1]+a[i];

    map<ll,int> ct;
    rep(i,n) ++ct[sa[i]];

    int loop_lim = 50;
    if(k==1) loop_lim = 1;
    if(k==-1) loop_lim = 2;

    vector<ll> check;
    ll x = 1;
    rep(_,loop_lim)
    {
        if(abs(x)>LIM) break;
        check.pb(x);
        x*=k;
    }
    int C = check.size();

    ll ans = 0;
    ll d = 0;
    rep(i,n)
    {
        rep(j,C)
        {
            ll c = check[j];
            if(ct.count(c+d)) ans += ct[c+d];
        }
        d += a[i];
        --ct[sa[i]];
    }
    printf("%lld\n", ans);
    return 0;
}
