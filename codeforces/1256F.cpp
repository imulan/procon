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

const int A = 26;

bool solve(){
    int n;
    string s,t;
    cin >>n >>s >>t;

    vector<int> cs(A), ct(A);
    rep(i,n){
        ++cs[s[i]-'a'];
        ++ct[t[i]-'a'];
    }

    if(cs != ct) return false;

    rep(i,A)if(cs[i]>1) return true;

    int inv_s=0, inv_t=0;
    rep(i,n)rep(j,i){
        if(s[j]>s[i]) ++inv_s;
        if(t[j]>t[i]) ++inv_t;
    }
    return inv_s%2 == inv_t%2;
}

int main(){
    int q;
    cin >>q;
    rep(i,q) cout << (solve()?"YES":"NO") << "\n";
    return 0;
}
