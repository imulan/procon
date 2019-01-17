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

struct edge{ int to,cost; };
const int INF = INT_MAX/3;

int main(){
    int n,m;
    while(cin >>n >>m,n){
        string s,p,g;
        cin >>s >>p >>g;

        map<string,int> name2idx;
        name2idx[s] = 0;
        name2idx[p] = 1;
        name2idx[g] = 2;

        int V = 3;

        vector<string> a(m),b(m);
        vector<int> c(m);
        rep(i,m){
            int d,t;
            cin >>a[i] >>b[i] >>d >>t;

            c[i] = d/40 + t;

            if(!name2idx.count(a[i])){
                name2idx[a[i]] = V;
                ++V;
            }
            if(!name2idx.count(b[i])){
                name2idx[b[i]] = V;
                ++V;
            }
        }

        vector<vector<edge>> G(V);
        rep(i,m){
            int u = name2idx[a[i]], v = name2idx[b[i]];
            G[u].pb({v,c[i]});
            G[v].pb({u,c[i]});
        }

        vector<int> d(V,INF);
        d[1] = 0;

        using pi = pair<int,int>;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0,1});
        while(!pq.empty()){
            pi now = pq.top();
            pq.pop();
            int v = now.se;
            if(now.fi > d[v]) continue;
            for(const auto &e:G[v]){
                if(d[e.to] > d[v]+e.cost){
                    d[e.to] = d[v]+e.cost;
                    pq.push({d[e.to], e.to});
                }
            }
        }

        cout << d[0]+d[2] << "\n";
    }
    return 0;
}
