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

const double INF = 1e8;

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<vector<int>> G(n);
    rep(i,m){
        int s,t;
        scanf(" %d %d", &s, &t);
        --s;
        --t;
        G[s].pb(t);
    }

    double ans = INF;
    rep(tgt,n){
        vector<double> dp(n,INF);
        dp[n-1] = 0;
        for(int i=n-2; i>=0; --i){
            int sz = G[i].size();
            if(i==tgt){
                if(sz<=1) continue;

                double p = 1.0/(sz-1);
                double mx = 0;

                dp[i] = 1;
                for(int j:G[i]){
                    dp[i] += p*dp[j];
                    mx = max(mx, dp[j]);
                }
                dp[i] -= p*mx;
            }
            else{
                double p = 1.0/sz;
                dp[i] = 1;
                for(int j:G[i]) dp[i] += p*dp[j];
            }
        }

        ans = min(ans, dp[0]);
    }

    printf("%.15f\n", ans);
    return 0;
}
