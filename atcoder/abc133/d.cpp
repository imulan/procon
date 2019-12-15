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
    int n;
    cin >>n;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    ll s[2]={};
    rep(i,n) s[i%2] += a[i];

    vector<ll> x(n);
    x[0] = (s[0]-s[1])/2;
    for(int i=1; i<n; ++i) x[i] = a[i-1]-x[i-1];

    rep(i,n) cout << 2*x[i] << " \n"[i==n-1];
    return 0;
}
