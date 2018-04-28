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

struct edge{
    int to;
    ll cost;
    int trans;
};

const int N = 200000;
const ll INF = LLONG_MAX/3;

using pi = pair<int,int>;
using pl = pair<ll,int>;

vector<edge> G[N];
pl d[N];

int main(){
    int n,T;
    string start,goal;
    cin >>n >>T >>start >>goal;

    map<string,int> s2id;
    int num = 0;
    s2id[start] = num++;
    s2id[goal] = num++;

    vector<int> a(n);
    vector<vector<int>> r(n),t(n);
    rep(i,n){
        cin >>a[i];
        r[i] = vector<int>(a[i]);
        t[i] = vector<int>(a[i]-1);

        rep(j,a[i]){
            string tmp;
            cin >>tmp;
            if(!s2id.count(tmp)) s2id[tmp] = num++;
            r[i][j] = s2id[tmp];
        }
        rep(j,a[i]-1) cin >>t[i][j];
    }

    map<pair<int,pi>, int> p2id;
    int SZ = 0;
    rep(i,num) p2id[{i,{-1,-1}}] = SZ++;

    rep(i,n){
        rep(j,a[i]){
            if(!p2id.count({r[i][j], {i,j}})) p2id[{r[i][j], {i,j}}] = SZ++;
            int u = p2id[{r[i][j], {i,j}}], v = p2id[{r[i][j], {-1,-1}}];

            if(r[i][j]==1) G[u].pb({v,0,0});
            else G[u].pb({v,T,1});
            G[v].pb({u,0,0});
        }

        rep(j,a[i]-1){
            int u = p2id[{r[i][j], {i,j}}], v = p2id[{r[i][j+1], {i,j+1}}];
            G[u].pb({v,t[i][j],0});
            G[v].pb({u,t[i][j],0});
        }
    }

    fill(d,d+N,pl(INF,N));
    using P = pair<pl,int>;
    priority_queue<P, vector<P>, greater<P>> pq;

    d[p2id[{0,{-1,-1}}]] = {0,0};
    pq.push({{0,0},p2id[{0,{-1,-1}}]});
    while(!pq.empty()){
        P now = pq.top();
        pq.pop();

        int v = now.se;
        if(now.fi > d[v]) continue;

        for(const auto &e:G[v]){
            pl nx = now.fi;
            nx.fi += e.cost;
            nx.se += e.trans;

            if(d[e.to] > nx){
                d[e.to] = nx;
                pq.push({nx, e.to});
            }
        }
    }

    pl ans = d[p2id[{1,{-1,-1}}]];
    if(ans.fi == INF) cout << -1 << endl;
    else cout << ans.fi << " " << ans.se << endl;
    return 0;
}
