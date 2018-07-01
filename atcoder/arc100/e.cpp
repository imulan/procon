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

using P = pair<int,int>;

int main(){
    int n;
    cin >>n;

    int sz = 1<<n;
    vector<ll> a(sz);
    rep(i,sz) cin >>a[i];

    vector<P> top2(sz);
    rep(i,sz) top2[i] = {i,-1};

    auto UPD = [&](P p, P q, int idx){
        vector<int> v;
        v.pb(q.fi);
        if(q.se != -1) v.pb(q.se);
        v.pb(idx);

        for(int ii:v){
            if(ii==p.fi || ii==p.se) continue;

            if(a[ii]>a[p.fi]){
                p.se = p.fi;
                p.fi = ii;
            }
            else{
                if(p.se==-1 || a[ii]>a[p.se]){
                    p.se = ii;
                }
            }
        }
        return p;
    };

    rep(mask,sz){
        rep(i,n)if(!(mask>>i&1)){
            int nmask = mask|(1<<i);
            top2[nmask] = UPD(top2[nmask], top2[mask], nmask);
        }
        // dbg(top2[mask]);
    }
    // dbg(top2);

    vector<ll> dp(sz);
    dp[0] = a[0];
    for(int i=1; i<sz; ++i){
        dp[i] = a[top2[i].fi] + a[top2[i].se];
    }

    rep(mask,sz){
        rep(i,n)if(!(mask>>i&1)){
            int nmask = mask|(1<<i);
            dp[nmask] = max({dp[nmask], dp[mask]});
        }
    }
    for(int i=1; i<sz; ++i) dp[i] = max(dp[i], dp[i-1]);

    for(int i=1; i<sz; ++i) cout << dp[i] << "\n";
    return 0;
}
