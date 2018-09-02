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

bool solve(){
    int n;
    string s;
    cin >>n >>s;
    rep(i,n){
        int d = abs(s[i]-s[n-1-i]);
        if(d==0 || d==2) continue;
        return false;
    }
    return true;
}

int main(){
    int T;
    cin >>T;
    while(T--) cout << (solve()?"YES":"NO") << endl;
    return 0;
}
