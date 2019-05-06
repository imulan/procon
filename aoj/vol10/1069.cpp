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

using L = __int128;

int main(){
    int n;
    while(scanf(" %d", &n),n){
        vector<vector<ll>> b(n+1, vector<ll>(n+1));
        rep(i,n+1){
            for(int j=i+1; j<n+1; ++j) scanf(" %lld", &b[i][j]);
        }

        L sq_a0 = (L)b[0][1]*b[0][2];
        sq_a0 /= b[1][2];

        ll ng=0, ok=(1LL<<31)-1;
        while(ok-ng>1){
            ll mid = (ng+ok)/2;
            if(sq_a0 <= mid*mid) ok = mid;
            else ng = mid;
        }

        ll a0 = ok;
        printf("%lld\n", a0);

        vector<ll> a;
        for(int i=1; i<=n; ++i) a.pb(b[0][i]/a0);
        sort(all(a));
        rep(i,n) printf("%lld%c", a[i], " \n"[i==n-1]);
    }
    return 0;
}
