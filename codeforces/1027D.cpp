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
    int n;
    scanf(" %d", &n);
    vector<int> c(n);
    rep(i,n) scanf(" %d", &c[i]);

    vector<int> a(n);
    rep(i,n){
        scanf(" %d", &a[i]);
        --a[i];
        G[i].pb(a[i]);
        G[a[i]].pb(i);
    }

    int ans = 0;
    vector<bool> vis(n);
    rep(start,n)if(!vis[start]){
        queue<int> que;
        que.push(start);
        vis[start] = true;
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(int nx:G[v]){
                if(!vis[nx]){
                    que.push(nx);
                    vis[nx] = true;
                }
            }
        }

        vector<int> trail;
        set<int> s;
        int now = start;
        while(!s.count(now)){
            trail.pb(now);
            s.insert(now);
            now = a[now];
        }

        int sz = trail.size();
        int idx = 0;
        rep(i,sz)if(now==trail[i]) idx = i;

        int add = 12345678;
        for(int i=idx; i<sz; ++i) add = min(add, c[trail[i]]);
        ans += add;
    }
    printf("%d\n", ans);
    return 0;
}
