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

ll solve(){
    ll n,a,b;
    cin >>n >>a >>b;

    ll ans = 0;
    if(n%2 == 1){
        --n;
        ans += a;
    }
    ans += (n/2)*min(a*2, b);
    return ans;
}

int main(){
    int q;
    cin >>q;
    while(q--) cout << solve() << "\n";
    return 0;
}
