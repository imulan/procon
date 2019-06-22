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
    ll p,n;
    cin >>p >>n;

    ll a = 0;
    vector<bool> vis(p);
    for(ll i=0; i<=min(2*p,n); ++i){
        (a += i) %= p;
        vis[a] = true;
    }

    int ans = 0;
    rep(i,p)if(vis[i]) ++ans;
    cout << ans << "\n";
    return 0;
}
