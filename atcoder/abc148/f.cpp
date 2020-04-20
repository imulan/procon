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

int main(){
    int n,u,v;
    cin >>n >>u >>v;
    --u;
    --v;

    vector<vector<int>> G(n);
    rep(i,n-1){
        int a,b;
        cin >>a >>b;
        --a;
        --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    auto BFS = [&](int s){
        vector<int> d(n,n);
        d[s] = 0;
        queue<int> que({s});
        while(!que.empty()){
            int x = que.front();
            que.pop();
            for(int e:G[x])if(d[e] > d[x]+1){
                d[e] = d[x]+1;
                que.push(e);
            }
        }
        return d;
    };

    vector<int> du = BFS(u), dv = BFS(v);

    int ans = 0;
    rep(i,n){
        if(du[i]<dv[i] && G[i].size()==1){
            int nx = G[i][0];
            ans = max(ans, dv[nx]);
        }
    }
    cout << ans << "\n";
    return 0;
}
