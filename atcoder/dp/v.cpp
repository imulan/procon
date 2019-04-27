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

const int N = 100010;
int n;
ll mod;
vector<int> G[N];

ll dp[N];
void dfs(int x, int p){
    dp[x] = 1;
    for(int e:G[x])if(e!=p){
        dfs(e,x);
        (dp[x]*=dp[e]) %= mod;
    }
    (dp[x] += 1) %= mod;
}

ll ans[N];
void dfs2(int x, int p, ll par_dp){
    ans[x] = par_dp;

    vector<int> c;
    for(int e:G[x])if(e!=p){
        (ans[x] *= dp[e]) %= mod;
        c.pb(e);
    }
    sort(all(c));
    int C = c.size();

    vector<ll> dpv(C+2,1);
    rep(i,C) dpv[i+1] = dp[c[i]];

    vector<ll> pre(dpv), suf(dpv);
    rep(i,C+1) (pre[i+1] *= pre[i]) %= mod;
    for(int i=C+1; i>0; --i) (suf[i-1] *= suf[i]) %= mod;

    rep(i,C){
        ll t_par = par_dp;
        (t_par *= pre[i]) %= mod;
        (t_par *= suf[i+2]) %= mod;
        (t_par += 1) %= mod;
        dfs2(c[i], x, t_par);
    }
}

int main(){
    cin >>n >>mod;
    rep(i,n-1){
        int x,y;
        cin >>x >>y;
        --x;
        --y;
        G[x].pb(y);
        G[y].pb(x);
    }

    dfs(0,-1);
    dfs2(0,-1,1);

    rep(i,n) cout << ans[i] << "\n";
    return 0;
}
