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
    ll w;
    cin >>n >>w;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    rep(i,n-1) a[i+1] += a[i];

    ll mn = 0, mx = 0;
    rep(i,n){
        mn = min(mn,a[i]);
        mx = max(mx,a[i]);
    }

    ll R = w-mx, L = -mn;
    cout << max(0LL,R-L+1) << endl;
    return 0;
}
