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
    cin.tie(0); ios::sync_with_stdio(false);
    int n;
    ll a,b,k;
    cin >>n >>a >>b >>k;

    ll mod = a+b;

    vector<ll> s(n);
    rep(i,n){
        ll h;
        cin >>h;

        if(h <= a) s[i] = 0;
        else{
            ll r = h%mod;
            if(1<=r && r<=a) s[i] = 0;
            else{
                if(r == 0) r = mod;
                s[i] = (r+a-1)/a - 1;
            }
        }
    }
    sort(all(s));

    int ans = 0;
    rep(i,n){
        if(k >= s[i]){
            k -= s[i];
            ++ans;
        }
    }
    cout << ans << "\n";
    return 0;
}
