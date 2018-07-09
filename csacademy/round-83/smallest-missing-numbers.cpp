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

const ll LIM = 101010101010LL;

ll f(ll x){
    return x*(x+1)/2;
}

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<ll> a(n);
    rep(i,n) scanf(" %lld", &a[i]);
    a.pb(LIM);
    ++n;
    sort(all(a));

    ll ans = 0;
    ll now = 1;
    ll ct = 0;
    rep(i,n){
        ll d = a[i]-now;
        if(ct+d>=m){
            ans += f(now+m-ct-1)-f(now-1);
            ct = m;
            break;
        }
        else{
            ans += f(a[i]-1)-f(now-1);
            ct += d;
        }

        now = a[i]+1;
    }

    cout << ans << endl;
    return 0;
}
