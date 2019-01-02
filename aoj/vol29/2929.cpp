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
    int n,m;
    cin >>n >>m;
    vector<int> a(n),b(n);
    rep(i,n) cin >>a[i] >>b[i];
    vector<int> c(m),d(m);
    rep(i,m) cin >>c[i] >>d[i];

    vector<int> x(n+1, n);
    rep(i,m){
        int idx = lower_bound(all(a), c[i]) - a.begin();
        x[idx] = min(x[idx], d[i]);
    }

    rep(i,n) x[i+1] = min(x[i+1], x[i]);

    set<int> s;
    for(int i=n-1; i>=0; --i){
        s.insert(b[i]);
        if(s.size() == x[i]) s.erase(s.begin());
    }

    ll ans = 0;
    for(int i:s) ans += i;
    cout << ans << endl;
    return 0;
}
