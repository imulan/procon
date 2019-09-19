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

ll solve(){
    int n;
    cin >>n;
    vector<ll> d(n);
    rep(i,n) cin >>d[i];
    sort(all(d));

    ll x = d[0]*d[n-1];

    vector<ll> div;
    for(ll i=2; i*i<=x; ++i){
        if(x%i == 0){
            div.pb(i);
            if(i!=x/i) div.pb(x/i);
        }
    }
    sort(all(div));

    if(div != d) return -1;
    return x;
}

int main(){
    int t;
    cin >>t;
    while(t--) cout << solve() << "\n";
    return 0;
}
