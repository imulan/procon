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

void solve(){
    int m;
    cin >>m;
    vector<int> s(m);
    rep(i,m) cin >>s[i];

    int g = s[0];
    rep(i,m) g = __gcd(g,s[i]);
    if(g!=s[0]){
        cout << -1 << endl;
    }
    else{
        cout << 2*m << endl;
        rep(i,m) cout << s[i] << " " << s[0] << " \n"[i==m-1];
    }
}

int main(){
    solve();
    return 0;
}
