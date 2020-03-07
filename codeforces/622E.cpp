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
    int n;
    scanf(" %d", &n);

    vector<vector<int>> G(n);
    vector<int> c;
    rep(i,n-1){
        int u,v;
        scanf(" %d %d", &u, &v);
        --u;
        --v;
        if(u>v) swap(u,v);
        if(u==0) c.pb(v);

        G[u].pb(v);
        G[v].pb(u);
    }

    vector<int> d(n,n);
    int ans = 0;
    for(int r:c){
        d[r] = 1;
        vector<int> a;
        queue<int> que({r});
        while(!que.empty()){
            int v = que.front();
            que.pop();

            if(G[v].size() == 1) a.pb(v);

            for(int nx:G[v])if(nx != 0 && d[nx] > d[v]+1){
                d[nx] = d[v]+1;
                que.push(nx);
            }
        }

        int A = a.size();
        rep(i,A) a[i] = d[a[i]];
        sort(all(a), greater<int>());

        rep(i,A) ans = max(ans, a[i]+i);
    }
    printf("%d\n", ans);
    return 0;
}
