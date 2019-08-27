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

ll solve(){
    ll k,n,a,b;
    scanf(" %lld %lld %lld %lld", &k, &n, &a, &b);

    if(b*n >= k) return -1;
    ll ok = 0, ng = n+1;
    while(ng-ok>1){
        ll mid = (ok+ng)/2;
        if(mid*a + (n-mid)*b < k) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
    int q;
    scanf(" %d", &q);
    while(q--) printf("%lld\n", solve());
    return 0;
}
