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

const ll mod = 1e9+7;

ll mod_pow(ll x, ll n){
    ll ret = 1;
    while(n){
        if(n&1) (ret*=x) %= mod;
        (x*=x) %= mod;
        n >>= 1;
    }
    return ret;
}

const int N = 55;

int n,p;
int c[N];

ll C[N][N];
ll ev[N], od[N];

ll dp[N][N][N][N];
ll dfs(int d, int ew, int ow, int eb){
    int ob = d-(ew+ow+eb);
    if(d==n) return (ow+ob)%2 == p;
    if(dp[d][ew][ow][eb]>=0) return dp[d][ew][ow][eb];

    ll ret = 0;

    // 黒塗り
    if(c[d]!=1){
        ll mul = mod_pow(2,eb+ob+ew);

        ll add = 0;
        (add += dfs(d+1,ew,ow,eb+1)*od[ow]) %= mod;
        (add += dfs(d+1,ew,ow,eb)*ev[ow]) %= mod;

        (ret += mul*add) %= mod;
    }

    // 白塗り
    if(c[d]!=0){
        ll mul = mod_pow(2,ew+ow+eb);

        ll add = 0;
        (add += dfs(d+1,ew+1,ow,eb)*od[ob]) %= mod;
        (add += dfs(d+1,ew,ow+1,eb)*ev[ob]) %= mod;

        (ret += mul*add) %= mod;
    }

    // printf(" %d %d %d %d ->  %lld\n", d,ew,ow,eb,ret);
    return dp[d][ew][ow][eb] = ret;
}

int main(){
    C[0][0]=1;
    for(int i=1; i<N; ++i){
        C[i][0]=1;
        for(int j=1; j<i; ++j) C[i][j] = (C[i-1][j-1]+C[i-1][j])%mod;
        C[i][i]=1;
    }

    rep(i,N){
        rep(j,i+1){
            if(j%2==0) (ev[i] += C[i][j]) %= mod;
            else (od[i] += C[i][j]) %= mod;
        }
    }

    cin >>n >>p;
    rep(i,n) cin >>c[i];

    memset(dp,-1,sizeof(dp));
    cout << dfs(0,0,0,0) << endl;
    return 0;
}
