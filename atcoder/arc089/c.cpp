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

bool solve(){
    int n;
    cin >>n;

    vector<int> t(n);
    vector<pi> p(n);
    rep(i,n) cin >>t[i] >>p[i].fi >>p[i].se;

    auto dist = [&](pi a, pi b){
        return abs(a.fi-b.fi) + abs(a.se-b.se);
    };

    int T = 0;
    pi now = {0,0};
    rep(i,n){
        int pt = (p[i].fi+p[i].se)%2;
        if(pt%2 != t[i]%2) return false;

        int d = dist(now,p[i]);
        if(d > t[i]-T) return false;
        T = t[i];
        now = p[i];
    }
    return true;
}

int main(){
    cout << (solve()?"Yes":"No") << endl;
    return 0;
}
