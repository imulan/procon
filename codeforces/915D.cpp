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

const int N = 500;
vector<int> G[N];

bool found;
vector<int> cycle;
bool vis[N];

int start;
void dfs(int x){
    vis[x] = true;
    for(int e:G[x]){
        if(e==start){
            found = true;
            return;
        }

        if(!vis[e]){
            cycle.pb(e);
            dfs(e);
            if(found) return;

            cycle.pop_back();
        }
    }
}

bool solve(){
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<int> u(m), v(m);
    rep(i,m){
        scanf(" %d %d", &u[i], &v[i]);
        --u[i];
        --v[i];
        G[u[i]].pb(v[i]);
    }

    auto find_cycle = [&](){
        rep(i,n){
            found = false;
            fill(vis, vis+N, false);
            cycle.clear();
            cycle.pb(i);
            start = i;
            dfs(i);
            if(found) return true;
        }
        return false;
    };

    if(!find_cycle()) return true;

    vector<int> cand = cycle;
    int C = cand.size();
    rep(i,C){
        int uu = cand[i], vv = cand[(i+1)%C];
        // printf(" CHECK %d: %d -> %d\n", i,uu,vv);

        rep(j,n) G[j].clear();
        rep(j,m){
            if(u[j]==uu && v[j]==vv) continue;
            // printf(" ADD %d -> %d\n", u[j],v[j]);
            G[u[j]].pb(v[j]);
        }

        if(!find_cycle()) return true;
    }

    return false;
}

int main(){
    cout << (solve()?"YES":"NO") << endl;
    return 0;
}
