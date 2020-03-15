#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

int main(){
    int n;
    scanf(" %d", &n);
    vector<ll> a(n);
    rep(i,n) scanf(" %lld", &a[i]);

    auto calc = [&](){
        vector<pair<ll,int>> v(n);
        rep(i,n) v[i] = {a[i],i};
        sort(all(v));

        set<int> s;
        s.insert(0);

        vector<ll> dp(n+1);
        rep(i,n){
            ll x = v[i].fi;
            int idx = v[i].se;

            auto itr = s.lower_bound(idx+1);
            --itr;
            int t = *itr;

            dp[idx+1] = x*(idx+1-t)+dp[t];
            s.insert(idx+1);
        }
        return dp;
    };

    vector<ll> pre = calc();
    reverse(all(a));
    vector<ll> suf = calc();
    reverse(all(a));

    ll mx = -1;
    int idx = -1;
    rep(i,n){
        ll v = pre[i+1]+suf[n-i]-a[i];
        if(mx < v){
            mx = v;
            idx = i;
        }
    }

    for(int i=idx; i+1<n; ++i) a[i+1] = min(a[i+1], a[i]);
    for(int i=idx; i-1>=0; --i) a[i-1] = min(a[i-1], a[i]);
    rep(i,n) printf("%lld%c", a[i], " \n"[i==n-1]);
    return 0;
}
