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
    int n,m;
    scanf(" %d %d", &n, &m);
    vector<int> a(n),x(m);
    rep(i,n) scanf(" %d", &a[i]);
    rep(i,m) scanf(" %d", &x[i]);

    map<int,ll> ct,now;
    rep(i,n)
    {
        map<int,ll> nx;
        for(const auto &p:now)
        {
            ll g = __gcd(p.fi,a[i]);
            nx[g] += p.se;
        }
        ++nx[a[i]];

        now = nx;
        for(const auto &p:now) ct[p.fi] += p.se;
    }

    rep(i,m) printf("%lld\n", ct[x[i]]);
    return 0;
}
