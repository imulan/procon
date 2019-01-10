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

using pi = pair<ll,ll>;

pi READ(string s, ll mul){
    bool x = false;
    for(char c:s)if(c=='x') x = true;

    if(!x) return {mul*stoi(s), 0};

    int S = s.size();
    int xidx = 0;
    while(s[xidx]!='x') ++xidx;

    ll a = 1, n = 1;
    if(xidx != 0) a = stoi(s.substr(0,xidx));
    if(xidx != S-1) n = stoi(s.substr(xidx+2));
    return {mul*a, n};
}

ll f(const vector<pi> &v, ll x){
    ll ret = 0;
    for(pi p:v){
        ll add = p.fi;
        rep(_,p.se) add *= x;
        ret += add;
    }
    return ret;
}

string cv(int x){
    if(x==0) return "x";

    string ret = "(x";

    x = -x;
    if(x>0) ret += "+";

    ret += to_string(x) + ")";
    return ret;
}

int main(){
    string s;
    cin >>s;
    int S = s.size();

    int idx = 0;
    int m = 1;
    vector<pi> v;
    while(idx<S){
        int nx = idx;
        while(nx<S && (s[nx]!='+' && s[nx]!='-')) ++nx;

        v.pb(READ(s.substr(idx, nx-idx), m));

        if(nx<S){
            if(s[nx] == '+') m = 1;
            else m = -1;
            ++nx;
        }
        idx = nx;
    }

    // dbg(v);
    int n = v[0].se;

    string ans = "";

    const int N = 2000;
    for(int i=N; i>=-N; --i){
        if(f(v,i) == 0) ans += cv(i);
    }
    cout << ans << "\n";
    return 0;
}
