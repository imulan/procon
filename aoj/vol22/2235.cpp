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

struct UF{
    int n;
    //正だったらその頂点の親,負だったら根で連結成分の個数
    vector<int> d;
    UF() {}
    UF(int N):n(N), d(N,-1){}
    int root(int v){
        if(d[v]<0) return v;
        return d[v]=root(d[v]);
    }
    bool unite(int X,int Y){
        X=root(X); Y=root(Y);
        if(X==Y) return false;
        if(size(X) < size(Y)) swap(X,Y);
        d[X]+=d[Y];
        d[Y]=X;
        return true;
    }
    int size(int v){ return -d[root(v)]; }
    bool same(int X,int Y){ return root(X)==root(Y); }
};

const int B = 200;

using pi = pair<int,int>;

int main(){
    int n,k;
    scanf(" %d %d", &n, &k);

    vector<int> t(k);
    vector<pi> e(k);
    rep(i,k) scanf(" %d %d %d", &t[i], &e[i].fi, &e[i].se);

    rep(i,B){
        if(i*B >= k) break;

        set<pi> add;
        rep(j,i*B){
            if(t[j] == 1) add.insert(e[j]);
            else if(t[j] == 2) add.erase(e[j]);
        }

        set<pi> pre;
        rep(j,B){
            int idx = i*B + j;
            if(idx >= k) break;

            if(t[idx] == 2){
                if(add.count(e[idx])){
                    add.erase(e[idx]);
                    pre.insert(e[idx]);
                }
            }
        }

        UF uf(n);
        for(pi p:add) uf.unite(p.fi, p.se);

        vector<int> v2id(n,-1);
        int V = 0;

        rep(j,B){
            int idx = i*B + j;
            if(idx >= k) break;

            // dbg(idx);dbg(e[idx]);

            int u = uf.root(e[idx].fi), v = uf.root(e[idx].se);
            for(int tt:{u,v}){
                if(v2id[tt] == -1){
                    v2id[tt] = V;
                    ++V;
                }
            }
        }

        vector<multiset<int>> G(V);
        for(pi p:pre){
            int u = v2id[uf.root(p.fi)], v = v2id[uf.root(p.se)];
            G[u].insert(v);
            G[v].insert(u);
        }

        rep(j,B){
            int idx = i*B + j;
            if(idx >= k) break;

            int u = v2id[uf.root(e[idx].fi)], v = v2id[uf.root(e[idx].se)];
            if(t[idx] == 1){
                if(u != v){
                    G[u].insert(v);
                    G[v].insert(u);
                }
            }
            else if(t[idx] == 2){
                if(u != v){
                    G[u].erase( G[u].find(v) );
                    G[v].erase( G[v].find(u) );
                }
            }
            else{
                vector<bool> vis(V);
                queue<int> que;
                vis[u] = true;
                que.push(u);
                while(!que.empty()){
                    int now = que.front();
                    que.pop();
                    for(int nx:G[now]){
                        if(!vis[nx]){
                            vis[nx] = true;
                            que.push(nx);
                        }
                    }
                }

                if(vis[v]) printf("YES\n");
                else printf("NO\n");
            }
        }
    }

    return 0;
}
