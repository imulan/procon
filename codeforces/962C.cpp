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

bool valid(const string &s){
    if(s[0]=='0') return false;

    ll v = stoll(s);
    ll ok=0, ng=50000;
    while(ng-ok>1){
        ll mid = (ok+ng)/2;
        if(mid*mid <= v) ok = mid;
        else ng = mid;
    }

    return ok*ok == v;
}

int main(){
    string s;
    cin >>s;
    int n = s.size();

    int ans = n;
    for(int i=1; i<(1<<n); ++i){
        string t = "";
        rep(j,n)if(i>>j&1) t += s[j];

        if(valid(t)) ans = min(ans, n-__builtin_popcount(i));
    }
    if(ans == n) ans = -1;
    cout << ans << "\n";
    return 0;
}
