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
    scanf(" %d %d", &n, &m);
    vector<ll> a(n),b(m);
    rep(i,n) scanf(" %lld", &a[i]);
    rep(i,m) scanf(" %lld", &b[i]);

    ll A = 0;
    int idx = 0;
    rep(i,m){
        while( idx<n && A+a[idx] < b[i] ){
            A += a[idx];
            ++idx;
        }
        printf("%d %lld\n", idx+1, b[i]-A);
    }
    return 0;
}
