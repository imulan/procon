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

using pi = pair<int,int>;

bool is_sub(const string &a, const string &b){
    int A = a.size(), B = b.size();
    rep(i,A-B+1){
        if(a.substr(i,B) == b) return true;
    }
    return false;
}

int main(){
    int n;
    cin >>n;
    vector<string> s(n);
    rep(i,n) cin >>s[i];

    vector<pi> v(n);
    rep(i,n) v[i] = {s[i].size(),i};
    sort(all(v));

    bool ok = true;
    rep(i,n)rep(j,i){
        ok &= is_sub(s[v[i].se], s[v[j].se]);
    }

    if(ok){
        cout << "YES" << endl;
        rep(i,n) cout << s[v[i].se] << endl;
    }
    else cout << "NO" << endl;
    return 0;
}
