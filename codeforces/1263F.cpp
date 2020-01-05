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

using vi = vector<int>;
const int INF = 101010;

vector<vi> calc_cost(int L){
    int V;
    scanf(" %d", &V);

    vector<int> p(V,-1);
    for(int i=1; i<V; ++i){
        scanf(" %d", &p[i]);
        --p[i];
    }

    vector<int> l(L);
    rep(i,L){
        scanf(" %d", &l[i]);
        --l[i];
    }

    vi num_leaf(V);
    rep(i,L){
        int v = l[i];
        while(v!=-1){
            ++num_leaf[v];
            v = p[v];
        }
    }
    ++num_leaf[0];

    vector<vi> w(L, vi(L,INF));
    rep(i,L){
        vi ct(num_leaf);
        for(int j=i; j<L; ++j){
            if(j==i) w[i][j] = 0;
            else w[i][j] = w[i][j-1];

            for(int v=l[j]; v!=-1; v=p[v]){
                --ct[v];
                w[i][j] += !ct[v];
            }
        }
        // printf(" %d:",i); dbg(w[i]);
    }
    return w;
}

int main(){
    int n;
    scanf(" %d", &n);

    vector<vi> cost(n, vi(n));
    rep(loop,2){
        vector<vi> t = calc_cost(n);
        rep(i,n)rep(j,n) cost[i][j] = max(cost[i][j], t[i][j]);
    }

    vector<int> dp(n+1, -INF);
    dp[0] = 0;
    rep(i,n){
        rep(j,i+1) dp[i+1] = max(dp[i+1], dp[j]+cost[j][i]);
    }
    printf("%d\n", dp[n]);
    return 0;
}
