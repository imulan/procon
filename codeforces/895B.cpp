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
    int n,x,k;
    cin >>n >>x >>k;

    map<int,ll> ct;
    rep(i,n){
        int a;
        cin >>a;
        ++ct[a];
    }

    ll ans = 0;
    map<int,ll> d;
    for(const auto &p:ct){
        d[(p.fi-1)/x] += p.se;
        ans += p.se*d[p.fi/x - k];
    }
    cout << ans << endl;
    return 0;
}
