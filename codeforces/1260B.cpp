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
    ll a,b;
    cin >>a >>b;
    if(a>b) swap(a,b);

    ll x = 2*b-a;
    if(x%3 != 0) return false;
    x /= 3;

    ll y = b-2*x;
    return y>=0;
}

int main(){
    int t;
    cin >>t;
    while(t--) cout << (solve()?"YES":"NO") << "\n";
    return 0;
}
