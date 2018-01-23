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

void solve(){
    ll n,a,b;
    cin >>n >>a >>b;

    rep(i,n+1){
        ll rem = n - i*a;
        if(rem<0) break;

        if(rem%b == 0){
            ll j = rem/b;
            cout << "YES" << endl;
            cout << i << " " << j << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main(){
    solve();
    return 0;
}
