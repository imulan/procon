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

struct edge{ int to,cost; };

const int INF = 1e9+7;

int main(){
    int n;
    cin >>n;

    vector<pi> a(n),b(n);
    rep(i,n){
        cin >>a[i].fi;
        a[i].se = i;
    }
    rep(i,n){
        cin >>b[i].fi;
        b[i].se = i;
    }

    sort(all(a));
    sort(all(b));

    vector<vector<edge>> G(n);
    rep(i,n-1){
        int u = a[i].se, v = a[i+1].se;
        int d = a[i+1].fi-a[i].fi;
        G[u].pb({v,d});
        G[v].pb({u,d});
    }
    rep(i,n-1){
        int u = b[i].se, v = b[i+1].se;
        int d = b[i+1].fi-b[i].fi;
        G[u].pb({v,d});
        G[v].pb({u,d});
    }

    vector<int> d(n,INF);
    d[0] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0,0});
    while(!pq.empty()){
        pi c = pq.top();
        pq.pop();
        int v = c.se;
        if(c.fi > d[v]) continue;
        for(const auto &e:G[v]){
            if(d[e.to] > d[v]+e.cost){
                d[e.to] = d[v]+e.cost;
                pq.push({d[e.to],e.to});
            }
        }
    }

    rep(i,n) cout << d[i] << "\n";
    return 0;
}
