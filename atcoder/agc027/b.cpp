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

const ll INF = LLONG_MAX/3;

int main(){
    int n;
    ll X;
    cin >>n >>X;

    vector<ll> x(n);
    rep(i,n) cin >>x[i];

    ll ans = INF;
    for(int i=1; i<=n; ++i){
        ll t = X*i;



        ans = min(ans, t);
    }
    cout << ans+X*n << endl;
    return 0;
}
