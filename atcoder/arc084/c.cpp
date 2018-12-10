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

vector<int> READ(int n){
    vector<int> x(n);
    rep(i,n) cin >>x[i];
    sort(all(x));
    return x;
}

int main(){
    int n;
    cin >>n;

    vector<int> v[3];
    rep(i,3) v[i] = READ(n);

    ll ans = 0;
    rep(i,n){
        int sz = v[1][i];
        ll x = lower_bound(all(v[0]), sz) - v[0].begin();
        ll y = n - (upper_bound(all(v[2]), sz) - v[2].begin());
        ans += x*y;
    }
    cout << ans << endl;
    return 0;
}
