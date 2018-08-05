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

const int N = 200000;
vector<int> G[N];

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    rep(i,m){
        int u,v;
        scanf(" %d %d", &u, &v);
        --u;
        --v;
        G[u].pb(v);
        G[v].pb(u);
    }

    int ans = 0;
    vector<bool> vis(n);
    rep(i,n)if(!vis[i]){
        vector<int> cc;
        queue<int> que;

        vis[i] = true;
        cc.pb(i);
        que.push(i);
        while(!que.empty()){
            int now = que.front();
            que.pop();
            for(int nx:G[now]){
                if(!vis[nx]){
                    vis[nx] = true;
                    cc.pb(nx);
                    que.push(nx);
                }
            }
        }

        int cycle = 1;
        for(int v:cc){
            if(G[v].size()!=2) cycle = 0;
        }
        ans += cycle;
    }
    printf("%d\n", ans);
    return 0;
}
