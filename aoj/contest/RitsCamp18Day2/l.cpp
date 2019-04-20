#include <bits/stdc++.h>
using namespace std;
#define _MACRO(_1, _2, _3, NAME, ...) NAME
#define _repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define _rep(i,n) _repl(i,0,n)
#define rep(...) _MACRO(__VA_ARGS__, _repl, _rep)(__VA_ARGS__)
#define mp make_pair
#define pb push_back
#define all(x) begin(x),end(x)
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define fi first
#define se second
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
void _dbg(string){cerr<<endl;}
template<class H,class... T> void _dbg(string s,H h,T... t){int l=s.find(',');cerr<<s.substr(0,l)<<" = "<<h<<", ";_dbg(s.substr(l+1),t...);}
template<class T,class U> ostream& operator<<(ostream &o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream &o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

const int N = 100005;

vector<int> tree[N];

template<int SZ>
class HLDecomp {
public:
  int n;
  void dfs(const int root){
    stack<pair<int,bool> > st;
    par[root] = -1;
    dep[root] = 0;
    st.push({root,false});
    while(!st.empty()){
      int v = st.top().first;
      bool &b = st.top().second;
      if(!b){
        // initial visit of v
        b = true;
        for(int u : tree[v]) if(u != par[v]){
          par[u] = v;
          dep[u] = dep[v] + 1;
          st.push({u, false});
        }
      }
      else {
        // second visit
        st.pop();
        int cur_max = 0;
        for(int u : tree[v]) if(u != par[v]){
          sub_sz[v] += sub_sz[u];
          if(sub_sz[u] > cur_max){
            cur_max = sub_sz[u];
            heavy_child[v] = u;
          }
        }
      }
    }
  }
  void bfs(const int root){
    int cnt = 0;
    queue<int> q;
    q.push(root);
    while(!q.empty()){
      int h = q.front(); q.pop();
      for(int i=h; i!=-1; i = heavy_child[i]){
        vid[i] = cnt++;
        vid2idx[vid[i]] = i;
        chain_head[i] = h;
        for(int to : tree[i]) if(to!=par[i] && to!=heavy_child[i]) q.push(to);
      }
    }
  }

  int par[SZ], dep[SZ], sub_sz[SZ], heavy_child[SZ], vid[SZ], vid2idx[SZ], chain_head[SZ];
  HLDecomp(){}
  HLDecomp(const int _n) : n(_n) {
    assert(n<=SZ);
    fill(sub_sz, sub_sz+n, 1);
    fill(heavy_child, heavy_child+n, -1);
  }
  void add_edge(const int u, const int v){
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  void build(const int root = 0){
    dfs(root);
    bfs(root);
  }

  // 閉区間注意 SegTreeの区間 r+1 必要かも
  void for_each_vertex(int u, int v, const function<void(int,int)> &f) const {
    while(true){
      if(vid[u] > vid[v]) swap(u,v);
      f(max(vid[chain_head[v]], vid[u]), vid[v]);
      if(chain_head[u] != chain_head[v]) v = par[chain_head[v]];
      else break;
    }
  }
  int lca(int u, int v) const {
    while(true){
      if(vid[u] > vid[v]) swap(u,v);
      if(chain_head[u] == chain_head[v]) return u;
      v = par[chain_head[v]];
    }
  }
};

HLDecomp<N> hl;
vector<pair<long,int>> lval[N];
long hval[N];
long w[N];
long ch_max[N];
long pa_max[N];
long tw;

using P = pair<long,int>;

class SegTree {
public:
  int n;
  vector<vector<P>> data;
  vector<P> op(const vector<P> &lh, const vector<P> &rh) const {
    vector<P> ret;
    for(auto p : lh) ret.pb(p);
    for(auto p : rh) ret.pb(p);
    sort(all(ret), greater<P>());
    if(ret.size()>=4) ret.resize(3);
    return ret;
  }
  SegTree(int m){
    n=1;
    while(n<m) n*=2;
    data.resize(2*n);
    rep(i,m) data[i+n] = lval[hl.vid[i]];
    for(int i=n-1; i>0; i--) data[i] = op(data[i*2], data[i*2+1]);
  }
  vector<P> query(int l, int r) const {
    vector<P> v = {};
    for(l+=n, r+=n; l<r; l/=2, r/=2){
      if(l&1) v = op(v, data[l++]);
      if(r&1) v = op(data[--r], v);
    }
    return v;
  }
};

long dfs(int v, int pre){
  ch_max[v] = 0;
  long ret = w[v];
  for(auto nx : tree[v]) if(nx != pre){
    long r = dfs(nx, v);
    ch_max[v] = max(ch_max[v], r);
    ret += r;
    if(nx == hl.heavy_child[v]) hval[v] = r;
    else lval[v].push_back({r, nx});
  }
  sort(all(lval[v]), greater<P>());
  if(lval[v].size()>=4) lval[v].resize(3);
  pa_max[v] = tw - ret;
  return ret;
}


int main(){
  int n;
  cin>>n;
  rep(i,n) scanf("%ld", w+i);
  tw = accumulate(w, w+n, 0L);
  hl = HLDecomp<N>(n);

  rep(i,n-1){
    int a,b;
    scanf("%d %d", &a, &b);
    a--;b--;
    hl.add_edge(a,b);
  }

  hl.build();
  dfs(0, -1);

  SegTree st(n);

  int q;
  scanf("%d", &q);
  rep(_,q){
    int a,b;
    scanf("%d %d", &a, &b);
    a--;b--;
    if(a==b){
      cout << max(ch_max[a], pa_max[a]) << "\n";
      continue;
    }
    int cp = hl.lca(a,b);

    long cand;
    if(cp == a) cand = ch_max[b];
    else if(cp == b) cand = ch_max[a];
    else cand = max(ch_max[a], ch_max[b]);
    cand = max(cand, pa_max[hl.lca(a,b)]);

    hl.for_each_vertex(a, b, [&](auto l, auto r){
      cand = max(cand, hval[hl.vid2idx[r]]);
      auto v = st.query(l ,r+1);
      // dbg(cand, hl.vid2idx[l], hl.vid2idx[r], hval[hl.vid2idx[r]], pa_max[hl.vid2idx[l]], v);
      for(auto &p : v){
        if(hl.lca(p.second,a) != p.second && hl.lca(p.second,b) != p.second){
          cand = max(cand, p.first);
          return;
        }
      }
    });
    printf("%ld\n", cand);
  }

  return 0;
}

