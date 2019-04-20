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

const int N = 7500;
set<int> G[N];

void add_edge(int u, int v){
    G[u].insert(v);
    G[v].insert(u);
}

int cb(int x){
    return x*x*x;
}

int main(){
    int r,k;
    cin >>r >>k;

    vector<int> a(k);
    rep(i,k) cin >>a[i];

    int R = 2*r-1;

    vector<vector<int>> row(R);
    int now = 1;

    int pl = 1;
    int num = r;
    rep(i,R){
        vector<int> v(num);
        rep(j,num) v[j] = now++;

        row[i] = v;

        // dbg(row[i]);

        if(i == r-1) pl = -1;
        num += pl;
    }

    rep(i,R){
        int sz = row[i].size();
        rep(j,sz-1){
            int u = row[i][j], v = row[i][j+1];
            add_edge(u,v);
        }
    }

    auto make_vertical = [&](const vector<int> &x, const vector<int> &y){
        int X = x.size(), Y = y.size();
        assert(Y == X+1);

        rep(i,X){
            add_edge(x[i],y[i]);
            add_edge(x[i],y[i+1]);
        }
    };

    rep(i,r-1){
        vector<int> x = row[i], y = row[i+1];
        make_vertical(x,y);
    }

    for(int i=R-1; i>r-1; --i){
        vector<int> x = row[i], y = row[i-1];
        make_vertical(x,y);
    }

    int n = cb(r)-cb(r-1);

    // for(int i=1; i<=n; ++i){
    //     vector<int> adj(G[i].begin(), G[i].end());
    //     printf("%3d : ",i);dbg(adj);
    // }

    vector<bool> house(n+1,false);
    rep(i,k) house[a[i]] = true;

    vector<bool> vis(n+1,false);
    queue<int> que;

    for(int i:{0,R-1}){
        for(int j:row[i]){
            if(!house[j]){
                vis[j] = true;
                que.push(j);
            }
        }
    }
    for(int i=1; i<R-1; ++i){
        for(int j:{row[i].front(), row[i].back()}){
            if(!house[j]){
                vis[j] = true;
                que.push(j);
            }
        }
    }

    while(!que.empty()){
        int v = que.front();
        que.pop();
        // dbg(v);
        for(int e:G[v]){
            if(!house[e] && !vis[e]){
                vis[e] = true;
                que.push(e);
            }
        }
    }

    int ans = 0;
    for(int i=1; i<=n; ++i){
        if(!vis[i] && house[i]){
            int sz = G[i].size();
            ans += 6-sz;

            for(int e:G[i])if(vis[e]) ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
