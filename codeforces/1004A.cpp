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
    ll d;
    cin >>n >>d;

    vector<ll> x(n);
    rep(i,n) cin >>x[i];

    int ans = 2;
    rep(i,n-1){
        ll w = x[i+1]-x[i];

        if(w>2*d) ans += 2;
        else if(w==2*d) ++ans;
    }
    cout << ans << endl;
    return 0;
}
