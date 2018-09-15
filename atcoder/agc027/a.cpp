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

int solve(){
    int n;
    ll x;
    cin >>n >>x;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];
    sort(all(a));

    ll sum = 0;
    rep(i,n){
        if(sum+a[i] > x) return i;
        sum += a[i];
    }

    if(sum == x) return n;
    return n-1;
}

int main(){
    cout << solve() << endl;
    return 0;
}
