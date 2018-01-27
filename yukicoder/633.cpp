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
    vector<int> a(n-1),b(n),c(n);
    rep(i,n-1) cin >>a[i];
    rep(i,n) cin >>b[i] >>c[i];

    int ans = 0;
    int now = 0;
    rep(i,n){
        if(i>0) ans += a[i-1]*now;
        now += c[i];
        now -= b[i];
    }

    cout << ans << endl;
    return 0;
}
