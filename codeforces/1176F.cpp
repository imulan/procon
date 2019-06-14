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

const ll INF = LLONG_MAX/3;
const int N = 10;

int main(){
    int n;
    scanf(" %d", &n);

    vector<ll> dp(N,-INF);
    dp[0]=0;

    rep(turn,n){
        int k;
        scanf(" %d", &k);

        vector<ll> cost[4];
        rep(i,k){
            int c,d;
            scanf(" %d %d", &c, &d);
            cost[c].pb(d);
        }
        rep(i,4) sort(all(cost[i]), greater<ll>());

        vector<ll> nx(dp);
        rep(i,N){
            ll d;
            // 1 card
            // [1],[2],[3]
            d = -INF;
            for(int cc=1; cc<=3; ++cc){
                if(cost[cc].size()>=1) d = max(d,cost[cc][0]);
            }
            if(d>=0){
                int ni = (i+1)%N;
                if(i+1>=N) d*=2;
                nx[ni] = max(nx[ni], dp[i]+d);
            }

            // 2 cards
            // [1,1],[1,2]
            d = -INF;
            if(cost[1].size()>=2){
                ll t = cost[1][0]+cost[1][1];
                if(i+2>=N) t += cost[1][0];
                d = max(d,t);
            }
            if(cost[1].size()>=1 && cost[2].size()>=1){
                ll t = cost[1][0]+cost[2][0];
                if(i+2>=N) t += max(cost[1][0],cost[2][0]);
                d = max(d,t);
            }
            if(d>=0){
                int ni = (i+2)%N;
                nx[ni] = max(nx[ni], dp[i]+d);
            }

            // 3 cards
            // [1,1,1]
            d = -INF;
            if(cost[1].size()>=3){
                ll t = 0;
                rep(j,3) t += cost[1][j];
                if(i+3>=N) t += cost[1][0];
                d = max(d,t);
            }
            if(d>=0){
                int ni = (i+3)%N;
                nx[ni] = max(nx[ni], dp[i]+d);
            }
        }
        dp = nx;
    }

    printf("%lld\n", *max_element(all(dp)));
    return 0;
}
