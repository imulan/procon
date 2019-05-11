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

vector<int> divisor(int n){
    vector<int> d;
    for(int i=1; i*i<=n; ++i)if(n%i==0){
        d.pb(i);
        if(n/i != i) d.pb(n/i);
    }
    return d;
}

int main(){
    int s;
    cin >>s;

    vector<ll> a(s+1);
    for(int i=1; i<=s; ++i){
        int now = 0;
        for(int j=i; j<=s; ++j){
            now += j;
            if(now > s) break;
            ++a[now];
        }
    }

    ll ans = 0;
    for(int x:divisor(s)) ans += a[x]*a[s/x];
    cout << ans << endl;
    return 0;
}
