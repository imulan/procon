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

const ll mod = 1e9+7;

int main(){
    string s;
    cin >>s;
    int n = s.size();

    vector<ll> pw(n+1);
    pw[0] = 1;
    rep(i,n) pw[i+1] = pw[i]*3%mod;

    int q = 0;
    rep(i,n) q += (s[i]=='?');

    // 0:CHAR, 1:'?' (A:pre, C:suf)
    ll a[2]={0,0}, c[2]={0,q};
    rep(i,n) c[0] += (s[i]=='C');

    ll ans = 0;
    rep(i,n){
        if(s[i]=='?') --c[1];
        if(s[i]=='C') --c[0];

        if(s[i]=='B' || s[i]=='?'){
            rep(j,2)rep(k,2){
                int qq = q-j-k-(s[i]=='?');
                if(qq<0) continue;

                ll add = a[j]*c[k]%mod;
                (add *= pw[qq]) %= mod;
                (ans += add) %= mod;
            }
        }

        if(s[i]=='?') ++a[1];
        if(s[i]=='A') ++a[0];
    }

    cout << ans << endl;
    return 0;
}
