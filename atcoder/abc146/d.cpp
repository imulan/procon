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

using pi = pair<int,int>;

int main(){
    int n;
    cin >>n;

    vector<vector<int>> G(n);
    map<pi,int> m;
    rep(i,n-1){
        int a,b;
        cin >>a >>b;
        --a;
        --b;

        G[a].pb(b);
        G[b].pb(b);
        m[{a,b}] = m[{b,a}] = i;
    }

    vector<int> c(n-1);

    vector<set<int>> used(n);
    vector<bool> vis(n);
    vis[0] = true;
    queue<int> que({0});
    while(!que.empty()){
        int v = que.front();
        que.pop();
        int now = 1;
        for(int nx:G[v])if(!vis[nx]){
            while(used[v].count(now)) ++now;
            used[v].insert(now);
            used[nx].insert(now);

            int eidx = m[{v,nx}];
            c[eidx] = now;

            que.push(nx);
            vis[nx] = true;
        }
    }

    int ans = 0;
    rep(i,n) ans = max(ans, (int)G[i].size());

    cout << ans << "\n";
    rep(i,n-1) cout << c[i] << "\n";
    return 0;
}
