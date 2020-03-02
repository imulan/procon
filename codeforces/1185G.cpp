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

using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;

const int N = 51;
const int M = 2505;
const ll mod = 1e9+7;

int main(){
    int n,T;
    scanf(" %d %d", &n, &T);

    vector<vi> x(3);
    rep(i,n){
        int t,g;
        scanf(" %d %d", &t, &g);
        --g;
        x[g].pb(t);
    }
    sort(all(x), [](const vi &lh, const vi &rh){
        return lh.size() < rh.size();
    });

    vector<int> sz(3);
    rep(i,3) sz[i] = x[i].size();

    // dp[i][j] = i曲選んで合計j分
    auto one_genre = [&](int g){
        vector<vi> dp(sz[g]+1, vi(M));
        dp[0][0] = 1;
        rep(song,sz[g]){
            int t = x[g][song];
            for(int i=sz[g]-1; i>=0; --i)for(int j=M-1; j>=0; --j)if(dp[i][j]){
                (dp[i+1][j+t] += dp[i][j]) %= mod;
            }
        }
        return dp;
    };

    vector<vvi> genre(3);
    rep(i,3) genre[i] = one_genre(i);

    vector<vvi> dp01(sz[0]+1, vvi(sz[1]+1, vi(M)));
    rep(i,sz[0]+1)rep(ti,50*i+1)rep(j,sz[1]+1)rep(tj,50*j+1){
        ll add = genre[0][i][ti]*genre[1][j][tj];
        (dp01[i][j][ti+tj] += add) %= mod;
    }

    vector<vvvi> pat(sz[0]+1, vvvi(sz[1]+1, vvi(sz[2]+1, vi(3))));
    if(sz[0]) pat[1][0][0][0] = 1;
    if(sz[1]) pat[0][1][0][1] = 1;
    if(sz[2]) pat[0][0][1][2] = 1;
    rep(i,sz[0]+1)rep(j,sz[1]+1)rep(k,sz[2]+1)rep(l,3){
        if(!pat[i][j][k][l]) continue;
        ll val = pat[i][j][k][l];

        if(i<sz[0] && l!=0) (pat[i+1][j][k][0] += val) %= mod;
        if(j<sz[1] && l!=1) (pat[i][j+1][k][1] += val) %= mod;
        if(k<sz[2] && l!=2) (pat[i][j][k+1][2] += val) %= mod;
    }

    vector<ll> f(N);
    f[0] = 1;
    rep(i,N-1) f[i+1] = (f[i]*(i+1))%mod;

    ll ans = 0;
    rep(i,sz[0]+1)rep(j,sz[1]+1)rep(t,T+1)if(dp01[i][j][t]){
        // printf(" --- %d %d %d \n", i,j,t);
        int kt = T-t;
        rep(k,sz[2]+1){
            ll add = dp01[i][j][t];
            (add *= genre[2][k][kt]) %= mod;

            ll pt = 0;
            rep(l,3) (pt += pat[i][j][k][l]) %= mod;
            (pt *= f[i]) %= mod;
            (pt *= f[j]) %= mod;
            (pt *= f[k]) %= mod;
            (add *= pt) %= mod;

            // printf("k %d :: pt %lld, add %lld\n", k,pt,add);
            (ans += add) %= mod;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
