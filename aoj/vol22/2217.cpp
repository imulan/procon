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

int main(){
    int n;
    while(cin >>n,n){
        auto f = [&](int y, int x){
            return y*n+x;
        };

        const int V = n*n;
        vector<vector<int>> G(V);
        rep(i,n)rep(j,n){
            int x,y;
            cin >>x >>y;

            int u = f(i,j), v = f(y,x);
            G[u].pb(v);
            G[v].pb(u);
        }

        int ans = 0;
        vector<bool> vis(V);
        rep(i,V)if(!vis[i]){
            vis[i] = true;
            ++ans;
            queue<int> que({i});
            while(!que.empty()){
                int v = que.front();
                que.pop();
                for(int e:G[v])if(!vis[e]){
                    vis[e] = true;
                    que.push(e);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
