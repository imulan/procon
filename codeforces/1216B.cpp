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

using pi = pair<int,int>;

int main(){
    int n;
    cin >>n;

    vector<pi> a(n);
    rep(i,n){
        cin >>a[i].fi;
        a[i].se = i;
    }
    sort(all(a), greater<pi>());

    int ans = 0;
    vector<int> o(n);
    rep(i,n){
        ans += (i*a[i].fi)+1;
        o[i] = a[i].se+1;
    }

    cout << ans << "\n";
    rep(i,n) cout << o[i] << " \n"[i==n-1];
    return 0;
}
