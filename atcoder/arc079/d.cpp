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

using vl = vector<ll>;

vl b(const vl &v)
{
    int n = v.size();

    vl r(v);
    r[0]+=n;
    for(int i=1; i<n; ++i) --r[i];

    sort(all(r));
    return r;
}

int main()
{
    ll k;
    cin >>k;

    int n = 50;
    ll num = k/n;
    vl a(n,num+49);
    k -= num*n;

    while(k--) a = b(a);

    printf("%d\n", n);
    rep(i,n) printf("%lld%c", a[i], " \n"[i==n-1]);
    return 0;
}
