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

const int N = 100010, P = 210;
const int INF = 19191919;

int dp[N][P];

int solve(){
    int n,L;
    scanf(" %d %d", &n, &L);

    vector<int> c(n,0);
    rep(i,L) scanf(" %d", &c[i]);
    sort(all(c));

    vector<int> val(n+1);
    vector<int> cost(101,INF);

    for(int i=0; i<=n; ++i){
        double p = 100.0*i/n;
        val[i] = round(p);
        cost[val[i]] = min(cost[val[i]], i);
    }

    fill(dp[0],dp[N],INF);
    dp[0][0] = 0;
    rep(i,n)rep(j,P)if(dp[i][j]<INF){

        for(int k=val[c[i]]; k<=100; ++k)if(cost[k]<INF){
            // printf(" %d %d %d\n",i,j,k);
            int need = max(0,cost[k]-c[i]);
            // dbg(need);
            if(dp[i][j]+c[i]+need<=n) dp[i+1][j+k] = min(dp[i+1][j+k], dp[i][j]+c[i]+need);
            else break;
        }
    }

    int ans = 0;
    rep(i,P)if(dp[n][i]<=n) ans = i;
    return ans;
}

int solve2(){
    int n,L;
    scanf(" %d %d", &n, &L);

    vector<int> c(n,0);
    rep(i,L) scanf(" %d", &c[i]);

    vector<int> up;
    for(int i=0; i<=n; ++i){
        double p = 100.0*i/n;
        if(p - (int)p >= 0.5) up.pb(i);
    }

    using pi = pair<int,int>;
    priority_queue<pi, vector<pi>, greater<pi>> pq;

    rep(i,n){
        auto itr = lower_bound(all(up), c[i]);

        if(itr != up.end()){
            if(*itr == c[i]) continue;
            pq.push({*itr-c[i], i});
        }
    }

    int rem = n;
    rep(i,n) rem -= c[i];

    while(!pq.empty()){
        pi now = pq.top();
        pq.pop();

        if(rem - now.fi < 0){
            c[now.se] += rem;
            rem = 0;
            break;
        }

        rem -= now.fi;
        c[now.se] += now.fi;
    }
    rep(i,n){
        if(c[i]==0){
            c[i] += rem;
            break;
        }
    }

    int ans = 0;
    rep(i,n) ans += round(100.0*c[i]/n);
    return ans;
}

int main(){
    int T;
    cin >>T;
    rep(i,T) printf("Case #%d: %d\n", i+1, solve2());
    return 0;
}
