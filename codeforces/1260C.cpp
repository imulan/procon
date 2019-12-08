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

bool solve(){
    ll r,b,k;
    cin >>r >>b >>k;
    if(r>b) swap(r,b);

    ll g = __gcd(r,b);
    r /= g;
    b /= g;

    ll w = b-1;
    ll x = (w+r-1)/r;
    return x<k;
}

int main(){
    int t;
    cin >>t;
    while(t--) cout << (solve()?"OBEY":"REBEL") << "\n";
    return 0;
}
