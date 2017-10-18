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

const ll mod = 1e9+7;

map<ll,int> factorize(ll n)
{
    map<ll,int> r;
    ll t = n;
    for(int i=2; i*i<=n; ++i)
    {
        while(t%i==0)
        {
            ++r[i];
            t/=i;
        }
    }
    if(t>1) ++r[t];
    return r;
}

ll mod_pow(ll x, ll n)
{
    ll r = 1;
    while(n)
    {
        if(n&1) (r*=x)%=mod;
        (x*=x)%=mod;
        n>>=1;
    }
    return r;
}

int main()
{
    int n,k;
    cin >>n >>k;

    vector<map<ll,int>> a(n);
    vector<ll> p;
    rep(i,n)
    {
        ll x;
        cin >>x;
        map<ll,int> m = factorize(x);

        a[i] = m;
        for(const auto &v:m) p.pb(v.fi);
    }

    sort(all(p));
    p.erase(unique(all(p)),p.end());

    ll ans = 1;
    for(ll i:p)
    {
        priority_queue<int> pq;
        rep(j,n)
        {
            int val = 0;
            if(a[j].count(i)) val = a[j][i];
            pq.push(val);
        }

        int ct = 0;
        rep(j,k)
        {
            ct += pq.top();
            pq.pop();
        }

        (ans*=mod_pow(i,ct))%=mod;
    }
    cout << ans << endl;
    return 0;
}
