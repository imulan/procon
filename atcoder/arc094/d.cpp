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

const ll LIM = 1e9+4;
ll find(ll X){
    ll l=0, r=LIM;
    while(r-l>1){
        ll m =(l+r)/2;
        if(m*m < X) l=m;
        else r=m;
    }
    return l;
}

ll solve(){
    ll a,b;
    cin >>a >>b;
    if(a>b) swap(a,b);

    ll x = find(a*b);

    ll ans = x;
    if(a<=x) --ans;

    ll y = (a*b-1)/(x+1);
    ans += y;
    if(b<=y) --ans;

    // dbg(x);
    // dbg(y);
    return ans;
}

int main(){
    int Q;
    cin >>Q;
    rep(i,Q) cout << solve() << "\n";
    return 0;
}
