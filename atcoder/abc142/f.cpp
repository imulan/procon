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

const int N = 1000;
vector<int> G[N];

bool found = false;
vector<int> buf,cycle;
int vis[N] = {};

void dfs(int x){
    vis[x] = 2;
    buf.pb(x);

    for(int nx:G[x]){
        if(vis[nx]==2 && !found){
            int idx = 0;
            while(buf[idx]!=nx) ++idx;

            vector<int> t;
            int sz = buf.size();
            for(int i=idx; i<sz; ++i) cycle.pb(buf[i]);

            found = true;
        }

        if(!vis[nx]) dfs(nx);
    }

    vis[x] = 1;
    buf.pop_back();
}

int main(){
    int n,m;
    cin >>n >>m;
    vector<pi> e(m);
    rep(i,m){
        int a,b;
        cin >>a >>b;
        --a;
        --b;

        e[i] = {a,b};
        G[a].pb(b);
    }

    rep(i,n)if(!vis[i] && !found) dfs(i);
    if(!found){
        cout << -1 << "\n";
        return 0;
    }

    rep(loop,n){
        bool upd = false;

        int C = cycle.size();
        vector<int> idx(n,-1);
        rep(i,C) idx[cycle[i]] = i;

        for(const pi &p:e){
            int a = p.fi, b = p.se;
            if(idx[a]!=-1 && idx[b]!=-1 && (idx[a]+1)%C != idx[b]){
                vector<bool> next(C);
                if(idx[a] < idx[b]){
                    fill(all(next), true);
                    for(int i=idx[a]+1; i<idx[b]; ++i) next[i] = false;
                }
                else{
                    fill(all(next), false);
                    for(int i=idx[b]; i<=idx[a]; ++i) next[i] = true;
                }

                vector<int> t;
                rep(i,C)if(next[i]) t.pb(cycle[i]);

                cycle = t;
                upd = true;
                break;
            }
        }
        if(!upd) break;
    }

    cout << cycle.size() << "\n";
    for(int i:cycle) cout << i+1 << "\n";
    return 0;
}
