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

bool tri(const vector<ll> &x)
{
    return x[0]+x[1]>x[2];
}

bool check(const vector<ll> &v)
{
    // dbg(v);
    int comb = (1<<3) - 1;
    while(comb < (1<<6)-1)
    {
        vector<ll> p,q;
        rep(i,6)
        {
            if(comb>>i&1) p.pb(v[i]);
            else q.pb(v[i]);
        }
        // dbg(p);dbg(q);
        if(tri(p) && tri(q)) return true;

        int x = comb & -comb, y = comb + x;
        comb = ((comb & ~y) / x>>1) | y;
    }
    return false;
}

ll SUM(const vector<ll> &v)
{
    ll ret = 0;
    for(ll i:v) ret += i;
    return ret;
}

int main()
{
    int n;
    cin >>n;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];
    sort(all(a));

    vector<int> ok;
    for(int i=2; i<n; ++i)
    {
        vector<ll> v;
        rep(j,3) v.pb(a[i-2+j]);
        if(tri(v)) ok.pb(i);
    }

    ll ans = 0;
    rep(i,n-5)
    {
        vector<ll> v;
        rep(j,6) v.pb(a[i+j]);
        if(check(v)) ans = max(ans,SUM(v));
    }

    if(ok.size()>0)
    {
        for(int i=n-1; i>=2; --i)
        {
            if(*lower_bound(all(ok),i) == i)
            {
                int idx = lower_bound(all(ok),i-2)-ok.begin();
                --idx;
                if(idx>=0)
                {
                    vector<ll> v;
                    rep(j,3) v.pb(a[ok[idx]-2+j]);
                    rep(j,3) v.pb(a[i-2+j]);
                    ans = max(ans,SUM(v));
                }
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}
