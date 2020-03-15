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

const int INF = 19191919;

int main(){
    int n,m,k;
    scanf(" %d %d %d", &n, &m, &k);

    map<int,vector<int>> IN,OUT;
    vector<int> ux;
    rep(i,n){
        int l,r;
        scanf(" %d %d", &l, &r);
        ++r;

        IN[l].pb(i);
        OUT[r].pb(i);
        ux.pb(l);
        ux.pb(r);
    }

    sort(all(ux));
    ux.erase(unique(all(ux)), ux.end());
    const int X = ux.size();

    vector<bool> odd(1<<k);
    rep(i,1<<k) odd[i] = (__builtin_popcount(i)%2 == 1);

    vector<int> dp(1<<k,-INF);
    dp[0] = 0;

    set<int> pre;
    rep(i,X-1){
        set<int> now(pre);
        for(int j:IN[ux[i]]) now.insert(j);
        for(int j:OUT[ux[i]]) now.erase(j);

        vector<int> p(all(pre)), q(all(now));
        const int P = p.size(), Q = q.size();
        int cp_mask = 0;
        map<int,int> q2p;
        rep(ii,P)rep(jj,Q)if(p[ii]==q[jj]){
            q2p[jj] = ii;
            cp_mask |= 1<<ii;
        }

        vector<int> mxcp(1<<k,-INF);
        rep(mask,1<<P){
            int t = mask&cp_mask;
            mxcp[t] = max(mxcp[t], dp[mask]);
        }

        rep(mask,1<<Q){
            int cp = 0;
            rep(j,Q)if(mask>>j&1){
                if(q2p.count(j)) cp |= 1<<q2p[j];
            }

            int add = 0;
            if(odd[mask]) add = ux[i+1]-ux[i];

            dp[mask] = mxcp[cp] + add;
        }

        pre = now;
    }

    int ans = -INF;
    for(int i:dp) ans = max(ans, i);
    printf("%d\n", ans);
    return 0;
}
