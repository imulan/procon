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

const int N = 200002;
vector<int> G[N];
int par[N];
int d[N];

void dfs(int x){
    for(int c:G[x])if(c!=par[x]){
        par[c] = x;
        d[c] = d[x]+1;
        dfs(c);
    }
}

int main(){
    int n;
    cin >>n;
    rep(i,n-1){
        int u,v;
        cin >>u >>v;
        --u;
        --v;
        G[u].pb(v);
        G[v].pb(u);
    }

    d[0]=0;
    par[0] = -1;
    dfs(0);

    vector<bool> ok(n);
    priority_queue<pi> pq;
    rep(i,n){
        if(d[i]>2) pq.push({d[i],i});
        else ok[i] = true;
    }

    int ans = 0;
    while(!pq.empty()){
        pi now = pq.top();
        pq.pop();
        int v = now.se;
        if(ok[v]) continue;

        ++ans;
        v = par[v];
        ok[v] = true;
        for(int e:G[v]) ok[e] = true;
    }

    cout << ans << endl;
    return 0;
}
