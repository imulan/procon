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

int main(){
    int n;
    scanf(" %d", &n);

    vector<vector<int>> c(3, vector<int>(n));
    rep(i,3)rep(j,n) scanf(" %d", &c[i][j]);

    vector<vector<int>> G(n);
    rep(i,n-1){
        int u,v;
        scanf(" %d %d", &u, &v);
        --u;
        --v;
        G[u].pb(v);
        G[v].pb(u);
    }

    int s = 0;
    rep(i,n){
        int sz = G[i].size();
        if(sz>=3){
            printf("-1\n");
            return 0;
        }

        if(sz==1) s = i;
    }

    vector<int> v;
    int par = -1;
    rep(i,n){
        v.pb(s);
        for(int j:G[s]){
            if(j!=par){
                par = s;
                s = j;
                break;
            }
        }
    }

    vector<int> p(3);
    rep(i,3) p[i] = i;

    ll ans = LLONG_MAX;
    vector<int> a;
    do{
        ll t = 0;
        rep(i,n) t += c[p[i%3]][v[i]];

        if(t < ans){
            ans = t;
            a = p;
        }
    }while(next_permutation(all(p)));

    vector<int> x(n);
    rep(i,n) x[v[i]] = a[i%3]+1;

    printf("%lld\n", ans);
    rep(i,n) printf("%d%c", x[i], " \n"[i==n-1]);
    return 0;
}
