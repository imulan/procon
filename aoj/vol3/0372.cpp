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

pi READ(){
    int s,t;
    int h,m;

    cin >>h >>m;
    s = h*60+m;
    cin >>h >>m;
    t = h*60+m;
    return {s,t};
}

const int N = 1450;

int main(){
    int n;
    cin >>n;

    vector<vector<pi>> v(n);
    rep(i,n){
        rep(j,3) v[i].pb(READ());
    }

    int ans = 0;
    rep(a,N)rep(h,N){

        auto IN = [&](pi p, int val){
            return p.fi<=val && val<=p.se;
        };

        auto OK = [&](int idx){
            return IN(v[idx][0], a) && IN(v[idx][1], h);
        };

        vector<int> ut;
        rep(i,n)if(OK(i)){
            ut.pb(v[i][2].fi);
            ut.pb(v[i][2].se);
        }
        sort(all(ut));
        ut.erase(unique(all(ut)), ut.end());

        int T = ut.size();
        vector<int> add(T), sub(T);
        rep(i,n)if(OK(i)){
            ++add[ lower_bound(all(ut),v[i][2].fi)-ut.begin() ];
            ++sub[ lower_bound(all(ut),v[i][2].se)-ut.begin() ];
        }

        int now = 0;
        rep(i,T){
            now += add[i];
            ans = max(ans, now);
            now -= sub[i];
        }
    }
    cout << ans << "\n";
    return 0;
}
