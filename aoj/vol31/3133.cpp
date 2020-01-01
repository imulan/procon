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

const int INF = 19191919;

int main(){
    int x,y,z,n,m,s,t;
    cin >>x >>y >>z >>n >>m >>s >>t;
    --s;
    --t;

    s = x+y+z+s;
    t = x+y+z+n+t;
    int V = x+y+z+n+m;
    vector<vector<int>> G(V);

    auto add_edge = [&](int u, int v){
        G[u].pb(v);
        G[v].pb(u);
    };

    int idx = x+y+z;

    rep(i,n){
        int a,b;
        cin >>a >>b;
        --a;
        --b;
        add_edge(idx,a);
        add_edge(idx,x+b);
        ++idx;
    }

    rep(i,m){
        int c,d;
        cin >>c >>d;
        --c;
        --d;
        add_edge(idx,x+c);
        add_edge(idx,x+y+d);
        ++idx;
    }

    vector<int> d(V,INF);
    d[s] = 0;
    queue<int> que({s});
    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(int e:G[v]){
            if(d[e] > d[v]+1){
                d[e] = d[v]+1;
                que.push(e);
            }
        }
    }

    int ans = d[t]/2;
    if(d[t]==INF) ans = -1;
    cout << ans << "\n";
    return 0;
}
