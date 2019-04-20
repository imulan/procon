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
const ll INF = 1000000000000000000LL;

void solve(){
    int r,s,m,d,n;
    scanf(" %d %d %d %d %d", &r, &s, &m, &d, &n);

    vector<int> b(r);
    rep(i,r) scanf(" %d", &b[i]);

    vector<vector<int>> x(s+m+d);
    rep(i,s+m+d){
        int sz;
        scanf(" %d", &sz);

        x[i] = vector<int>(sz);
        rep(j,sz){
            scanf(" %d", &x[i][j]);
            --x[i][j];
        }
    }

    vector<vector<bool>> ban(s+m+d, vector<bool>(s+m+d));
    rep(i,n){
        int u,v;
        scanf(" %d %d", &u, &v);
        --u; --v;
        ban[u][v] = ban[v][u] = true;
    }

    ll ans = 0;
    rep(i,s)rep(j,m)rep(k,d){
        if(ban[i][s+j] || ban[s+j][s+m+k] || ban[s+m+k][i]) continue;
        // printf(" %d %d %d\n", i,j,k);

        set<int> use;
        for(int xx:x[i]) use.insert(xx);
        for(int xx:x[s+j]) use.insert(xx);
        for(int xx:x[s+m+k]) use.insert(xx);

        ll add = 1;
        for(int xx:use){
            if(add>INF/b[xx]){
                printf("too many\n");
                return;
            }

            add *= b[xx];
        }

        ans += add;
        if(ans>INF){
            printf("too many\n");
            return;
        }
    }

    printf("%lld\n", ans);
}

int main(){
    solve();
    return 0;
}
