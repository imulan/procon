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
    string s;
    cin >>s;

    int n = s.size();
    int ct = 0;
    rep(i,n-3){
        string t = "";
        rep(j,4) t += s[i+j];
        sort(all(t));
        if(t == "cefh") ++ct;
    }

    if(ct == 0) cout << "normal" << endl;
    else cout << "lovely " << ct << endl;
}

int main(){
    int T;
    cin >>T;
    while(T--) solve();
    return 0;
}
