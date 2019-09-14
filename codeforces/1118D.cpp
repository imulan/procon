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
    int n,m;
    scanf(" %d %d", &n, &m);
    vector<ll> a(n);
    rep(i,n) scanf(" %lld", &a[i]);
    sort(all(a), greater<ll>());

    ll sa = 0;
    for(ll i:a) sa += i;
    if(sa < m){
        printf("-1\n");
        return 0;
    }

    int ng=0, ok=n;
    while(ok-ng>1){
        int x = (ng+ok)/2;
        vector<vector<ll>> v(x);
        rep(i,n) v[i%x].pb(a[i]);

        ll s = 0;
        rep(i,x){
            int V = v[i].size();
            rep(j,V) s += max(0LL, v[i][j]-j);
        }

        if(s>=m) ok = x;
        else ng = x;
    }
    printf("%d\n", ok);
    return 0;
}
