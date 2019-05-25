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

const int N = 400000;
vector<pi> G[N];

int main(){
    int n;
    scanf(" %d", &n);

    vector<int> u;
    vector<int> a(n),b(n);
    rep(i,n){
        scanf(" %d %d", &a[i], &b[i]);
        u.pb(a[i]);
        u.pb(b[i]);
    }

    sort(all(u));
    u.erase(unique(all(u)), u.end());
    int U = u.size();

    rep(i,n){
        a[i] = lower_bound(all(u), a[i]) - u.begin();
        b[i] = lower_bound(all(u), b[i]) - u.begin();
        G[a[i]].pb({b[i],i});
        G[b[i]].pb({a[i],i});
    }

    int ans = 0;
    vector<bool> vis(U);
    rep(i,U)if(!vis[i]){
        vis[i] = true;
        queue<int> que({i});

        int cc = 1;
        set<int> e;
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(pi p:G[v]){
                e.insert(p.se);
                if(!vis[p.fi]){
                    vis[p.fi] = true;
                    que.push(p.fi);
                    ++cc;
                }
            }
        }
        int ee = e.size();

        ee = min(ee, cc);
        ans += ee;
    }
    printf("%d\n", ans);
    return 0;
}
