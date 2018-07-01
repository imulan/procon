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

const ll INF = LLONG_MAX/3;

int main(){
    int n;
    cin >>n;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    ll U = 0;
    rep(i,n) U+=a[i];

    vector<ll> pre(a);
    rep(i,n-1) pre[i+1] += pre[i];

    vector<ll> pq(n);
    for(int i=1; i<n; ++i){

        auto itr = lower_bound(all(pre),(pre[i]+1)/2);
        pq[i] = *itr;

        if(itr != pre.begin()){
            --itr;
            ll P = *itr;
            ll Q = pre[i]-P;

            if(abs(P-Q)< abs(pq[i]-(pre[i]-pq[i]))) pq[i] = P;
        }
    }
    // dbg(pq);

    vector<ll> suf(a);
    for(int i=n-1; i>0; --i) suf[i-1] += suf[i];
    reverse(all(suf));
    // dbg(suf);
    vector<ll> rs(n);
    for(int i=1; i<n; ++i){

        auto itr = lower_bound(all(suf),(suf[i]+1)/2);
        rs[i] = *itr;

        if(itr != suf.begin()){
            --itr;
            ll P = *itr;
            ll Q = suf[i]-P;

            if(abs(P-Q)< abs(rs[i]-(suf[i]-rs[i]))) rs[i] = P;
        }
    }
    reverse(all(rs));
    // dbg(rs);

    ll ans = INF;
    for(int i=2; i<=n-2; ++i){
        ll P = pq[i-1];
        ll Q = pre[i-1]-P;
        ll S = rs[i];
        ll R = U-P-Q-S;

        // printf(" %lld %lld %lld %lld\n",P,Q,R,S);
        ans = min(ans, max({P,Q,R,S})-min({P,Q,R,S}));
    }
    cout << ans << endl;
    return 0;
}
