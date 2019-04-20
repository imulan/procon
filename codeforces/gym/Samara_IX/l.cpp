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

bool f(const vector<int> &m, const vector<int> &e){
    int n = m.size();

    int sz = n/2+1;

    vector<int> mm,ee;
    rep(i,sz){
        mm.pb(m[n-1-i]);
        ee.pb(e[i]);
    }

    sort(all(mm));
    sort(all(ee));
    rep(i,sz){
        if(mm[i] < ee[i]) return false;
    }
    return true;
}

int main(){
    int n;
    scanf(" %d", &n);

    vector<int> a(n),b(n);
    rep(i,n) scanf(" %d", &a[i]);
    rep(i,n) scanf(" %d", &b[i]);
    sort(all(a));
    sort(all(b));

    int A = f(a,b), B = f(b,a);

    string ans = "None";
    if(A && B) ans = "Both";
    else if(A) ans = "First";
    else if(B) ans = "Second";
    cout << ans << '\n';
    return 0;
}
