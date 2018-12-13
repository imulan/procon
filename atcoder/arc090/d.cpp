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

const ll INF = LLONG_MAX/3;
const int N = 100000;

struct edge{
    int to;
    ll cost;
};

vector<edge> G[N];
ll x[N];

void dfs(int v){
    for(const auto &e:G[v]){
        if(x[e.to]==INF){
            x[e.to] = x[v]+e.cost;
            dfs(e.to);
        }
    }
}

int main(){
    int n,m;
    cin >>n >>m;

    vector<int> l(m),r(m),d(m);
    rep(i,m){
        cin >>l[i] >>r[i] >>d[i];
        --l[i];
        --r[i];

        G[l[i]].pb({r[i],d[i]});
        G[r[i]].pb({l[i],-d[i]});
    }

    fill(x,x+N,INF);
    rep(i,n){
        if(x[i]==INF){
            x[i] = 0;
            dfs(i);
        }
    }

    string ans = "Yes";
    rep(i,m){
        if(x[r[i]] - x[l[i]] !=  d[i]) ans = "No";
    }
    cout << ans << endl;
    return 0;
}
