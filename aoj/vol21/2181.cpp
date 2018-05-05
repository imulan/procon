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
using P = pair<pi,int>;

inline int sq(int x){
    return x*x;
}

inline int dist2(pi a, pi b){
    return sq(a.fi-b.fi) + sq(a.se-b.se);
}

inline bool in_circle(pi c, int r, pi p){
    return dist2(p,c) < r*r;
}

inline bool intersect(pi p, int rp, pi q, int rq){
    return dist2(p,q) <= sq(rp+rq);
}

// circle p includes circle q?
inline bool include(pi p, int rp, pi q, int rq){
    if(!in_circle(p,rp,q)) return false;
    return sqrt(dist2(p,q)) + rq < rp;
}

vector<vector<int>> G;
vector<int> l;
vector<bool> vis;

void dfs(int x){
    if(vis[x]) return;

    vis[x] = true;
    for(int e:G[x]) dfs(e);
    l.pb(x);
}

vector<int> calc(const vector<pi> &p, const vector<int> r){
    int n = p.size();

    G = vector<vector<int>>(n);
    rep(i,n)rep(j,n)if(i!=j){
        if(include(p[i],r[i],p[j],r[j])){
            G[j].pb(i);
        }
    }

    l.clear();
    vis = vector<bool>(n);

    rep(i,n) dfs(i);
    reverse(all(l));

    vector<int> dp(n,1);
    for(int i:l){
        for(int j:G[i]){
            dp[j] = max(dp[j],dp[i]+1);
        }
    }

    return dp;
}

int main(){
    int n;
    while(cin >>n,n){
        pi s,t;
        cin >>s.fi >>s.se;
        cin >>t.fi >>t.se;

        vector<pi> ps,pt;
        vector<int> rs,rt;

        rep(i,n){
            pi p;
            int r;

            cin >>p.fi >>p.se >>r;

            if(in_circle(p,r,s) && in_circle(p,r,t)) continue;

            if(in_circle(p,r,s)){
                ps.pb(p);
                rs.pb(r);
            }
            if(in_circle(p,r,t)){
                pt.pb(p);
                rt.pb(r);
            }
        }

        vector<int> dps = calc(ps,rs), dpt = calc(pt,rt);
        int S = dps.size(), T = dpt.size();

        int ans = 0;
        rep(i,S) ans = max(ans, dps[i]);
        rep(i,T) ans = max(ans, dpt[i]);

        rep(i,S)rep(j,T){
            if(!intersect(ps[i],rs[i],pt[j],rt[j])){
                ans = max(ans, dps[i]+dpt[j]);
            }
        }

        cout << ans << endl;
    }
    return 0;
}
