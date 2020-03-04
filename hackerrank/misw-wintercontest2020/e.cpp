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

const ll mod = 1e9+7;

int main(){
    int n;
    scanf(" %d", &n);

    map<int,int> m;
    rep(i,n){
        int a;
        scanf(" %d", &a);
        ++m[a];
    }

    vector<int> v;
    for(const auto &p:m) v.pb(p.se);
    const int V = v.size();

    ll ans = 1;
    rep(i,V){
        rep(j,v[i]-2) (ans *= v[i]) %= mod;
        if(i+1<V) (ans *= v[i]*v[i+1]%mod) %= mod;
    }

    printf("%lld\n", ans);
    return 0;
}
