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

const int INF = 10101010;

void solve(){
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<vector<int>> G(n);
    rep(i,m){
        int u,v;
        scanf(" %d %d", &u, &v);
        --u;
        --v;
        G[u].pb(v);
        G[v].pb(u);
    }

    vector<int> d(n,INF);
    d[0] = 0;
    queue<int> que({0});
    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(int e:G[v])if(d[e] > d[v]+1){
            que.push(e);
            d[e] = d[v]+1;
        }
    }

    int ct[2]={};
    rep(i,n) ++ct[d[i]%2];

    int f = 0;
    if(ct[1]<ct[0]) f = 1;

    vector<int> c;
    rep(i,n)if(d[i]%2 == f) c.pb(i);

    int k = c.size();
    printf("%d\n",k);
    rep(i,k) printf("%d%c", c[i]+1, " \n"[i==k-1]);
}

int main(){
    int T;
    scanf(" %d", &T);
    rep(i,T) solve();
    return 0;
}
