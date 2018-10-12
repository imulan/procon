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

int main(){
    int n;
    cin >>n;

    vector<pi> v;
    rep(i,n){
        int m;
        cin >>m;
        rep(j,m){
            int c;
            cin >>c;
            v.pb({c,i});
        }
    }
    sort(all(v),greater<pi>());
    int V = v.size();

    set<int> t;
    rep(i,n) t.insert(i);

    ll ans = 0;
    rep(i,V){
        int idx = v[i].se;

        auto itr = t.upper_bound(idx);
        if(itr != t.begin()){
            --itr;
            ans += v[i].fi;
            t.erase(itr);
        }
    }
    cout << ans << endl;
    return 0;
}
