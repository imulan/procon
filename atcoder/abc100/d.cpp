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

using vl = vector<ll>;

int main(){
    int n,m;
    cin >>n >>m;

    vector<vl> c(n);
    rep(i,n){
        vl v(3);
        rep(j,3) cin >>v[j];
        c[i] = v;
    }

    ll ans = 0;
    rep(mask,1<<3){
        vl t;
        rep(i,n){
            ll v = 0;
            rep(j,3){
                if(mask>>j&1) v += c[i][j];
                else v -= c[i][j];
            }
            t.pb(v);
        }

        sort(all(t), greater<ll>());

        ll x = 0;
        rep(j,m) x += t[j];
        ans = max(ans, x);
    }
    cout << ans << endl;
    return 0;
}
