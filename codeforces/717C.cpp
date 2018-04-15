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

const int mod = 10007;

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];
    sort(all(a));

    int ans = 0;
    rep(i,n) a[i] %= mod;
    rep(i,n) (ans += a[i]*a[n-i-1]) %= mod;
    cout << ans << endl;
    return 0;
}
