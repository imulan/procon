#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;
using D = pair<ll,pi>;

const ll INF = LLONG_MAX/3;

const int N = 1010;
vector<int> G[N];

ll dp[N][N];

int main(){
    int x,n,m,t;
    cin >>x >>n >>m >>t;

    rep(i,m){
        int a,b;
        cin >>a >>b;
        --a;
        --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    vector<int> T(n),P(n);
    rep(i,n) cin >>T[i] >>P[i];

    rep(i,N)rep(j,N) dp[i][j] = INF;

    priority_queue<D,vector<D>,greater<D>> pq;
    if(T[0]<=x){
        dp[0][T[0]] = P[0];
        pq.push({P[0],{0,T[0]}});
    }
    while(!pq.empty()){
        D now = pq.top();
        pq.pop();
        int v = now.se.fi, tm = now.se.se;
        if(now.fi > dp[v][tm]) continue;

//        stay
        if(tm+T[v]<=x){
            int nt = tm+T[v];
            if(dp[v][nt] > dp[v][tm]+P[v]){
                dp[v][nt] = dp[v][tm]+P[v];
                pq.push({dp[v][nt],{v,nt}});
            }
        }

//        move
        for(int nv:G[v]){
            int nt = tm+t+T[nv];
            if(nt<=x && dp[nv][nt] > dp[v][tm]+P[nv]){
                dp[nv][nt] = dp[v][tm]+P[nv];
                pq.push({dp[nv][nt],{nv,nt}});
            }
        }
    }

    ll ans = dp[0][x];
    if(ans == INF) cout << "It is a trap." << endl;
    else cout << ans << endl;
    return 0;
}