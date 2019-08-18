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

bool solve(string s){
    int n = s.size();
    if(s[0] != 'A') return false;

    int ct = 0;
    for(int i=2; i<n-1; ++i)if(s[i] == 'C') ++ct;
    if(ct != 1) return false;

    rep(i,n)if(s[i]!='A' && s[i]!='C'){
        if(isupper(s[i])) return false;
    }
    return true;
}

int main(){
    string s;
    cin >>s;
    cout << (solve(s)?"AC":"WA") << endl;
    return 0;
}
