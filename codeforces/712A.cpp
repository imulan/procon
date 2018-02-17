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
    int n;
    cin >>n;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    vector<ll> b(n);
    b[n-1] = a[n-1];
    for(int i=n-2; i>=0; --i){
        b[i] = a[i]+a[i+1];
    }

    rep(i,n) cout << b[i] << " \n"[i==n-1];
    return 0;
}
