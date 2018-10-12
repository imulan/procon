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

pi NORM(pi p){
    if(p.fi<0){
        p.fi = -p.fi;
        p.se = -p.se;
    }
    int g = __gcd(abs(p.fi), abs(p.se));
    p.fi /= g;
    p.se /= g;
    return p;
}

int solve(){
    int n,k;
    cin >>n >>k;
    vector<int> x(n),y(n);
    rep(i,n) cin >>x[i] >>y[i];

    rep(i,n){
        map<pi,int> m;
        rep(j,n)if(i!=j){
            pi d(x[i]-x[j], y[i]-y[j]);
            ++m[NORM(d)];
        }

        for(const auto &p:m)if(p.se+1 >= k) return 1;
    }
    return 0;
}

int main(){
    cout << solve() << endl;
    return 0;
}
