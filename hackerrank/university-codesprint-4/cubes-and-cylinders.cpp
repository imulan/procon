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

inline bool ok(int S, int R){
    return S*S < 2*R*R;
}

int solve(){
    int n,m;
    cin >>n >>m;
    vector<int> s(n),k(n),r(m),c(m);
    rep(i,n) cin >>s[i];
    rep(i,n) cin >>k[i];
    rep(i,m) cin >>r[i];
    rep(i,m) cin >>c[i];

    vector<int> package, cylinder;
    rep(i,n){
        rep(j,k[i]) package.pb(s[i]);
    }
    rep(i,m){
        rep(j,c[i]) cylinder.pb(r[i]);
    }
    sort(all(package));
    sort(all(cylinder));

    int P = package.size(), C = cylinder.size();
    int pp=0, cc=0;
    int ans = 0;
    while(pp<P && cc<C){
        if(ok(package[pp], cylinder[cc])){
            ++pp;
            ++cc;
            ++ans;
        }
        else ++cc;
    }
    return ans;
}

int main(){
    cout << solve() << endl;
    return 0;
}
