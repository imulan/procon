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

const double PI = acos(-1);

map<ll,int> factorize(ll n)
{
    map<ll,int> ret;

    ll t = n;
    for(ll i=2; i*i<=n; ++i)
    {
        while(t%i==0)
        {
            ++ret[i];
            t/=i;
        }
    }
    if(t>1) ++ret[t];

    return ret;
}

double stirling(ll n)
{
    return n*(log(n)-1) + log(sqrt(2*PI*n));
}

ll num(ll n, ll prime)
{
    ll a = prime;
    ll ret = 0;
    while(a<=n)
    {
        ret += n/a;
        a*=prime;
    }
    return ret;
}

double fact(ll n)
{
    if(n==1) return 0;
    return log(n) + fact(n-1);
}

int main()
{
    ll n,m;
    cin >>n >>m;

    ll ct = LLONG_MAX;
    for(const auto &p:factorize(m)) ct = min(ct, num(n,p.fi)/p.se);

    double v;
    if(n<100000) v = fact(n);
    else v = stirling(n);
    v -= ct*log(m);
    v /= log(10);

    ll d = v;
    double ans = pow(10,v-d);

    printf("%.10fe%lld\n", ans,d);
    return 0;
}
