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
    ll m;
    cin >>n >>m;

    vector<ll> v(n);
    ll now = 0;
    rep(i,n){
        ll a,b;
        cin >>a >>b;
        v[i] = b-a;
        now += a;
    }
    sort(all(v));

    if(now<=m) return 0;
    rep(i,n){
        now += v[i];
        if(now<=m) return i+1;
    }
    return -1;
}

int main(){
    cout << solve() << endl;
    return 0;
}
