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

void solve(){
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<vector<ll>> d(n, vector<ll>(n,INF));
    vector<int> x(m),y(m);
    vector<ll> z(m);
    rep(i,m){
        scanf(" %d %d %lld", &x[i], &y[i], &z[i]);
        --x[i];
        --y[i];
        d[x[i]][y[i]] = min(d[x[i]][y[i]], z[i]);
        d[y[i]][x[i]] = min(d[y[i]][x[i]], z[i]);
    }

    rep(k,n)rep(i,n)rep(j,n) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);

    // rep(i,n){
    //     rep(j,n)printf("%lld ", d[i][j]);
    //     printf("\n");
    // }

    rep(i,m){
        if(d[x[i]][y[i]] != z[i]){
            printf("Impossible\n");
            return;
        }
    }

    int ct = 0;
    rep(i,n)rep(j,i)if(d[i][j] <= 1000000) ++ct;

    printf("%d\n", ct);
    rep(i,n)rep(j,i)if(d[i][j] <= 1000000) printf("%d %d %lld\n", j+1, i+1, d[i][j]);
}

int main(){
    int T;
    scanf(" %d", &T);
    rep(i,T){
        printf("Case #%d: ", i+1);
        solve();
    }
    return 0;
}
