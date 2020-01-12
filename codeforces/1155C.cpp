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

    vector<ll> x(n),p(m);
    rep(i,n) scanf(" %lld", &x[i]);
    rep(i,m) scanf(" %lld", &p[i]);

    ll g = 0;
    rep(i,n-1) g = __gcd(g,x[i+1]-x[i]);

    rep(i,m){
        if(g%p[i] == 0){
            printf("YES\n%lld %d\n", x[0], i+1);
            return 0;
        }
    }

    printf("NO\n");
    return 0;
}
