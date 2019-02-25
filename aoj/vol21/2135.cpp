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

const int INF = 10101010;

int main(){
    int n;
    while(cin >>n,n){
        int s,t;
        cin >>s >>t;
        --s;
        --t;

        vector<vector<int>> G(n),rG(n);

        auto add_edge = [&](int u, int v){
            G[u].pb(v);
            rG[v].pb(u);
        };

        int m;
        cin >>m;
        vector<int> a(m),b(m);
        rep(i,m){
            cin >>a[i] >>b[i];
            --a[i];
            --b[i];
            add_edge(a[i],b[i]);
        }

        auto BFS = [&](int start, vector<vector<int>>g){
            vector<int> d(n,INF);
            d[start] = 0;
            queue<int> que({start});
            while(!que.empty()){
                int v = que.front();
                que.pop();
                for(int e:g[v]){
                    if(d[e] > d[v]+1){
                        d[e] = d[v]+1;
                        que.push(e);
                    }
                }
            }
            return d;
        };

        vector<int> ds = BFS(s,G), dt = BFS(t,rG);

        int eidx = -1;
        int ans = ds[t];
        rep(i,m){
            int dd = ds[b[i]] + 1 + dt[a[i]];
            if(ans > dd){
                ans = dd;
                eidx = i;
            }
        }

        cout << ans << " " << eidx+1 << "\n";
    }
    return 0;
}
