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

    vector<int> a(n+2);
    rep(i,n) cin >>a[i+1];
    n += 2;

    int f = 0;
    rep(i,n-1) f += abs(a[i]-a[i+1]);

    for(int i=1; i<=n-2; ++i){
        int ans = f;
        ans -= abs(a[i]-a[i-1]);
        ans -= abs(a[i]-a[i+1]);
        ans += abs(a[i-1]-a[i+1]);
        cout << ans << endl;
    }

    return 0;
}
