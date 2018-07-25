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

bool valid(ll n, ll k){
    ll ct = 0;
    ll rem = n;
    bool myturn = true;
    while(rem>0){
        if(myturn){
            ll a = min(k,rem);
            ct += a;
            rem -= a;
        }
        else{
            ll a = rem/10;
            rem -= a;
        }
        myturn = !myturn;
    }
    return ct >= (n+1)/2;
}

int main(){
    ll n;
    cin >>n;
    ll ng=0, ok=n;
    while(ok-ng>1){
        ll m = (ng+ok)/2;
        if(valid(n,m)) ok = m;
        else ng = m;
    }
    cout << ok << endl;
    return 0;
}
