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

const int LIM = 200000;

vector<ll> f(ll n)
{
    vector<ll> d;
    for(ll i=1; i*i<=n; ++i)
    {
        if(n%i==0)
        {
            d.pb(i);
            if(n/i != i) d.pb(n/i);
        }
    }
    sort(all(d));
    reverse(all(d));
    return d;
}

ll s(ll x)
{
    return x*(x+1)/2;
}

void solve(ll n, ll k)
{
    if(k>LIM || s(k)>n)
    {
        printf("-1\n");
        return;
    }

    vector<ll> ans(k);
    for(ll i:f(n))
    {
        ll rem = n;
        rem -= i*s(k);

        // dbg(i);
        // dbg(rem);
        if(rem<0) continue;

        if(rem%i==0)
        {
            ll t = n;
            rep(j,k)
            {
                ans[j] = i*(j+1);
                t -= ans[j];
            }

            ans[k-1] += t;
            break;
        }
    }

    rep(i,k) printf("%lld%c", ans[i], " \n"[i==k-1]);
}

int main()
{
    ll n,k;
    cin >>n >>k;
    solve(n,k);
    return 0;
}
