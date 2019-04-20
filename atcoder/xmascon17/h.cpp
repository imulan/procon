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

using pi = pair<int,int>;

bool ok(const vector<ll> &v, const set<ll> &s, ll x)
{
    rep(i,v.size())if(s.count(x+v[i])) return false;
    return true;
}

int SZ = 200000;

// a(n) = 20*n^2-4*n+2, for n>0.
// ll b3(ll n)
// {
//     if(n==0) return 0;
// }

vector<ll> test()
{
    vector<ll> v;
    v.pb(0);

    ll x = v[0]+1;
    set<ll> s;
    while(v.size()<SZ)
    {
        if(ok(v,s,x))
        {
            rep(i,v.size()) s.insert(x+v[i]);

            dbg(x-v.back());

            v.pb(x);
            // printf(" %d: %d\n", v.size(), x);
        }
        ++x;
    }

    // dbg(v);
    return v;
}

int main()
{
    vector<ll> x = test();
    int n;
    ll m;
    scanf(" %d %lld", &n, &m);

    rep(i,n) printf("%lld%c", x[i], " \n"[i==n-1]);
    fflush(stdout);

    map<ll,pi> F;
    rep(i,n)rep(j,i) F[x[i]+x[j]] = {j+1,i+1};

    int Q;
    scanf(" %d", &Q);
    while(Q--)
    {
        ll val;
        scanf(" %lld", &val);
        printf("%d %d\n", F[val].fi, F[val].se);
        fflush(stdout);
    }
    return 0;
}
