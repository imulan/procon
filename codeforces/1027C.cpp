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

// minimize: (2a+2b)^2 / ab
// = (4a^2 + 8ab + 4b^2) / ab
// = 4a/b + 8 + 4b/a
// = 4(a/b + b/a) + 8

using pi = pair<int,int>;
using pl = pair<ll,ll>;

inline bool is_small(pi p, pi q){
    auto sq = [](ll x){
        return x*x;
    };

    pl P(sq(p.fi+p.se), p.fi*p.se);
    pl Q(sq(q.fi+q.se), q.fi*q.se);

    // P.fi/P.se > Q.fi/Q.se
    ll lh = P.fi*Q.se;
    ll rh = Q.fi*P.se;
    return lh > rh;
}

void solve(){
    int n;
    scanf(" %d", &n);

    map<int,int> m;
    rep(i,n){
        int a;
        scanf(" %d", &a);
        ++m[a];
    }

    vector<int> v;
    for(const auto &p:m){
        rep(i,p.se/2) v.pb(p.fi);
    }
    sort(all(v));
    int V = v.size();
    assert(V>=2);

    pi x ={v[0],v[1]};
    rep(i,V-1){
        pi cand = {v[i], v[i+1]};
        if(is_small(x, cand)) x = cand;
    }

    vector<int> ans;
    rep(i,2){
        ans.pb(x.fi);
        ans.pb(x.se);
    }
    rep(i,4) printf("%d%c", ans[i], " \n"[i==3]);
}

int main(){
    int T;
    scanf(" %d", &T);
    while(T--) solve();
    return 0;
}
