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

ll calc(ll T, int n, const vector<ll> &s, const vector<ll> &t)
{
    vector<ll> sum(n+1);
    rep(i,n) sum[i+1] = sum[i]+(t[i]-s[i]);

    ll ret = 0;

    rep(i,n)
    {
        ll F = s[i]+T;
        int idx = lower_bound(all(s),F)-s.begin()-1;

        ll x = sum[idx]-sum[i];
        if(idx<n)
        {
            if(s[idx]<F) x+=(min(F,t[idx])-s[idx]);
        }

        // printf(" %d %d , x= %lld\n", i,idx,x);
        ret = max(ret,x);
    }

    return ret;
}

int main()
{
    ll T;
    int n;
    cin >>T >>n;
    vector<ll> s(n),t(n);
    rep(i,n) cin >>s[i] >>t[i];

    ll ans = 0;
    ans = max(ans, calc(T,n,s,t));

    rep(i,n)
    {
        s[i] = -s[i];
        t[i] = -t[i];
        swap(s[i],t[i]);
    }
    reverse(all(s));
    reverse(all(t));

    // rep(i,n) printf(" %d: %d ~ %d\n", i,s[i],t[i]);
    ans = max(ans, calc(T,n,s,t));

    cout << ans << endl;
    return 0;
}
