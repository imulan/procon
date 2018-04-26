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

bool solve(ll n, ll k){
    if(n==1){
        if(k<=2) return true;
        return false;
    }

    if(n<=k) return false;

    for(ll i=1; i<=k; ++i){
        if(n%i != i-1) return false;
    }
    return true;
}

int main(){
    ll n,k;
    cin >>n >>k;
    cout << (solve(n,k)?"Yes":"No") << endl;
    return 0;
}
