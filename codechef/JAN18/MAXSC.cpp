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

ll solve(){
    int n;
    cin >>n;

    vector<vector<ll>> a;
    rep(i,n){
        vector<ll> x(n);
        rep(j,n) cin >>x[j];
        sort(all(x));
        a.pb(x);
    }

    ll ans = -1;
    rep(i,n){
        bool ok = true;
        ll val = a[n-1][i];
        ll t = val;
        for(int j=n-2; j>=0; --j){
            int idx = upper_bound(all(a[j]),val-1)-a[j].begin();
            if(idx == 0){
                ok = false;
                break;
            }
            
            val = a[j][idx-1];
            t += val;
        }
        if(ok) ans = max(ans,t);
    }
    return ans;
}

int main(){
    int T;
    cin >>T;
    while(T--) cout << solve() << endl;
    return 0;
}
