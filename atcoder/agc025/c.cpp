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
    cin >>n;
    vector<int> l(n),r(n);
    rep(i,n) cin >>l[i] >>r[i];
    l.pb(0);
    r.pb(0);
    ++n;

    sort(all(l), greater<int>());
    sort(all(r));

    ll ans = 0;
    ll t = 0;
    rep(i,n){
        t += 2*(l[i]-r[i]);
        ans = max(ans, t);
    }
    cout << ans << endl;
    return 0;
}
