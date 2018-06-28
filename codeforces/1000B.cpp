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
    int n;
    ll m;
    cin >>n >>m;

    vector<ll> a;
    a.pb(0);
    rep(i,n){
        ll x;
        cin >>x;
        a.pb(x);
    }
    a.pb(m);

    int A = a.size();
    ll def = 0;
    vector<ll> s(A);
    vector<ll> pre(A);
    rep(i,A-1){
        if(i%2==0){
            def += a[i+1]-a[i];
            s[i] += a[i+1]-a[i];
            pre[i+1] += a[i+1]-a[i];
        }
    }

    rep(i,A-1) pre[i+1] += pre[i];
    for(int i=A-1; i>0; --i) s[i-1] += s[i];
    // dbg(def);

    ll ans = def;

    for(int i=1; i<A; i+=2){
        ll t = a[i]-1;
        if(a[i-1]<t){
            ll tmp = pre[i] + (m-a[i]-s[i]-1);
            ans = max(ans, tmp);
            // printf(" %lld: %lld\n",t,tmp);
        }

        t = a[i]+1;
        if(i+1<A && t<a[i+1]){
            ll tmp = pre[i] + (m-a[i]-s[i]-1);
            ans = max(ans, tmp);
            // printf(" %lld: %lld\n",t,tmp);
        }
    }

    cout << ans << endl;
    return 0;
}
