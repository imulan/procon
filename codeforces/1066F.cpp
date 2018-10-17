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

const ll INF = LLONG_MAX/3;

#define x first
#define y second
using pi = pair<int,int>;

int main(){
    int n;
    scanf(" %d", &n);

    vector<pi> p(n);
    rep(i,n) scanf(" %d %d", &p[i].x, &p[i].y);

    map<int,vector<pi>> pts;
    rep(i,n){
        int lv = max(p[i].x, p[i].y);
        p[i].y = -p[i].y;
        pts[lv].pb(p[i]);
        p[i].y = -p[i].y;
    }

    vector<vector<pi>> lv_pt;
    lv_pt.pb({{0,0}});
    for(const auto &tt:pts){
        int k = tt.fi;
        sort(all(pts[k]));

        rep(i,pts[k].size()) pts[k][i].y = -pts[k][i].y;
        lv_pt.pb(pts[k]);
    }

    auto dist = [&](pi pp, pi qq){
        return abs(pp.x-qq.x) + abs(pp.y-qq.y);
    };

    int L = lv_pt.size();
    vector<vector<ll>> dp(L, vector<ll>(2,INF));
    dp[0][0] = 0;
    rep(i,L-1)rep(j,2){
        ll lv_cost = dist(lv_pt[i+1].front(), lv_pt[i+1].back());

        pi ed = lv_pt[i].front();
        if(j) ed = lv_pt[i].back();

        rep(k,2){
            pi st = lv_pt[i+1].front();
            if(k) st = lv_pt[i+1].back();

            dp[i+1][!k] = min(dp[i+1][!k], dp[i][j]+dist(ed,st)+lv_cost);
        }
    }

    ll ans = INF;
    rep(i,2) ans = min(ans, dp[L-1][i]);
    cout << ans << endl;
    return 0;
}
