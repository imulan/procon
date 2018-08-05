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
    scanf(" %d", &n);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    map<int,vector<int>> m;
    rep(i,n) m[a[i]].pb(i);

    vector<int> dp(n,1),par(n,-1);

    for(const auto &p:m){
        int val = p.fi;
        vector<int> cur = p.se;

        if(!m.count(val-1)) continue;
        vector<int> pre = m[val-1];

        int P = pre.size(), C = cur.size();
        int pidx = 0;
        int max_p = 0, max_idx = -1;
        rep(cidx,C){
            while(pidx<P && pre[pidx]<cur[cidx]){
                if(max_p < dp[pre[pidx]]){
                    max_p = dp[pre[pidx]];
                    max_idx = pre[pidx];
                }
                ++pidx;
            }

            if(max_p+1 > dp[cur[cidx]]){
                dp[cur[cidx]] = max_p+1;
                par[cur[cidx]] = max_idx;
            }
        }
    }

    // 復元
    int ans = 1;
    int idx = 0;
    rep(i,n){
        if(ans < dp[i]){
            idx = i;
            ans = dp[i];
        }
    }

    vector<int> x;
    while(idx!=-1){
        x.pb(idx+1);
        idx = par[idx];
    }
    reverse(all(x));

    printf("%d\n", ans);
    rep(i,ans) printf("%d%c", x[i], " \n"[i==ans-1]);
    return 0;
}
