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

using pi = pair<int,int>;
using P = pair<pi,int>;

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    map<int, vector<int>> pos;
    rep(i,n){
        int a;
        scanf(" %d", &a);
        pos[a].pb(i);
    }

    map<int, vector<P>> q;
    rep(i,m){
        int l,r,x;
        scanf(" %d %d %d", &l, &r, &x);
        --l;
        --r;
        q[x].pb({{l,r},i});
    }

    set<int> s;
    rep(i,n) s.insert(i);

    vector<int> ans(m,-1);
    for(const auto &x:q){
        int v = x.fi;
        for(int i:pos[v]) s.erase(i);

        for(const auto &p:x.se){
            pi range = p.fi;
            int l = range.fi, r = range.se;
            int idx = p.se;

            auto itr = s.lower_bound(l);
            if(itr != s.end() && *itr<=r) ans[idx] = (*itr)+1;
        }

        for(int i:pos[v]) s.insert(i);
    }

    rep(i,m) printf("%d\n", ans[i]);
    return 0;
}
