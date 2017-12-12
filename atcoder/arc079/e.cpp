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

vl f(const vl &v)
{
    int n = v.size();
    vl r(v);

    r[n-1] -= n;
    rep(i,n-1) ++r[i];
    sort(all(r));
    return r;
}

bool valid(const vl &v)
{
    int n = v.size();
    return v[n-1]<n;
}

void test(const vl &V)
{
    vl v = V;

    int n = v.size();
    int ct = 0;
    while(!valid(v))
    {
        v = f(v);
        int D = v[n-1]-v[0];
        printf("%3d: diff: %3d ", ++ct, D);
        // if(D<n) break;
        dbg(v);
    }
}

ll solve(const vl &V)
{
    vl v = V;
    int n = v.size();

    ll ret = 0;

    for(int i=n-1; i>0; --i)
    {
        if(valid(v)) break;

        ll step = n-i;
        ll dec = i+1;

        ll x = (v[i]-v[i-1])/(step+dec);

        ret += step*x;
        rep(j,i) v[j] += x*step;
        for(int j=i; j<n; ++j) v[j] -= x*dec;
        sort(all(v));
    }

    if(!valid(v))
    {
        while(!valid(v) && v[n-1]-v[0]>=2*n)
        {
            ++ret;
            v = f(v);
        }

        ll LIM = 2*n;
        ll y = v[n-1]-LIM;
        if(y>0)
        {
            ret += y*n;
            rep(i,n) v[i] -= y;
        }

        while(!valid(v))
        {
            ++ret;
            v = f(v);
        }
    }

    return ret;
}

int main()
{
    int n;
    cin >>n;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    sort(all(a));

    // test(a);
    cout << solve(a) << endl;
    return 0;
}
