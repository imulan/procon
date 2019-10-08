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
    ll n,m;
    cin >>n >>m;

    ll num = n/m;

    ll x = 0;
    bool ap[10]={};
    vector<ll> v;
    while(1){
        x += m;
        x %= 10;
        if(ap[x]) break;
        v.pb(x);
        ap[x] = true;
    }

    int V = v.size();
    ll ans = 0;
    rep(i,V){
        ll c = num/V;
        if(i < num%V) ++c;
        ans += v[i]*c;
    }
    return ans;
}

int main(){
    int q;
    cin >>q;
    while(q--) cout << solve() << "\n";
    return 0;
}
