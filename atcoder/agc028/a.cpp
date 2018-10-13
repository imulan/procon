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

ll lcm(ll x, ll y){
    return x*y/__gcd(x,y);
}

int main(){
    ll n,m;
    string s,t;
    cin >>n >>m >>s >>t;

    ll L = lcm(n,m);

    map<int,char> ch;
    rep(i,n){
        ch[L/n * i] = s[i];
    }

    ll ans = L;
    rep(i,m){
        ll pos = L/m * i;
        if(ch.count(pos)){
            if(ch[pos] != t[i]) ans = -1;
        }
    }
    cout << ans << endl;
    return 0;
}
