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

const int V = 50000;
vector<int> G[V];
int vid[V],inv[V],depth[V],par[V],heavy[V],head[V],sub[V];

void add_edge(int u, int v){
    G[u].pb(v);
    G[v].pb(u);
}

void dfs(int cur, int pre){
    par[cur] = pre;
    sub[cur] = 1;
    int max_sub = 0;
    for(int nx:G[cur])if(nx != pre){
        depth[nx] = depth[cur] + 1;
        dfs(nx, cur);
        sub[cur] += sub[nx];
        if(max_sub < sub[nx]){
            max_sub = sub[nx];
            heavy[cur] = nx;
        }
    }
}

void dfs2(int root){
    int k = 0;
    stack<int> que({root});
    while(!que.empty()){
        int cur = que.top();
        que.pop();

        // curを先頭とするheavy-pathの処理
        for(int i=cur; i!=-1; i=heavy[i]){
            vid[i] = k++;
            inv[vid[i]] = i;
            head[i] = cur;
            // heavy-pathの先頭になるなら push
            for(int nx:G[i])if(nx != par[i] && nx != heavy[i]){
                que.push(nx);
            }
        }
    }
}

void build(int root = 0){
    dfs(root,-1);
    dfs2(root);
}

inline int lca(int u, int v){
    while(1){
        if(vid[u] > vid[v]) swap(u,v);
        if(head[u] == head[v]) return u;
        v = par[head[v]];
    }
}

struct BIT{
    int n;
    vector<int> bit;
    BIT(){}
    BIT(int _n){
        n = _n;
        bit = vector<int>(n+1,0);
    }

    int sum(int i){
        ++i;
        int s = 0;
        while(i>0){
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    void update(int i){
        ++i;
        while(i<=n){
            bit[i] += 1;
            i += i & -i;
        }
    }

    int query(int l, int r){
        return sum(r) - sum(l-1);
    }
};

BIT st;

inline int SUM(int u, int v){
    int ret = 0;
    while(1){
        if(vid[u] > vid[v]) swap(u,v);

        if(head[u] == head[v]){
            ret += st.query(vid[u]+1, vid[v]);
            break;
        }

        ret += st.query(vid[head[v]], vid[v]);
        v = par[head[v]];
    }
    return ret;
}

inline void ADD(int u, int v){
    if(depth[u] < depth[v]) swap(u,v);
    st.update(vid[u]);
}

inline int DIST(int u, int v){
    int LCA = lca(u,v);
    return depth[u] + depth[v] - 2*depth[LCA];
}

const int N = 100001;
int a[N],b[N],d[N];

int l[N],r[N];
int ans[N][2];

vector<int> QUERY[N];

using pi = pair<int,int>;
using edge = pair<int,pi>;

int main(){
    int T;
    scanf(" %d", &T);
    rep(case_num,T){
        rep(i,N) QUERY[i].clear();

        rep(i,V) G[i].clear();
        memset(heavy,-1,sizeof(heavy));
        memset(vid,0,sizeof(vid));
        memset(inv,0,sizeof(inv));
        memset(depth,0,sizeof(depth));
        memset(par,0,sizeof(par));
        memset(head,0,sizeof(head));
        memset(sub,0,sizeof(sub));

        // input
        int n;
        scanf(" %d", &n);

        vector<int> uw;
        vector<edge> E(n-1);
        rep(i,n-1){
            int u,v,w;
            scanf(" %d %d %d", &u, &v, &w);
            --u;
            --v;
            add_edge(u,v);
            E[i] = {w,{u,v}};
            uw.pb(w);
        }
        build();

        sort(all(E));

        sort(all(uw));
        uw.erase(unique(all(uw)), uw.end());
        int W = uw.size();

        int Q;
        scanf(" %d", &Q);

        rep(i,Q){
            scanf(" %d %d", &a[i], &b[i]);
            --a[i];
            --b[i];
            d[i] = DIST(a[i],b[i]);
        }

        rep(add,2){
            rep(i,Q){
                l[i] = -1;
                r[i] = W-1;
            }

            rep(loop,16){
                rep(i,W) QUERY[i].clear();
                rep(i,Q) QUERY[ (l[i]+r[i])/2 ].pb(i);

                st = BIT(n+1);

                // printf(" ----- \n");
                int eidx = 0;
                rep(ww,W){
                    while(eidx < n-1){
                        if(E[eidx].fi <= uw[ww]) ADD(E[eidx].se.fi, E[eidx].se.se);
                        else break;
                        ++eidx;
                    }

                    // printf("ww %d, uw[ww] %d\n", ww, uw[ww]);
                    for(int qid:QUERY[ww]){
                        int s = SUM(a[qid], b[qid]);
                        // printf(" qid %d ,  s  %d\n", qid,s);

                        if(d[qid]/2+add <= s) r[qid] = ww;
                        else l[qid] = ww;
                    }
                }
            }

            rep(i,Q) ans[i][add] = uw[r[i]];
        }

        rep(i,Q){
            if(d[i]%2==1) printf("%d.0\n", ans[i][1]);
            else printf("%.1f\n", (ans[i][0]+ans[i][1])/2.0);
        }
    }
    return 0;
}
