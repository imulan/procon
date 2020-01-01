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
    cin >>n;

    vector<ll> b(n/2);
    rep(i,n/2) cin >>b[i];

    vector<ll> l,h;
    l.pb(0);
    h.pb(b[0]);
    for(int i=1; i<n/2; ++i){
        ll nl = max(l[i-1], b[i]-h[i-1]);

        l.pb(nl);
        h.pb(b[i]-nl);
    }

    reverse(all(h));
    for(ll i:h) l.pb(i);
    rep(i,n) cout << l[i] << " \n"[i==n-1];
    return 0;
}
