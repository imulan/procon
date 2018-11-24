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

int main(){
    int n,K;
    cin >>n >>K;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    vector<ll> b;
    rep(i,n){
        ll t = 0;
        for(int j=i; j<n; ++j){
            t += a[j];
            b.pb(t);
        }
    }

    sort(all(b));
    reverse(all(b));
    int B = b.size();
    // dbg(b);

    ll ans = 0;
    for(int i=39; i>=0; --i){
        int ct = 0;
        rep(j,B)if(b[j]>>i&1) ++ct;

        if(ct<K) continue;

        ans |= 1LL<<i;
        vector<ll> r;
        rep(j,B)if(b[j]>>i&1) r.pb(b[j]);

        for(int j=i-1; j>=0; --j){
            int R = r.size();

            ct = 0;
            rep(k,R)if(r[k]>>j&1) ++ct;

            if(ct>=K){
                vector<ll> nr;
                rep(k,R)if(r[k]>>j&1) nr.pb(r[k]);

                ans |= 1LL<<j;
                r = nr;
            }
        }

        break;
    }
    cout << ans << endl;
    return 0;
}
