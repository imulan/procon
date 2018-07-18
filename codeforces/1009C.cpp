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
    int n,m;
    cin >>n >>m;
    vector<int> x(m),d(m);
    rep(i,m) cin >>x[i] >>d[i];

    ll S = 0,M = 0;
    rep(i,n){
        S += i;
        M += abs(i-n/2);
    }

    ll ans = 0;
    ll X=0;
    rep(i,m){
        if(d[i]<0) ans += M*d[i];
        else ans += S*d[i];
        X += x[i];
    }
    printf("%.10f\n", (double)ans/n+X);
    return 0;
}
