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

int main(){
    ll a,b,c;
    int x,y;
    cin >>a >>b >>c >>x >>y;

    ll ans = LLONG_MAX;
    rep(i,100001){
        ll t = c*2*i;
        t += a*max(0,x-i);
        t += b*max(0,y-i);
        ans = min(ans, t);
    }
    cout << ans << endl;
    return 0;
}
