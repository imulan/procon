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

ll solve(){
    ll n,m,k;
    cin >>n >>m >>k;

    n %= 10;

    if(m == 0) return n*k;

    vector<int> v;
    bool u[10]={};
    ll t = n;
    while(!u[t]){
        u[t] = true;
        v.pb(t);
        t = (t*n)%10;
    }

    // dbg(v);
    int V = v.size();
    ll mul = v[(m-1)%V];

    v.clear();
    rep(i,10) u[i] = false;
    t = n;
    while(!u[t]){
        u[t] = true;
        v.pb(t);
        t = (t*mul)%10;
    }

    // dbg(v);
    V = v.size();

    ll sv = 0;
    for(ll i:v) sv += i;

    ll ans = sv*(k/V);
    rep(i,k%V) ans += v[i];
    return ans;
}

int main(){
    cout << solve() << endl;
    return 0;
}
