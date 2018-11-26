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
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    ll sa = 0;
    rep(i,n) sa += a[i];

    multiset<ll> s;
    rep(i,n) s.insert(a[i]);

    vector<int> ans;
    rep(i,n){
        sa -= a[i];
        s.erase(s.find(a[i]));

        ll mx = *s.rbegin();
        if(mx == sa-mx) ans.pb(i+1);

        sa += a[i];
        s.insert(a[i]);
    }

    int A = ans.size();
    cout << A << '\n';
    rep(i,A){
        if(i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}
