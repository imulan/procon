alias g='g++-8 -O2 -std=c++14 -Wextra -W -Wshadow -fsanitize=undefined -fsanitize=address'

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()

/* INDEX
yamad:
  GNU extension / SA / LCP / Z algorithm / Aho Crasick / Rolling Hash / linear congruence equation / Matrix ( gauss_jordan / det / mod_inv_matrix / getrank) / euler_phi_list / FFT / Combination / UnionFind / BIT / BIT 2d / LazySegTree / ValueSegmentTree on Tree / centroid decomposition
ryoissy:
  Convex Hull Trick / Radix Heap / Sparse Table / Treap / Lowest Common Ancestor / Diameter (by DP) / Find EulerPath(有向グラフ) / Graph_Bridge(橋・間接点検出, 二重辺連結成分分解) / Hungarian / 木の上に対するクエリの解き方 / LL(1)式構文解析パーサ(四則演算) / 数式を処理するセグメント木
imulan:
  geometry / Dinic / MinCostFlow / GlobalMinCut / SCC / TwoSat / 最小有向全域木 / HL分解
*/

//// gnu extension
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;

template<class Key>
using ordered_set = __gnu_pbds::tree<Key, __gnu_pbds::null_type, less<Key>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

definition : ordered_set<Type> s;
order of key : s.order_of_key(hoge);
find by order : s.find_by_order(hoge);
other : same as set
*/

int len,crtk;
int ranks[MAX_N+1];
int tmp[MAX_N+1];
bool compare_sa(int i,int j){
  if(ranks[i]!=ranks[j])return ranks[i]<ranks[j];
  else{
    int ri=i+crtk<=len?ranks[i+crtk]:-1;
    int rj=j+crtk<=len?ranks[j+crtk]:-1;
    return ri<rj;
  }
}
vector<int> construct_sa(const string& s){
  vector<int> sa;
  len=s.size(); sa.resize(len+1);
  for(int i=0;i<=len;i++){
    sa[i]=i;
    ranks[i]=i<len?s[i]:-1;
  }
  for(crtk=1;crtk<=len;crtk*=2){
    sort(all(sa),compare_sa);
    tmp[sa[0]]=0;
    for(int i=1;i<=len;i++){
      tmp[sa[i]]=tmp[sa[i-1]]+(compare_sa(sa[i-1],sa[i])?1:0);
    }
    for(int i=0;i<=len;i++){
      ranks[i]=tmp[i];
    }
  }
  return sa;
}

vector<int> construct_lcp(const string& s,const vector<int>& sa){
  vector<int> lcp;
  int n=s.length(); lcp.resize(n+1);
  for(int i=0;i<=n;i++){
    ranks[sa[i]]=i;
  }
  int h=0;
  lcp[0]=0;
  for(int i=0;i<n;i++){
    int j=sa[ranks[i]-1];
    if(h>0)h--;
    while(j+h<n&&i+h<n){
      if(s[j+h]!=s[i+h])break;
      h++;
    }
    lcp[ranks[i]-1]=h;
  }
  return lcp;
}

vector<ll> z_algorithm(const string& S){
  const ll n=S.length();
  vector<ll> A(n);
  A[0] = n;
  int i = 1, j = 0;
  while (i < n) {
    while (i+j < n && S[j] == S[i+j]) ++j;
    A[i] = j;
    if (j == 0) { ++i; continue;}
    ll k = 1;
    while (i+k < n && k+A[k] < j) A[i+k] = A[k], ++k;
    i += k; j -= k;
  }
  return A;
}

int rad[2*MAX_N];
P longest_palindrome(string s){ // -> (index,length)
  int n=s.length();
  int i,j,k;
  for(i=0,j=0;i<2*n;i+=k,j=max(j-k,0)){
    while(i-j>=0&&i+j+1<2*n&&s[(i-j)/2]==s[(i+j+1)/2])j++;
    rad[i]=j;
    for(k=1;i-k>=0&&rad[i]-k>=0&&rad[i-k]!=rad[i]-k;k++){
      rad[i+k]=min(rad[i-k],rad[i]-k);
    }
  }
  int idx=(max_element(rad,rad+2*n)-rad)/2;
  int len=*max_element(rad,rad+2*n);
  idx-=(len-1)/2;
  return P(idx,len);
}

class PMA {
  PMA* next[27];
  vector<int> matched;

  PMA() { rep(i,27) next[i] = NULL; }

  void build(vector<string> &sp) {
    // trans
    vector<vector<int> > p;
    rep(i,sp.size()){
      p.push_back(vector<int>());
      rep(j,sp[i].size())p[p.size()-1].push_back((int)(sp[i][j]-'a'+1));
    }

    rep(i,27) next[i] = NULL;
    this->next[0] = this;
    rep(i,p.size()) {
      PMA *now = this;
      rep(j,p[i].size()) {
        if(now->next[p[i][j]] == 0) now->next[p[i][j]] = new PMA;
        now = now->next[p[i][j]];
      }
      now->matched.push_back(i);
    }

    queue<PMA*> q;
    repl(i,1,27) {
      if(!this->next[i]) this->next[i] = this;
      else {
        this->next[i]->next[0] = this;
        q.push(this->next[i]);
      }
    }

    while(!q.empty()) {
      PMA *now = q.front();
      q.pop();
      repl(i,1,27) if(now->next[i]){
        PMA *nxt = now->next[0];
        while(!nxt->next[i]) nxt = nxt->next[0];
        now->next[i]->next[0] = nxt->next[i];
        vector<int> &m1 = now->next[i]->matched, &m2 = nxt->next[i]->matched;
        rep(j, m2.size()) if(!binary_search(m1.begin(), m1.end(), m2[j])) m1.push_back(m2[j]);
        sort(m1.begin(), m1.end());
        q.push(now->next[i]);
      }
    }
  }

public:
  /* initialized by vector of pattern string */
  PMA(vector<string>& p) {
    build(p);
  }

  /* find all substring mathing pattern */
  vector< vector<int> > match(string ss) {
    // trans
    vector<int> s;
    rep(i,ss.size())s.push_back(ss[i]-'a'+1);

    vector< vector<int> > idx(s.size());
    PMA* pma = this;
    rep(i, s.size()) {
      while(!pma->next[s[i]]) pma = pma->next[0];
      pma = pma->next[s[i]];
      for(int j : pma->matched) idx[i].push_back(j);
    }
    return idx;
  }
};

using vl = vector<ll>;
const vl base{1009,1021};
const ll MOD = 1000000009;
// const vl mod{1000000009,1000000007};

// 2次元ハッシュ
// sの各P*Q部分のハッシュを計算
vector<vl> calc_hash(const vector<string> &s, int P, int Q){
    int n = s.size(), m = s[0].size();
    vector<vector<ll>> tmp(n,vl(m)), hash(n,vl(m));
    ll t0 = 1;
    rep(j,Q) (t0 *= base[0]) %= MOD;

    // 行方向
    rep(i,n){
        ll e = 0;
        rep(j,Q) e = (e*base[0] + s[i][j]) % MOD;

        for(int j=0; j+Q<=m; ++j){
            tmp[i][j] = e;
            if(j+Q < m) e = (e*base[0] - (t0*s[i][j])%MOD + MOD + s[i][j+Q]) % MOD;
        }
    }
    ll t1 = 1;
    rep(i,P) (t1 *= base[1]) %= MOD;
    for(int j=0; j+Q<=m; ++j){
        ll e = 0;
        rep(i,P) e = (e*base[1] + tmp[i][j]) % MOD;
        for(int i=0; i+P<=n; ++i){
            hash[i][j] = e;
            if(i+P < n) e = (e*base[1] - (t1*tmp[i][j])%MOD + MOD + tmp[i+P][j]) % MOD;
        }
    }
    return hash;
}

struct RollingHash{
    static const int MD = 3;
    static const vector<ll> hash_base, hash_mod;
    int n;
    vector<ll> hs[MD], pw[MD];
    RollingHash(){}
    RollingHash(const string &s){
        n = s.size();
        rep(i,MD){
            hs[i].assign(n+1,0);
            pw[i].assign(n+1,0);
            hs[i][0] = 0;
            pw[i][0] = 1;
            rep(j,n){
                pw[i][j+1] = pw[i][j]*hash_base[i] % hash_mod[i];
                hs[i][j+1] = (hs[i][j]*hash_base[i]+s[j]) % hash_mod[i];
            }
        }
    }
    // 1-index
    ll hash_value(int l, int r, int i){
        return ((hs[i][r] - hs[i][l]*pw[i][r-l])%hash_mod[i]+hash_mod[i])%hash_mod[i];
    }
    bool match(int l1, int r1, int l2, int r2){
        bool ret = true;
        rep(i,MD) ret &= (hash_value(l1-1,r1,i) == hash_value(l2-1,r2,i));
        return ret;
    }
    vector<ll> calc(int l, int r){
        vector<ll> ret(MD);
        rep(i,MD) ret[i]=hash_value(l-1,r,i);
        return ret;
    }
};
const vector<ll> RollingHash::hash_base{1009,1021,1013};
const vector<ll> RollingHash::hash_mod{1000000009,1000000007,1000000021};

//// linear congruence equation -- not verified A[i]x=B[i] (mod M[i]) の解
pair<int,int> linear_congruence(const vector<int>& A,const vector<int>& B,const vector<int>& M){
  int x=0,m=1;

  for(int i=0;i<A.size();i++){
    int a=A[i]*m,b=B[i]-A[i]*x,d=gcd(M[i],a);
    if(b%d!=0)return make_pair(0,-1); // no answer
    int t=b/d*mod_inverse(a/d,M[i]/d)%(M[i]/d);
    x=x+m*t;
    m*=M[i]/d;
  }
  return make_pair(x%m,m);
}

// Matrix
// 冪の和を求めるのは　(A|0)
// 　　　　　　　　　　(E|E) をかける

typedef vector<double> vec;
typedef vector<vec> mat;
vec gauss_jordan(const mat& A,const vec& b){
  int n=A.size();
  mat B(n,vec(n+1));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      B[i][j]=A[i][j];
    }
    B[i][n]=b[i];
  }
  for (int k = 0; k < n-1; k++) {
    for (int i = k + 1; i < n; i++) {
      double d = B[i][k] / B[k][k];
      for (int j = k + 1; j <= n; j++){
        B[i][j] -= B[k][j] * d;
      }
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    double d = B[i][n];
    for (int j = i + 1; j < n; j++){
      d -= B[i][j] * B[j][n];
    }
    B[i][n] = d / B[i][i];
  }
  vec x(n);
  for(int i=0;i<n;i++)x[i]=B[i][n];
  return x;
}

ll det(mat a){
// 行列木定理：ラプラシアン行列（i=jの時：頂点の次数、i!=jの時：辺があれば-1,なければ0）の左上部分行列の行列式が全域木の個数
  int N=a.size();
  mat tmp(N,vec(N));
  ll res=1;
  for(int i=0;i<N;i++)for(int j=0;j<N;j++)tmp[i][j]=a[i][j]%mod;
  for(int i=0;i<N;i++){
    int pivot=-1;
    for(int j=i;j<N;j++){
      if(tmp[j][i]>0)pivot=j;
    }
    if(pivot==-1)return 0;
    if(pivot!=i){
      res=mod-res;
      swap(tmp[i],tmp[pivot]);
    }
    for(int j=i+1;j<N;j++){
      tmp[i][j]=(tmp[i][j]*mod_pow(tmp[i][i],mod-2))%mod;
    }
    for(int j=i+1;j<N;j++){
      for(int k=i+1;k<N;k++)tmp[j][k]=(mod+tmp[j][k]-(tmp[j][i]*tmp[i][k])%mod)%mod;
    }
  }
  for(int i=0;i<N;i++)res=(res*tmp[i][i])%mod;
  return res%mod;
}

bool mod_inv_matrix(mat &A,int mod,mat &res){
  int n = A.size();
  mat B(n,vec(n+n));
  for(int i=0;i<n;i++)for(int j=0;j<n;j++) B[i][j] = A[i][j], B[i][n+j] = ( i == j );

  for(int x=0;x<n;x++){
    int pivot = -1;
    for(int j=x;j<n;j++) if( B[j][x] ) { pivot = j; break; }
    if( pivot == -1 ) return false;
    swap(B[x],B[pivot]);
    for(int j=0;j<n;j++) if( j != x ) {
      int t = B[j][x] * mod_pow(B[x][x],mod-2,mod) % mod;
      // int t = B[j][x] / B[x][x];
      if(t) for(int k=x;k<n+n;k++) B[j][k] = ( ( B[j][k] - B[x][k] * t ) % mod + mod ) % mod;
    }
    int t = mod_pow(B[x][x],mod-2,mod);
    // int t = 1.0 / B[x][x];
    for(int j=x;j<n+n;j++) B[x][j] = ( B[x][j] * t ) % mod;
  }

  res.clear();
  res.resize(n,vec(n));
  for(int i=0;i<n;i++)for(int j=0;j<n;j++) res[i][j] = B[i][n+j];
  return true;
}

int getrank(mat A,int mod) {
  int H = A.size(), W = A[0].size();
  int r = 0;
  for(int x = 0; x < W; x++){
    int pivot = -1;
    for(int y = r; y < H; y++) if(A[y][x]) {
      pivot = y;
      break;
    }
    if( pivot == -1 )continue;
    swap(A[r], A[pivot]);
    for(int y = r+1; y < H; y++) {
      int value = A[y][x] * mod_pow(A[r][x], mod-2, mod) % mod;
      // int value = A[y][x] / A[r][x];
      if(value) for(int x2 = x; x2 < W; x2++) A[y][x2] = ((A[y][x2] - A[r][x2] * value)%mod + mod ) % mod;
    }
    r++;
  }
  return r;
}

int euler[MAX_N];
void euler_phi_list(){
  for(int i=0;i<MAX_N;i++)euler[i]=i;
    for(int i=2;i<MAX_N;i++){
      if(euler[i]==i){
        for(int j=i;j<MAX_N;j+=i)euler[j]=euler[j]/i*(i-1);
      }
  }
}

ll discrete_logarithm(ll g,ll y){
  map<ll,ll> idx;
  ll m=(ll)ceil(sqrt((double)y));
  ll tmp=1;
  for(ll j=0;j<m;j++){
    idx[tmp]=j;
    tmp=tmp*g%mod;
  }
  ll g_inv_m=mod_pow(mod_pow(g,mod-2),m);
  tmp=y;
  for(ll i=0;i<m;i++){
    if(idx.count(tmp)){
      return i*m+idx[tmp];
    }
    tmp=tmp*g_inv_m%mod;
  }
  return -1; // fail
}

ll mod_sqrt(ll a,ll p) {
  if(a==0) return 0;
  if(p==2) return a;
  if(!is_square(a,p)) return -1;
  ll b=2;
  while(is_square((b*b-a+p)%p,p))b++;
  ll w=(b*b-a+p)%p;

  auto mul=[&](pair<ll,ll> u,pair<ll,ll> v) {
    ll a=(u.first*v.first+u.second*v.second%p*w)%p;
    ll b=(u.first*v.second+u.second*v.first)%p;
    return make_pair(a,b);
  };

  // (b + sqrt(b^2-a))^(p+1)/2
  ll e=(p+1)/2;
  auto ret=make_pair(1,0);
  auto v=make_pair(b,1);
  while(e>0){
    if(e&1)ret=mul(ret,v);
    v=mul(v,v);
    e/=2;
  }
  return ret.first;
}

// not verified
double lagrange_interpol(vector<double> x,vector<double> y,double x1){
  double s1,s2,y1=0.0;
  int n=x.size();
  for(int i=0;i<n;i++){
    double s1=1.0,s2=1.0;
    for(int j=0;j<n;j++){
      if(i!=j){
        s1*=(x1-x[j]);
        s2*=(x[i]-x[j]);
      }
    }
    y1+=y[i]*s1/s2;
  }
  return y1;
}

//// FFT
#define X real()
#define Y imag()
struct FFT {
  using C = complex< double >;
  const double PI = acos(-1);
  vector< vector< C > > rts, rrts;

  void DFT(vector< C > &F, bool rev) {
    int N = (int) F.size();
    auto &r = rev ? rrts : rts;

    for(int i = 0, j = 1; j + 1 < N; j++) {
      for(int k = N >> 1; k > (i ^= k); k >>= 1);
      if(i > j) swap(F[i], F[j]);
    }
    if(rts.size() < N){
      rts.resize(N), rrts.resize(N);
      for(int i = 1; i < N; i <<= 1) {
        if(rts[i].size()) continue;
        rts[i].resize(i), rrts[i].resize(i);
        for(int k = 0; k < i; k++) {
          rts[i][k] = polar(1.0, PI / i * k);
          rrts[i][k] = polar(1.0, -PI / i * k);
        }
      }
    }
    C s, t;
    for(int i = 1; i < N; i <<= 1) {
      for(int j = 0; j < N; j += i * 2) {
        for(int k = 0; k < i; k++) {
          s = F[j + k];
          t = C(F[j + k + i].X * r[i][k].X - F[j + k + i].Y * r[i][k].Y,
                F[j + k + i].X * r[i][k].Y + F[j + k + i].Y * r[i][k].X);
          F[j + k] = s + t, F[j + k + i] = s - t;
        }
      }
    }
    if(rev) for(int i = 0; i < N; i++) F[i] /= N;
  }
  vector<ll> Multiply(const vector< int > &A, const vector< int > &B) {
    int sz = 1;
    while(sz < A.size() + B.size() - 1) sz <<= 1;
    vector< C > F(sz), G(sz);
    for(int i = 0; i < A.size(); i++) F[i] = A[i];
    for(int i = 0; i < B.size(); i++) G[i] = B[i];
    DFT(F, false); DFT(G, false);
    for(int i = 0; i < sz; i++) F[i] *= G[i];
    DFT(F, true);
    vector<ll> res(A.size() + B.size() - 1);
    for(int i = 0; i < A.size() + B.size() - 1; i++) res[i] = (ll)(F[i].real() + 0.5);
    return res;
  }
};

ll extgcd(ll a,ll b,ll& x,ll& y){
  ll d=a;
  if(b!=0){
    d=extgcd(b,a%b,y,x);
    y-=(a/b)*x;
  }else{
    x=1;y=0;
  }
  return d;
}

ll mod_inverse(ll a,ll m){
  ll x,y;
  extgcd(a,m,x,y);
  return (m+x%m)%m;
}

ll fact[MAX_P];
ll mod_fact(ll n,ll p,ll& e){ // O(logn)? <- preparation O(p)?
  e=0;
  if(n==0)return 1;
  ll res=mod_fact(n/p,p,e);
  e+=n/p;
  if(n/p%2!=0)return res*(p-fact[n%p])%p;
  else return res*fact[n%p]%p;
}

ll mod_comb(ll n,ll k,ll p){
  if(n<0||k<0||n<k)return 0;
  ll e1,e2,e3;
  ll a1=mod_fact(n,p,e1), a2=mod_fact(k,p,e2), a3=mod_fact(n-k,p,e3);
  if(e1>e2+e3)return 0;
  return a1*mod_inverse(a2*a3%p,p)%p;
}

//// calc starling2 n個のものをk個に分ける場合の数（グループを区別しない）
ll starling2(ll n,ll k){
  ll res=0;
  for(ll i=1;i<=k;i++){
    ll a=comb(k,i)*mod_pow(i,n)%mod;
    if((k-i)&1LL)res+=mod-a;
    else res+=a;
    res%=mod;
  }
  return res*finv[k]%mod;
}

//// make tabel starling2
ll S[3001][3001];
void make_table(){
  S[0][0]=1;
  for(int i=1;i<=3000;i++){
    for(int j=1;j<=i;j++){
      S[i][j]=(S[i-1][j-1]+j*S[i-1][j])%mod;
    }
  }
}

struct UnionFind{
  vector<int> v;
  UnionFind(int n) : v(n, -1) {}
  void init(){ for(int i = 0;i < (int)v.size();i++)v[i]=-1; }
  int find(int x) { return v[x] < 0 ? x : v[x] = find(v[x]); }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (-v[x] < -v[y]) swap(x, y);
    v[x] += v[y]; v[y] = x;
    return true;
  }
  bool root(int x) { return v[x] < 0; }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return -v[find(x)]; }
};

struct BIT{
  int n;
  vector<ll> bit;
  BIT(int size):n(size),bit(size+1,0){}
  ll sum(int i){
    ll s=0;
    while(i>0){
      s+=bit[i];
      i-=i&-i;
    }
    return s;
  }
  void add(int i,ll v){
    if(i==0)return ;
    while(i<=n){
      bit[i]+=v;
      i+=i&-i;
    }
  }
  ll lower_bound(ll w){
    if(w<=0)return 0;
    ll x=0,r=1;
    while(r<n)r<<=1;
    for(ll k=r;k>0;k>>=1){
      if(x+k<=n&&bit[x+k]<w){
        w-=bit[x+k];
        x+=k;
      }
    }
    return x+1;
  }
};

struct BIT2d{
  ll bit[MAX_N][MAX_N];
  void init(){
    memset(bit,0,sizeof(bit));
  }
  ll sum(int x, int y){
    ll s=0;
    for(int i=y;i>0;i-=i&-i){
      for(int j=x;j>0;j-=j&-j){
        s+=bit[i][j];
      }
    }
    return s;
  }
  void add(int x, int y,ll v){
    for(int i=y;i<=MAX_N;i+=i&-i){
      for(int j=x;j<=MAX_N;j+=j&-j){
        bit[i][j]+=v;
      }
    }
  }
};

struct LazySegTree {
  vector<ll> seg, lazy;
  int size;
  LazySegTree() {}
  LazySegTree(int n) {
    init(n);
  }
  void init(int n) {
    size = 1;
    while (size < n) size *= 2;
    seg.resize(size * 2);
    lazy.resize(size * 2);
    for(int i = 0; i < size*2; i++)seg[i]=-INF;
  }
  void update(int k,ll v){
    k += size-1;
    seg[k] = v;
    while(k > 0){
      k = (k - 1)/2;
      seg[k] = max(seg[k * 2 + 1], seg[k * 2 + 2]);
    }
  }
  void push(int k, int l, int r) {
    seg[k] += lazy[k];
    if (r - l > 1) {
      lazy[k * 2 + 1] += lazy[k];
      lazy[k * 2 + 2] += lazy[k];
    }
    lazy[k] = 0;
  }
  void add(int a, int b, ll v, int k, int l, int r) {
    push(k, l, r);
    if (r <= a || b <= l) return;
    if (a <= l && r <= b) {
      lazy[k] += v;
      push(k, l, r);
    } else {
      add(a, b, v, k * 2 + 1, l, (l + r) / 2);
      add(a, b, v, k * 2 + 2, (l + r) / 2, r);
      seg[k] = max(seg[k * 2 + 1], seg[k * 2 + 2]);
    }
  }
  void add(int a, int b, ll v) {
    add(a, b, v, 0, 0, size);
  }
  ll query(int a, int b, int k, int l, int r) {
    push(k, l, r);
    if (r <= a || b <= l) return -INF*100; // caution
    if (a <= l && r <= b) return seg[k];
    ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return max(vl,vr);
  }
  ll query(int a, int b) {
    return query(a, b, 0, 0, size);
  }
};

// ValueSegmentTree on Tree
int rt[100010];
int l[2000010],r[2000010];
int val[2000010];
int insert(int x,int v,int vl,int vr){
  int y=++idx;
  val[y]=val[x]+1;
  if(vl+1==vr)return y;
  int mid=(vl+vr)/2;
  if(v<mid){
    l[y]=insert(l[x],v,vl,mid);
    r[y]=r[x];
  }else{
    l[y]=l[x];
    r[y]=insert(r[x],v,mid,vr);
  }
  return y;
}
int kth(int u,int v,int lc,int k){
  int vl=0,vr=100001;
  while(vr-vl>1){
    int cnt=val[l[v]]+val[l[u]]-val[l[lc]]*2;
    int mid=(vl+vr)/2;
    if(k<=cnt){
      v=l[v]; u=l[u]; lc=l[lc];
      vr=mid;
    }else{
      v=r[v]; u=r[u]; lc=r[lc];
      vl=mid; k-=cnt;
    }
  }
  return vl;
}
void dfs(int v,int pre,int d){
  par[0][v]=pre; dep[v]=d;
  for(P e : g[v]){
    if(e.fi==pre){
      rt[v]=insert(rt[pre],e.se,0,100001);
      continue;
    }
    dfs(e.fi,v,d+1);
  }
}

//// centroid devide and conquer
vector<int> g[100010];
int sz[100010];
bool dame[100010];
vector<int> cent;

void compute_subtree_size(int v,int pre){
  sz[v]=1;
  for(int nv : g[v]){
    if(nv==pre||dame[nv])continue;
    compute_subtree_size(nv,v);
    sz[v]+=sz[nv];
  }
}
void search_centroid(int v,int pre,int tot){
  bool is_cent=true;
  for(int nv : g[v]){
    if(nv==pre||dame[nv])continue;
    search_centroid(nv,v,tot);
    if(sz[nv]>tot/2)is_cent=false;
  }
  if(tot-sz[v]>tot/2)is_cent=false;
  if(is_cent)cent.push_back(v);
}
void solve_subprob(ll v){ // main
  compute_subtree_size(v,-1);
  cent.clear();
  search_centroid(v,-1,sz[v]);
  int c=cent[0];
  dame[c]=true;

  // devide
  for(int nv : g[c]){
    if(dame[nv])continue;
    solve_subprob(nv);
  }

  dame[c]=false;

  // conquer
}

// 典型漸化式
// 重複組み合わせ：dp[i+1][j]=dp[i+1][j-1]+dp[i][j]-dp[i][j-a[i]-1]
// 分割数：dp[i+1][j]=dp[i+1][j-i]+dp[i][j]

/* Convex Hull Trick
this can get the minimum(maximum) value of lines(f_i(x)=ax+b)
when query add and get is monotony(x1<=x2<=x3... or x1>=x2>=x3>=...
and a1<=a2<=a3... or a1>=a2>=a3...), you can use (isMonoticX=true) (O(N+Q))
when add query is monotony, you use (isMonoticX=false) (O((N+Q)logN) */
struct CHTrick{
	deque<P> lines;
	bool isMonoticX=false;
	CHTrick(bool flag=false){
		isMonoticX=flag;
	}
	// check whether line l2 is useless
	// maybe overflow
	bool check(P l1,P l2,P l3){
		return (long double)(l3.second-l2.second)*(l2.first-l1.first)>=(long double)(l2.second-l1.second)*(l3.first-l2.first);
	}
	// add line(y=ax+b)
	void add(ll a,ll b){
		if(lines.size()>0 && lines.back().first==a){
			// if you find minimum val, replace max to min
			b=max(b,lines.back().second);
			lines.pop_back();
		}
		P line(a,b);
		while(lines.size()>=2 && check(*(lines.end()-2),lines.back(),line)){
			lines.pop_back();
		}
		lines.push_back(line);
	}
	// return the value of f_i(x)
	ll f(int i,ll x){
		return lines[i].first*x+lines[i].second;
	}
	ll f(P line,ll x){
		return line.first*x+line.second;
	}
	// minimum -> (lv>=rv), maximum ->(lv<=rv)
	bool comp(ll lv,ll rv){
		return lv>=rv;
	}
	// return the minimum(maximum) values among lines
	ll get(ll x){
		if(isMonoticX){
			while(lines.size()>=2 && comp(f(0,x),f(1,x))){
				lines.pop_front();
			}
			return f(0,x);
		}else{
			int low=-1,high=lines.size()-1;
			while(high-low>1){
				int mid=(high+low)/2;
				if(comp(f(mid,x),f(mid+1,x)))low=mid;
				else high=mid;
			}
			return f(high,x);
		}
	}
};

/* Radix Heap(最小値を返すバージョン)
最大値を取りたい場合は(INT_MAX-値)を代入すれば復元できます
This heap can be used for ""Nonnegative""integer""
This make dijkstra more faster than usual heap for mincostflow
push O(1)
pop O(log D) (D = maximum of the value) */
struct RadixHeap{
	vector<P> v[33];
	int sz;
	int last;
	RadixHeap(){
		last=0;
		sz=0;
	}
	int bsr(int x){
		if(x==0)return -1;
		return 31-__builtin_clz(x);
	}
	// P(距離(優先度), 頂点)を代入する
	void push(P p){
		assert(last<=p.first);
		sz++;
		v[bsr(p.first^last)+1].push_back(p);
	}
	P top(){
		return pop(false);
	}
	P pop(bool flag=true){
		assert(sz);
		if(!v[0].size()){
			int i=1;
			while(!v[i].size())i++;
			last=min_element(v[i].begin(),v[i].end())->first;
			for(int j=0;j<v[i].size();j++){
				v[bsr(v[i][j].first^last)+1].push_back(v[i][j]);
			}
			v[i].clear();
		}
		P best=v[0].back();
		if(flag){
			v[0].pop_back();
			sz--;
		}
		return best;
	}
};

//sparse table(更新がない時に超高速に動作するRMQ, 最大値を返す版)
//最小値を求めたい場合はmaxをminに書き直して動作させる
struct sparsetable{
	static const int N=10;
	int log_table[1<<N];
	int table[N+1][1<<(N+1)];
	sparsetable(){}
	//座標xに値vを挿入する(maxを取っているので負の値が入らないので注意)
	void update(int x,int v){
		table[0][x]=max(table[0][x],v);
	}
	// updateが終わったら呼び出す
	void construct(){
		int v=0;
		log_table[1]=0;
		log_table[2]=0;
		for(int i=3;i<(1<<N);i++){
			if((1<<v)*2<i){
				v++;
			}
			log_table[i]=v;
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<(1<<N);j++){
				table[i+1][j]=max(table[i][j],table[i][j+(1<<i)]);
			}
		}
	}
	// [l,r)に対して答えを返す
	int query(int l,int r){
		int len=log_table[r-l];
		return max(table[len][l],table[len][r-(1<<len)]);
	}
};

//treap(imulanさんの実装に下記の変更を加えたもの)
// 1. 乱数をmt()ではなxorを使って実装
unsigned int y=11451419;
int rand_int(int l=0,int r=11451419){
	y=y^(y<<13);
	y=y^(y>>17);
	y=y^(y<<5);
	return y%(r-l+1)+l;
}

template<class T>
struct treap{
	struct node_t{
		T val; // 値
		node_t *lch, *rch;
		int pri; // 優先度
		int cnt; // 部分木のサイズ
		T sum; // 部分木の値の和
		node_t(T v, int p):val(v), pri(p), cnt(1), sum(v){
			lch = rch = NULL;
		}
	};
	node_t *root;
	treap():root(NULL){}
	int count(node_t *t){ return t ? t->cnt : 0; }
	T sum(node_t *t){ return t ? t->sum : 0; }
	node_t *update(node_t *t){
    	t->cnt = count(t->lch) + count(t->rch) + 1;
    	t->sum = sum(t->lch) + sum(t->rch) + t->val;
    	return t;
    }
    //木rを木lの後に追加する
    node_t *merge(node_t *l, node_t *r){
    	if(!l || !r) return l?l:r;
        if(l->pri > r->pri){ // 左の部分木の根のほうが優先度が高い
        	l->rch = merge(l->rch, r);
        	return update(l);
        }else{
        	r->lch = merge(l, r->lch);
        	return update(r);
        }
    }
    pair<node_t*, node_t*> split(node_t *t, int k){ // [0,k), [k,n)に分割
    	if(!t) return {NULL,NULL};
    	if(k <= count(t->lch)){
    		pair<node_t*,node_t*> s = split(t->lch,k);
    		t->lch = s.second;
    		return {s.first, update(t)};
    	}else{
    		pair<node_t*,node_t*> s = split(t->rch, k-count(t->lch)-1);
    		t->rch = s.first;
    		return {update(t), s.second};
    	}
    }
    node_t *insert(node_t *t, int k, T val, int pri){
    	pair<node_t*,node_t*> s = split(t,k);
    	t = merge(s.first, new node_t(val,pri));
    	t = merge(t, s.second);
    	return update(t);
    }
   	// eraseによってsiz=0になるとバグって使えなくなるので注意
    node_t *erase(node_t *t, int k){
    	pair<node_t*,node_t*> s2 = split(t,k+1);
    	pair<node_t*,node_t*> s1 = split(s2.first, k);
    	t = merge(s1.first, s2.second);
    	return update(t);
    }
    node_t *find(node_t *t, int k){
    	int c = count(t->lch);
    	if(k < c) return find(t->lch,k);
    	if(k == c) return t;
    	return find(t->rch, k-c-1);
    }
    void insert(int k, T val){ root = insert(root, k, val, rand_int()); }
    void erase(int k){ root = erase(root, k); }
    node_t *find(int k){ return find(root,k); }

    // circular shift(右端の値が左端に来て、それ以外が右に1つずつシフト)
    void shift(int l,int r){
    	if(r-l==1)return;
    	assert(l<r);
    	auto sr=split(root,r);
    	auto sl=split(sr.first,l);
    	auto lr=split(sl.second,r-l-1);
    	root=merge(merge(sl.first,merge(lr.second,lr.first)),sr.second);
    }

    //[l,r)
    T min(int l,int r){
    	assert(l<r);
    	auto sr=split(root,r);
    	auto sl=split(sr.first,l);
    	auto lr=sl.second;
    	T ret=min(lr);
    	root=merge(merge(sl.first,lr),sr.second);
    	return ret;
    }
};

//lcatree
struct lcatree{
	static const int MAX_LOG=20;
	static const int MAX=40005;
	vector<int> G[MAX];
	int root;
	int parent[MAX_LOG][MAX];
	int depth[MAX];
	void dfs(int v,int p,int d){
		parent[0][v]=p;
		depth[v]=d;
		for(int i=0;i<G[v].size();i++){
			if(G[v][i]!=p)dfs(G[v][i],v,d+1);
		}
	}
	void init(int V){
		dfs(root,-1,0);
		for(int k=0;k+1<MAX_LOG;k++){
			for(int v=0;v<V;v++){
				if(parent[k][v]<0)parent[k+1][v]=-1;
				else parent[k+1][v]=parent[k][parent[k][v]];
			}
		}
	}
	int lca(int u,int v){
		if(depth[u]>depth[v])swap(u,v);
		for(int k=0;k<MAX_LOG;k++){
			if((depth[v]-depth[u])>>k & 1){
				v=parent[k][v];
			}
		}
		if(u==v)return u;
		for(int k=MAX_LOG-1;k>=0;k--){
			if(parent[k][u]!=parent[k][v]){
				u=parent[k][u];
				v=parent[k][v];
			}
		}
		return parent[0][u];
	}
};

//負の辺があっても動作する木の直径取得プログラム
struct edge{
	int t;
	ll c;
	edge(){}
	edge(int tt,ll cc){
		t=tt;
		c=cc;
	}
};

class diameter{
public:
	static const int MAX=300005;
	vector<edge> G[MAX];
	int ans=0;
	P ans_v;

	P dfs(int v,int p){
		P rec=P(0LL,v);
		for(int i=0;i<G[v].size();i++){
			edge e=G[v][i];
			if(e.t==p)continue;
			P p1=dfs(e.t,v);
			p1.first+=e.c;
			P val=max(P(0LL,v),p1);
			if(val.first+rec.first>ans){
				ans=val.first+rec.first;
				ans_v=P(val.second,rec.second);
			}
			rec=max(rec,val);
		}
		return rec;
	}

	int get(){
		ans=0;
		dfs(0,-1);
		return ans;
	}
};

/* find directed-eulerPath(and semi-eulerpath)*/

vector<int> G[200006];
vector<int> rG[200006];
vector<int> vs;
int node;

void dfs(int v,int p){
	while(G[v].size()){
		int nv=G[v].back();
		G[v].pop_back();
		dfs(nv,v);
	}
	vs.push_back(v);
}
bool eulerPath(){
	int cf=0,ct=0,ng=0;
	for(int i=0;i<node;i++){
		int va=G[i].size();
		int vb=rG[i].size();
		if((va-vb)==1)cf++;
		else if((va-vb)==-1)ct++;
		else if((va-vb)!=0)ng++;
	}
	if(ng>0 || cf>=2 || ct>=2 || cf!=ct)return false;
	if(cf==0)dfs(0,-1);
	else{
		for(int i=0;i<node;i++){
			int va=G[i].size();
			int vb=rG[i].size();
			if((va-vb)==1)dfs(i,-1);
		}
	}
	reverse(vs.begin(),vs.end());
	if(vs.size()!=n+1)return false;
	return true;
}

class graph_bridge{
public:
	static const int MAX=3005;
	vector<int> G[MAX];
	bool visited[MAX];
	int prenum[MAX],parent[MAX],lowest[MAX],timer;
	set<P> bridge;
	int cmp[MAX];
	void dfs(int v,int prev){
		prenum[v]=lowest[v]=timer;
		timer++;
		visited[v]=true;
		int next;
		for(int i=0;i<G[v].size();i++){
			next=G[v][i];
			if(!visited[next]){
				parent[next]=v;
				dfs(next,v);
				lowest[v]=min(lowest[v],lowest[next]);
				if(prenum[v]<lowest[G[v][i]])bridge.insert(P(min(v,G[v][i]),max(v,G[v][i])));
			}else if(next!=prev){
				lowest[v]=min(lowest[v],prenum[next]);
			}
		}
	}
	void dfs2(int v,int k){
		cmp[v]=k;
		for(int i=0;i<G[v].size();i++){
			int nv=G[v][i];
			if(cmp[nv]>=0)continue;
			if(bridge.find(P(min(v,nv),max(v,nv)))==bridge.end()){
				dfs2(nv,k);
			}
		}
	}
	set<int> art_points(int N){
		for(int i=0;i<N;i++){
			visited[i]=false;
		}
		timer=1;
		bridge.clear();
		dfs(0,-1);

		set<int> ap;
		int np=0;
		for(int i=1;i<N;i++){
			int p=parent[i];
			if(p==0)np++;
			else if(prenum[p]<lowest[i])ap.insert(p);
		}
		if(np>1)ap.insert(0);
		return ap;
	}
	int construct_TwoEdgeConnectedComponent(int N){
		for(int i=0;i<N;i++){
			visited[i]=false;
		}
		timer=1;
		bridge.clear();
		for(int i=0;i<N;i++){
			if(!visited[i]){
				dfs(i,-1);
			}
		}
		memset(cmp,-1,sizeof(cmp));
		int k=0;
		for(int i=0;i<N;i++){
			if(cmp[i]==-1){
				dfs2(i,k);
				k++;
			}
		}
		return k;
	}
};

//hungarian (O(n^3))
//There are people 1 ... n and work 1 ... n.
//Assume that the profit when assigning person i to work j is a[i][j].
// At this time, this program maximizes the profit obtained
// by putting all people in different work

typedef vector<int> vec;
typedef vector<vec> mat;

int hungarian(const mat &a){
	int n=a.size(),p,q;
	vector<int> fx(n,INF),fy(n,0);
	vector<int> x(n,-1),y(n,-1);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fx[i]=max(fx[i],a[i][j]);
		}
	}
	for(int i=0;i<n;){
		vector<int> t(n,-1),s(n+1,i);
		for(p=q=0;p<=q && x[i]<0;p++){
			for(int k=s[p],j=0;j<n && x[i]<0;j++){
				if(fx[k]+fy[j]==a[k][j] && t[j]<0){
					s[++q]=y[j];
					t[j]=k;
					if(s[q]<0){
						for(p=j;p>=0;j=p){
							y[j]=k=t[j];
							p=x[k];
							x[k]=j;
						}
					}
				}
			}
		}
		if(x[i]<0){
			int d=INF;
			for(int k=0;k<=q;k++){
				for(int j=0;j<n;j++){
					if(t[j]<0){
						d=min(d,fx[s[k]]+fy[j]-a[s[k]][j]);
					}
				}
			}
			for(int j=0;j<n;j++){
				fy[j]+=(t[j]<0?0:d);
			}
			for(int k=0;k<=q;k++){
				fx[s[k]]-=d;
			}
		}else{
			i++;
		}
	}
	int res=0;
	for(int i=0;i<n;i++){
		res+=a[i][x[i]];
	}
	return res;
}

/*
木の上に対するクエリの解き方

〇〇上の和等→オイラーツアー+セグメント木
〇〇上の要素数、最頻値等→Mo algorithm(参考: https://codeforces.com/blog/entry/43230)

番号付け: dfsの行きかけ順に各ノードにid付け->(来た時)st[v], (出た時)en[v]とする

1. ある頂点vの部分木に対するクエリ

1.1. オイラーツアー+セグメント木
照会クエリ→[st[v],en[v]]
更新クエリ→st[v]に適用

1.2. Mo algorithmの場合
照会クエリ→[st[v],en[v]]
頂点の値をどこに入れるか→st[v]に入れる

2. あるパス(u,v)に対するクエリ(st[u]<=st[v])
parent=lca(u,v)と置く

2.1. オイラーツアー+セグメント木
照会クエリ→[0,st[u]]+[0,st[v]]-2*[0,st[parent]]
更新クエリ→加算をst[v], 減算(打消し)をen[v]に適用

2.2. Mo algorithmの場合
頂点の値をどこに入れるか→st[v]とen[v]に入れる (mod2を取る, 区間がst[v]とen[v]を含むなら打ち消すように区間の左端と右端の更新をする)

・Case 1 parent=uの場合
照会クエリ: [st[u], st[v]]
・Case 2 parent!=uの場合
照会クエリ: [en[u],st[v]]+[st[parent],st[parent]]
*/


/* koubun kaiseki shisoku enzan
<expr> :: = <term>+<term> |  <term>-<term>
<term>:: = <fact>*<fact> | <fact>/<fact>
<fact>::= <number> | (<expr>)
<digit> :: = 0|1|2|...
*/
typedef string::const_iterator State;
int expression(State &begin);
int number(State &begin){
	int ret=0;
	while(isdigit(*begin)){
		ret*=10;
		ret+=*begin-'0';
		begin++;
	}
	return ret;
}
int factor(State &begin){
	if(*begin=='('){
		begin++;
		int ret=expression(begin);
		begin++;
		return ret;
	}else{
		return number(begin);
	}
}
int term(State &begin){
	int ret=factor(begin);
	while(1){
		if(*begin=='*'){
			begin++;
			ret*=factor(begin);
		}else if(*begin=='/'){
			begin--;
			ret/=factor(begin);
		}else{
			break;
		}
	}
	return ret;
}
int expression(State &begin){
	int ret=term(begin);
	while(1){
		if(*begin=='+'){
			begin++;
			ret+=term(begin);
		}else if(*begin=='-'){
			begin++;
			ret-=term(begin);
		}else{
			break;
		}
	}
	return ret;
}

//数式を処理するセグメント木(加算, 掛け算のみ), 値の変更には対応していない
//単位元が無いライブラリなので使用時注意
// verified by AOJ1630
const int PLUS=-1;
const int MUL=-2;
class expr{
public:
	bool f=true;
	ll l=0,m=0,r=0;
	expr(){}
	expr(bool ff,ll lv,ll mv,ll rv){
		f=ff;
		l=lv;
		m=mv;
		r=rv;
	}
};

expr merge(expr el,expr er,int op){
	expr res;
	if(op==PLUS){
		res.f=false;
		if(el.f && er.f){
			res.l=el.m;
			res.r=er.m;
			res.m=0;
		}else if(el.f){
			res.l=el.m;
			res.m=min(INF,er.l+er.m);
			res.r=er.r;
		}else if(er.f){
			res.l=el.l;
			res.m=min(INF,el.m+el.r);
			res.r=er.m;
		}else{
			res.l=el.l;
			// maybe overflow a+b+c+d
			res.m=min(INF,el.m+el.r+er.l+er.m);
			res.r=er.r;
		}
	}else if(op==MUL){
		res.f=el.f&&er.f;
		if(el.f && er.f){
			res.l=0;
			res.m=min(INF,el.m*er.m);
			res.r=0;
		}else if(el.f){
			res.l=min(INF,el.m*er.l);
			res.m=er.m;
			res.r=er.r;
		}else if(er.f){
			res.l=el.l;
			res.m=el.m;
			res.r=min(INF,el.r*er.m);
		}else{
			res.l=el.l;
			//maybe overflow a+b*c+d
			res.m=min(INF,el.m+el.r*er.l+er.m);
			res.r=er.r;
		}
	}else{
		res=el;
	}
	return res;
}

struct segtree{
	int N;
	expr ex[1<<21];
	int op[1<<21];
	segtree(){}
	void memsetN(int n){
		N=1;
		while(N<n){
			N*=2;
		}

		for(int i=0;i<N*2;i++){
			ex[i]=expr(true,0,1,0);
			op[i]=MUL;
		}
	}
	void init(vector<ll> &v,int k,int l,int r){
		if((r-l)==1){
			if(l*2<v.size())ex[k]=expr(true,0,v[l*2],0);
			return;
		}
		int mid=(l+r)/2;
		init(v,k*2+1,l,mid);
		init(v,k*2+2,mid,r);
		if(2*mid-1<v.size())op[k]=v[2*mid-1];
		ex[k]=merge(ex[k*2+1],ex[k*2+2],op[k]);
	}
	expr query(int a,int b,int k,int l,int r){
		if(b<=l || r<=a)return expr(true,0,1,0);
		if(a<=l && r<=b)return ex[k];
		int mid=(l+r)/2;
		expr el=query(a,b,k*2+1,l,mid);
		expr er=query(a,b,k*2+2,mid,r);
		if(mid<=a)return er;
		if(b<=mid)return el;
		return merge(el,er,op[k]);
	}
	ll getval(int l,int r){
		expr res=query(l,r,0,0,N);
		return min(INF,res.l+res.m+res.r);
	}
};
segtree seg;
ll n;
string str;
int pos=0;
ll ans=0;
// v {num, op, num, op, ...}
ll solve2(vector<ll> v){
	int m=v.size()/2+1;
	seg.memsetN(m);
	seg.init(v,0,0,seg.N);
	int r=0;
	int r2=0;
	for(int i=0;i<m;i++){
		ll tmp=0;
		r=max(i,r);
		r2=max(i,r2);
		while(r<m && (tmp=seg.getval(i,r+1))<=n){
			r++;
		}
		while(r2<m && (tmp=seg.getval(i,r2+1))<n){
			r2++;
		}
		ans+=(r-r2);
	}
	return seg.getval(0,m);
}

ll solve(){
	vector<ll> v;
	while(pos!=(int)str.size()){
		char c=str[pos];
		if(c=='('){
			pos++;
			v.push_back(solve());
		}
		if(c==')'){
			pos++;
			break;
		}
		if(isdigit(c)){
			pos++;
			v.push_back(c-'0');
		}
		if(c=='*'){
			pos++;
			v.push_back(MUL);
		}
		if(c=='+'){
			pos++;
			v.push_back(PLUS);
		}
	}
	return solve2(v);
}

int main(void){
	while(1){
		scanf("%lld",&n);
		if(n==0LL)break;
		cin >> str;
		ans=0;
		pos=0;
		solve();
		printf("%lld\n",ans);
	}
	return 0;
}




















































































/* geometry */
// !!! 整数座標に書き換える時、EPS周りの=の有無に注意 !!!

/* 基本要素 */
typedef complex<double> Point;
typedef pair<Point, Point> Line;
typedef vector<Point> VP;
const double PI = acos(-1);
const double EPS = 1e-9; // 許容誤差^2
const double INF = 1e9;
#define X real()
#define Y imag()
#define LE(n,m) ((n) - (m) < EPS)
#define GE(n,m) (EPS > (m) - (n))
#define EQ(n,m) (abs((n)-(m)) < EPS)

// 内積　dot(a,b) = |a||b|cosθ
double dot(Point a, Point b) {
  return a.X*b.X + a.Y*b.Y;
}

// 外積　cross(a,b) = |a||b|sinθ
double cross(Point a, Point b) {
  return a.X*b.Y - a.Y*b.X;
}

// 点の進行方向
// !!! 誤差に注意 !!! (掛け算したものとかなり小さいものを比べているので)
int ccw(Point a, Point b, Point c) {
  b -= a;  c -= a;
  if (cross(b,c) >  EPS) return +1;  // counter clockwise
  if (cross(b,c) < -EPS) return -1;  // clockwise
  if (dot(b,c)   < -EPS) return +2;  // c--a--b on line
  if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
  return 0;                          // a--c--b on line or a==c or b==c
}

/*
  交差判定　直線・線分は縮退してはならない。
  接する場合は交差するとみなす。
  縮退している = 2つのものが区別付かない状態(?)
  isec = intersect
  L = Line
  P = Point
  S = Segment
*/

// 直線と点
bool isecLP(Point a1, Point a2, Point b) {
  return abs(ccw(a1, a2, b)) != 1;
  // return EQ(cross(a2-a1, b-a1), 0); と等価
}

// 直線と直線
bool isecLL(Point a1, Point a2, Point b1, Point b2) {
  return !isecLP(a2-a1, b2-b1, 0) || isecLP(a1, b1, b2);
}

// 直線と線分
bool isecLS(Point a1, Point a2, Point b1, Point b2) {
  return cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS;
}

// 線分と線分
bool isecSS(Point a1, Point a2, Point b1, Point b2) {
  return ccw(a1, a2, b1)*ccw(a1, a2, b2) <= 0 &&
  ccw(b1, b2, a1)*ccw(b1, b2, a2) <= 0;
}

// 線分と点
bool isecSP(Point a1, Point a2, Point b) {
  return !ccw(a1, a2, b);
}

/* 距離　各直線・線分は縮退してはならない */

// 点pの直線aへの射影点を返す
Point proj(Point a1, Point a2, Point p) {
  return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}

// 点pの直線aへの反射点を返す
Point reflection(Point a1, Point a2, Point p) {
  return 2.0*proj(a1, a2, p) - p;
}

//点aと点bの距離は abs(a-b)
//#define distPP(p1,p2) abs(p1-p2)

double distLP(Point a1, Point a2, Point p) {
  return abs(proj(a1, a2, p) - p);
}

double distLL(Point a1, Point a2, Point b1, Point b2) {
  return isecLL(a1, a2, b1, b2) ? 0 : distLP(a1, a2, b1);
}

double distLS(Point a1, Point a2, Point b1, Point b2) {
  return isecLS(a1, a2, b1, b2) ? 0 : min(distLP(a1, a2, b1), distLP(a1, a2, b2));
}

double distSP(Point a1, Point a2, Point p) {
  Point r = proj(a1, a2, p);
  if (isecSP(a1, a2, r)) return abs(r-p);
  //= !ccw(a1, a2, r)
  return min(abs(a1-p), abs(a2-p));
}

double distSS(Point a1, Point a2, Point b1, Point b2) {
  if (isecSS(a1, a2, b1, b2)) return 0;
  return min(min(distSP(a1, a2, b1), distSP(a1, a2, b2)),
   min(distSP(b1, b2, a1), distSP(b1, b2, a2)));
}

// 2直線の交点
Point crosspointLL(Point a1, Point a2, Point b1, Point b2) {
  double d1 = cross(b2-b1, b1-a1);
  double d2 = cross(b2-b1, a2-a1);
  if (EQ(d1, 0) && EQ(d2, 0)) return a1;  // same line
  assert(!EQ(d2, 0)); // 交点がない
  return a1 + d1/d2 * (a2-a1);
}

/* 円 */

double distLC(Point a1, Point a2, Point c, double r) {
  return max(distLP(a1, a2, c) - r, 0.0);
}

double distSC(Point a1, Point a2, Point c, double r) {
  double dSqr1 = norm(c-a1), dSqr2 = norm(c-a2);
  if (dSqr1 < r*r ^ dSqr2 < r*r) return 0;  // 円が線分を包含するとき距離0ならここをORに変える
  if (dSqr1 < r*r & dSqr2 < r*r) return r - sqrt(max(dSqr1, dSqr2));
  return max(distSP(a1, a2, c) - r, 0.0);
}

VP crosspointLC(Point a1, Point a2, Point c, double r) {
  VP ps;
  Point ft = proj(a1, a2, c);
  if(!GE(r*r,norm(ft-c))) return ps;
  Point dir = sqrt(max(r*r - norm(ft-c), 0.0)) / abs(a2-a1) * (a2-a1);
  ps.push_back(ft + dir);
  if (!EQ(r*r, norm(ft-c))) ps.push_back(ft - dir);
  return ps;
}

double distCC(Point a, double ar, Point b, double br) {
  double d = abs(a-b);
  return GE(d, abs(ar-br)) ? max(d-ar-br, 0.0) : abs(ar-br) - d;
}

// 2円の交点
VP crosspointCC(Point a, double ar, Point b, double br) {
  VP ps;
  Point ab = b-a;
  double d = abs(ab);
  double crL = (norm(ab) + ar*ar - br*br) / (2*d);
  if (EQ(d, 0) || ar+EPS < abs(crL)) return ps;

  // 円が接する時、こことEPSの設定をうまくしないとsqrt(sub)がnanになるので注意
  double sub = ar*ar - crL*crL;
  if(EQ(sub,0)) sub = 0;

  Point abN = ab * Point(0, sqrt(sub) / d);
  Point cp = a + crL/d * ab;
  ps.push_back(cp + abN);
  if (!EQ(norm(abN), 0)) ps.push_back(cp - abN);
  return ps;
}

// 点pから円aへの接線の接点
VP tangentPoints(Point a, double ar, Point p) {
  VP ps;
  double sin = ar / abs(p-a);
  if (!LE(sin, 1)) return ps;  // ここでNaNも弾かれる
  double t = PI/2 - asin(min(sin, 1.0));
  ps.push_back(                 a + (p-a)*polar(sin, t));
  if (!EQ(sin, 1)) ps.push_back(a + (p-a)*polar(sin, -t));
  return ps;
}

// 2円の共通接線。返される各直線に含まれる頂点は円との接点となる
vector<Line> tangentLines(Point a, double ar, Point b, double br) {
  vector<Line> ls;
  double d = abs(b-a);
  rep (i,2) {
    double sin = (ar - (1-i*2)*br) / d;
    if (!LE(sin*sin, 1)) break;
    double cos = sqrt(max(1 - sin*sin, 0.0));
    rep (j,2) {
      Point n = (b-a) * Point(sin, (1-j*2)*cos) / d;
      ls.push_back(Line(a + ar*n, b + (1-i*2)*br*n));
      if (cos < EPS) break;  // 重複する接線を無視（重複していいならこの行不要）
    }
  }
  return ls;
}

// 三角形の外心。点a,b,cは同一線上にあってはならない
Point circumcenter(Point a, Point b, Point c) {
  a = (a-c)*0.5;
  b = (b-c)*0.5;
  return c + crosspointLL(a, a*Point(1,1), b, b*Point(1,1));
}

// 点aと点bを通り、半径がrの円の中心を返す
VP circlesPointsRadius(Point a, Point b, double r) {
  VP cs;
  Point abH = (b-a)*0.5;
  double d = abs(abH);
  if (d == 0 || d > r) return cs;  // 必要なら !LE(d,r) として円1つになる側へ丸める
  double dN = sqrt(r*r - d*d);          // 必要なら max(r*r - d*d, 0) とする
  Point n = abH * Point(0,1) * (dN / d);
  cs.push_back(a + abH + n);
  if (dN > 0) cs.push_back(a + abH - n);
  return cs;
}

// 点aと点bを通り、直線lに接する円の中心
VP circlesPointsTangent(Point a, Point b, Point l1, Point l2) {
  Point n = (l2-l1) * Point(0,1);
  Point m = (b-a) * Point(0,0.5);
  double rC = dot((a+b)*0.5-l1, n);
  double qa = norm(n)*norm(m) - dot(n,m)*dot(n,m);
  double qb = -rC * dot(n,m);
  double qc = norm(n)*norm(m) - rC*rC;
  double qd = qb*qb - qa*qc;  // qa*k^2 + 2*qb*k + qc = 0
  VP cs;
  if (qd < -EPS) return cs;
  if (EQ(qa, 0)) {
    if (!EQ(qb, 0)) cs.push_back((a+b)*0.5 - m * (qc/qb/2));
    return cs;
  }
  double t = -qb/qa;
  cs.push_back(              (a+b)*0.5 + m * (t + sqrt(max(qd, 0.0))/qa));
  if (qd > EPS) cs.push_back((a+b)*0.5 + m * (t - sqrt(max(qd, 0.0))/qa));
  return cs;
}

// 点集合を含む最小の円の中心
Point minEnclosingCircle(const VP& ps) {
  Point c;
  double move = 0.5;
  rep(i,39) {  // 2^(-39-1) \approx 0.9e-12
    rep(t,50) {
      double max = 0;
      int k = 0;
      rep (j, ps.size()) if (max < norm(ps[j]-c)) {
        max = norm(ps[j]-c);
        k = j;
      }
      c += (ps[k]-c) * move;
    }
    move /= 2;
  }
  return c;
}

/* 多角形 */

// 頂点の順序（sortやmax_elementに必要）
namespace std {
  bool operator<(const Point a, const Point b) { return a.X != b.X ? a.X < b.X : a.Y < b.Y; }
}

//多角形PSのi番目の辺
#define ps_edge(PS,i) PS[i],PS[(i+1)%PS.size()]

// 凸包
// 入力1個 -> 空
// 2個以上の全て同じ点 -> 同じもの2つ
VP convexHull(VP ps) {  // 元の点集合がソートされていいならVP&に
  int n = ps.size(), k = 0;
  sort(ps.begin(), ps.end());
  VP ch(2*n);
  for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
    while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;  // 余計な点も含むなら == -1 とする
  for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) // upper-hull
    while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
  ch.resize(k-1);
  return ch;
}

// 凸判定。縮退を認めないならccwの判定部分を != 1 とする
// 反時計か分からなければreverse(ps)も試す（コピー渡し）
bool isCcwConvex(const VP& ps) {
  int n = ps.size();
  rep (i, n) if (ccw(ps[i], ps[(i+1) % n], ps[(i+2) % n]) == -1) return false;
  return true;
}

// 凸多角形の内部判定　O(n)
// 点が領域内部なら1、境界上なら2、外部なら0を返す
int inConvex(Point p, const VP& ps) {
  int n = ps.size();
  int dir = ccw(ps[0], ps[1], p);
  rep (i, n) {
    int ccwc = ccw(ps[i], ps[(i + 1) % n], p);
    if (!ccwc) return 2;  // 線分上に存在
    if (ccwc != dir) return 0;
  }
  return 1;
}

// 凸多角形の内部判定　O(logn)
// 点が領域内部なら1、境界上なら2、外部なら0を返す
int inCcwConvex(const VP& ps, Point p) {
  int n = ps.size();
  Point g = (ps[0] + ps[n / 3] + ps[n*2 / 3]) / 3.0;
  if (g == p) return 1;
  Point gp = p - g;
  int l = 0, r = n;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    Point gl = ps[l] - g;
    Point gm = ps[mid] - g;
    if (cross(gl, gm) > 0) {
      if (cross(gl, gp) >= 0 && cross(gm, gp) <= 0) r = mid;
      else l = mid;
    }
    else {
      if (cross(gl, gp) <= 0 && cross(gm, gp) >= 0) l = mid;
      else r = mid;
    }
  }
  r %= n;
  double cr = cross(ps[l] - p, ps[r] - p);
  return EQ(cr, 0) ? 2 : cr < 0 ? 0 : 1;
}

// 多角形の内部判定
// 点が領域内部なら1、境界上なら2、外部なら0を返す
int inPolygon(const VP& ps, Point p) {
  int n = ps.size();
  bool in = false;
  rep (i, n) {
    Point a = ps[i] - p;
    Point b = ps[(i + 1) % n] - p;
    if (EQ(cross(a,b), 0) && LE(dot(a,b), 0)) return 2;
    if (a.Y > b.Y) swap(a,b);
    if ((a.Y*b.Y < 0 || (a.Y*b.Y < EPS && b.Y > EPS)) && LE(cross(a, b), 0)) in = !in;
  }
  return in;
}

bool inPolygon(Point p,VP& ps){
  int n = ps.size();
  double sumAngle=0;
  rep(i,n){
    double t = arg(ps[(i+1)%n]-p)-arg(ps[i]-p);
    while(t>+PI) t-=2*PI;
    while(t<-PI) t+=2*PI;
    sumAngle += t;
  }
  return (abs(sumAngle) > 0.1);
}

//ベクトル(a1->a2)で凸多角形psを切断したときの
//ベクトルの左側の凸多角形を返す
//参考 http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C

// 凸多角形クリッピング
VP convexCut(const VP& ps, Point a1, Point a2) {
  int n = ps.size();
  VP ret;
  rep(i,n) {
    int ccwc = ccw(a1, a2, ps[i]);
    if (ccwc != -1) ret.push_back(ps[i]);
    int ccwn = ccw(a1, a2, ps[(i + 1) % n]);
    if (ccwc * ccwn == -1) ret.push_back(crosspointLL(a1, a2, ps[i], ps[(i + 1) % n]));
  }
  return ret;
}

// 凸多角形の直径（最遠点対）
pair<int, int> convexDiameter(const VP& ps) {
  int n = ps.size();
  int i = min_element(ps.begin(), ps.end()) - ps.begin();
  int j = max_element(ps.begin(), ps.end()) - ps.begin();
  int maxI, maxJ;
  double maxD = 0;
  rep(_, 2*n) {
    if (maxD < norm(ps[i]-ps[j])) {
      maxD = norm(ps[i]-ps[j]);
      maxI = i;
      maxJ = j;
    }
    if (cross(ps[i]-ps[(i+1) % n], ps[(j+1) % n]-ps[j]) <= 0) j = (j+1) % n;
    else                                                      i = (i+1) % n;
  }
  return make_pair(maxI, maxJ);
}

// aからbへの回転角（中心(0,0)）[-pi,+pi]
double angle(Point a,Point b){
  double t = arg(b)-arg(a);
  while(t>+PI) t-=2*PI;
  while(t<-PI) t+=2*PI;
  return t;
}

// 多角形の符号付面積
double area(const VP& ps) {
  double a = 0;
  rep (i, ps.size()) a += cross(ps[i], ps[(i+1) % ps.size()]);
  return a / 2;
}

double areaCC(Point a, double ar, Point b, double br) {
  double d = abs(a-b);
  if (ar + br - d <= EPS) {
    return 0.0;
  } else if (d - abs(ar-br)<= EPS) {
    double r = min(ar,br);
    return r * r * PI;
  } else {
    double rc = (d*d + ar*ar - br*br) / (2*d);
    double theta = acos(rc / ar);
    double phi = acos((d - rc) / br);
    return ar*ar*theta + br*br*phi - d*ar*sin(theta);
  }
}

/* -------------最近点対の距離------------ */
bool compX(const Point a, const Point b) {
  return (a.X!=b.X ? a.X<b.X : a.Y<b.Y);
}

bool compY(const Point a, const Point b) {
  return (a.Y!=b.Y ? a.Y<b.Y : a.X<b.X);
}

double closestPair(VP& a,int l,int r) {
  if(r-l<=1) return INF;
  int m = (l+r)/2;
  double x = a[m].X;
  double d = min(closestPair(a,l,m),closestPair(a,m,r));
  inplace_merge(a.begin()+l, a.begin()+m, a.begin()+r, compY);
  VP b;
  for(int i=l;i<r;i++){
    if(abs(a[i].X - x)>=d)continue;
    for(int j=b.size()-1;j>=0;j--){
      if((a[i]-b[j]).Y>=d)break;
      d = min(d,abs(a[i]-b[j]));
    }
    b.push_back(a[i]);
  }
  return d;
}

double closestPair(VP ps){
  sort(ps.begin(),ps.end(),compX);
  return closestPair(ps,0,ps.size());
}
/* ------------------------------------- */


// 多角形の幾何学的重心
Point centroid(const VP& ps) {
  int n = ps.size();
  double aSum = 0;
  Point c;
  rep (i, n) {
    double a = cross(ps[i], ps[(i+1) % n]);
    aSum += a;
    c += (ps[i] + ps[(i+1) % n]) * a;
  }
  return 1 / aSum / 3 * c;
}

// ボロノイ領域
VP voronoiCell(Point p, const VP& ps, const VP& outer) {
  VP cl = outer;
  rep (i, ps.size()) {
    if (EQ(norm(ps[i]-p), 0)) continue;
    Point h = (p+ps[i])*0.5;
    cl = convexCut(cl, h, h + (ps[i]-h)*Point(0,1) );
  }
  return cl;
}

/* 幾何グラフ */
struct Edge {
  int from, to;
  double cost;
  Edge(int from_, int to_, double cost_) : from(from_), to(to_), cost(cost_) {}
};
struct Graph {
  int n;
  vector<vector<Edge> > edges;
  Graph(int n_) : n(n_), edges(n_) {}
  void addEdge(Edge e) {
    edges[e.from].push_back(e);
    edges[e.to].push_back(Edge(e.to, e.from, e.cost));
  }
};

// 線分アレンジメント（線分の位置関係からグラフを作成）
Graph segmentArrangement(const vector<Line>& segs, VP& ps) {
  int n = segs.size();
  rep (i, n) {
    ps.push_back(segs[i].first);
    ps.push_back(segs[i].second);
    rep (j, i) {
      if (isecSS(                 segs[i].first, segs[i].second, segs[j].first, segs[j].second))
        ps.push_back(crosspointLL(segs[i].first, segs[i].second, segs[j].first, segs[j].second));
    }
  }
  sort(ps.begin(), ps.end());
  ps.erase(unique(ps.begin(), ps.end()), ps.end());

  int m = ps.size();
  Graph gr(m);
  vector<pair<double, int> > list;
  rep (i, n) {
    list.clear();
    rep (j, m) {
      if (isecSP(segs[i].first, segs[i].second, ps[j]))
        list.push_back(make_pair(norm(segs[i].first-ps[j]), j));
    }
    sort(list.begin(), list.end());
    rep (j, list.size() - 1) {
      int a = list[j  ].second;
      int b = list[j+1].second;
      gr.addEdge(Edge(a, b, abs(ps[a]-ps[b])));
    }
  }
  return gr;
}

// 可視グラフ（点集合から見える位置へ辺を張ったグラフ）
Graph visibilityGraph(const VP& ps, const vector<VP>& objs) {
  int n = ps.size();
  Graph gr(n);
  rep (i,n) rep (j,i) {
    Point a = ps[i], b = ps[j];
    if (!EQ(norm(a-b), 0)) rep (k, objs.size()) {
      const VP& obj = objs[k];
      int inStA = inConvex(a, obj);
      int inStB = inConvex(b, obj);
      if ((inStA ^ inStB) % 2 || inStA * inStB != 1 && inConvex((a+b)*0.5, obj) == 1) goto skip;
      rep (l, obj.size()) {
        Point cur = obj[l];
        Point next = obj[(l + 1) % obj.size()];
        if (isecSS(a, b, cur, next) && !isecSP(cur, next, a) && !isecSP(cur, next, b)) goto skip;
      }
    }
    gr.addEdge( Edge(i, j, abs(a-b)) );
    skip: {}
  }
  return gr;
}

/* その他 */
// 重複する線分を併合する
vector<Line> mergeSegments(vector<Line> segs) {
  int n = segs.size();
  rep (i,n) if (segs[i].second < segs[i].first) swap(segs[i].second, segs[i].first);
  rep (i,n) rep (j,i) {
    Line &l1 = segs[i], &l2 = segs[j];
    if (EQ(cross(l1.second-l1.first, l2.second-l2.first), 0)
      && isecLP(l1.first, l1.second, l2.first)
      && ccw   (l1.first, l1.second, l2.second) != 2
      && ccw   (l2.first, l2.second, l1.second) != 2) {
        segs[j] = Line(min(l1.first, l2.first), max(l1.second, l2.second));
      segs[i--] = segs[--n];
      break;
    }
  }
  segs.resize(n);
  return segs;
}

// 線分ABをm:nに外分する点 (m≠nでないとだめ)
Point ext_div(Point a, Point b, double m, double n){
  return (a*(-n)+b*m)/(m-n);
}

// 点cを中心に、点pをthetaだけ回転
Point rot(Point p, Point c, double theta){
  return (p-c)*polar(1.0,theta) + c;
}

Point inner(Point a, Point b, Point c){
  double A = abs(b-c), B = abs(c-a), C = abs(a-b);
  return (A*a + B*b + C*c)*(1.0/(A+B+C));
}

// この辺にコードを載せるほどでもないが重要な定理とか図とか書いておくとよい気がします
// 余弦定理
// △ABC において、a = BC, b = CA, c = AB としたとき
// a^2 = b^2 + c^2 ? 2bc cos ∠CAB

// ヘロンの公式
// 3辺の長さがa,b,cである三角形の面積T
// T = sqrt{ s(s-a)(s-b)(s-c) }, s = (a+b+c)/2

// ピックの定理
// 多角形の頂点が全て格子点上にあり、内部に穴がないとき
// S=i+b/2-1 (S:多角形の面積, i: 多角形の内部にある格子点の数, b: 辺上の格子点の数)

/* Dinic */
// (行き先,容量,逆辺)
struct edge{ int to,cap,rev; };
const int MAX_V = ; // TODO:initialize
const int F_INF = ; // TODO:initialize
vector<edge> G[MAX_V];
int level[MAX_V]; // sからの距離
int iter[MAX_V]; // どこまで調べ終わったか

void add_edge(int from, int to, int cap){
    G[from].pb({to,cap,(int)G[to].size()});
    G[to].pb({from,0,(int)G[from].size()-1});
}
void dinic_bfs(int s){
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s]=0;
    que.push(s);
    while(!que.empty()){
        int v = que.front();
        que.pop();
        rep(i,G[v].size()){
            edge &e = G[v][i];
            if(e.cap>0 && level[e.to]<0){
                level[e.to] = level[v]+1;
                que.push(e.to);
            }
        }
    }
}
// 増加パスをdfsで探す
int dinic_dfs(int v, int t, int f){
    if(v==t) return f;
    for(int &i=iter[v]; i<(int)G[v].size(); ++i){
        edge &e=G[v][i];
        if(e.cap>0 && level[v]<level[e.to]){
            int d = dinic_dfs(e.to,t,min(f,e.cap));
            if(d>0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}
// sからtへの最大流
int max_flow(int s, int t){
    int flow = 0;
    while(1){
        dinic_bfs(s);
        if(level[t]<0) return flow;
        memset(iter,0,sizeof(iter));
        int f;
        while( (f=dinic_dfs(s,t,F_INF)) > 0 ) flow+=f;
    }
}

// 辺に対して最小流量の制約がある場合
// u->v : 最大流量c, 最小流量b の 辺e について

// 旧source(s),sink(t)
// 新しいsource(S),sink(T)を作成
// 辺の張り方
// u->v : c-b / u->T : b / S->v : b
// S->s : INF / t->T

// 新しいグラフでの流量 maxflow(S,T) = F'
// 元のグラフの最大流量 F = F' - Σb

// 下限制約を満たせるとは限らない場合のチェック方法
// S->s,t->Tを張る前に、 t->s:INFを張ってmax_flow(S,T) = Σbになることを確認する必要がある
/*
"燃やす埋める"
「Xが赤でYが青だとZ円罰金」
X->Yに容量Zの辺を貼る

「Xが赤 or 青だとZ円罰金」
赤だと罰金:X->Tに容量Zの辺
青だと罰金:S->Xに容量Zの辺

「Xが赤でYが赤だとZ円報酬」
新たな頂点Wを考える
強制的にZ円もらう
Wが青だとZ円罰金
Wが赤でXが青だとINF円罰金
Wが赤でYが青だとINF円罰金

「Aが赤でBが赤でCが赤だとZ円報酬」
これも同じ
新たな頂点Wを考える
強制的にZ円もらう
Wが青だとZ円罰金
Wが赤でAが青だとINF円罰金
Wが赤でBが青だとINF円罰金
Wが赤でCが青だとINF円罰金
*/

// マッチングについて
// 孤立点のないグラフに対し、 |最大マッチング| + |最小辺カバー| = |V|
// |最大安定集合| + |最小点カバー| = |V|
// ""二部グラフの場合には"" |最大マッチング| = |最小点カバー|

/* MinCostFlow */
using pi = pair<int,int>;
// (行き先, 容量, コスト, 逆辺)
struct edge{ int to,cap,cost,rev; };
int V; // TODO:initialize
const int MAX_V = ; // TODO:initialize
const int INF = ; // TODO:initialize
vector<edge> G[MAX_V];
int h[MAX_V]; // ポテンシャル
int dist[MAX_V];
int prevv[MAX_V], preve[MAX_V]; // 直前の頂点と辺

void add_edge(int from, int to, int cap, int cost){
    G[from].pb({to,cap,cost,(int)G[to].size()});
    G[to].pb({from,0,-cost,(int)G[from].size()-1});
}
// sからtへの流量fの最小費用流(不可能なら-1)
int min_cost_flow(int s, int t, int f, bool neg = false){
    int res = 0;
    fill(h,h+V,0);
    while(f>0){
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        fill(dist,dist+V,INF);
        dist[s]=0;
        if(neg){
            // bellman-fordでhを更新
            neg = false;
            bool update;
            do{
                update = false;
                rep(v,V){
                    if(dist[v] == INF) continue;
                    rep(i,G[v].size()){
                        edge &e = G[v][i];
                        if(e.cap>0 && dist[e.to]>dist[v]+e.cost){
                            dist[e.to]=dist[v]+e.cost;
                            prevv[e.to] = v;
                            preve[e.to] = i;
                            update = true;
                        }
                    }
                }
            }while(update);
        }
        else{
            // dijkstraでhを更新
            pq.push(pi(0,s));
            while(!pq.empty()){
                pi p = pq.top();
                pq.pop();
                int v = p.se;
                if(p.fi>dist[v]) continue;
                rep(i,G[v].size()){
                    edge &e = G[v][i];
                    if(e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
                        dist[e.to] = dist[v]+e.cost+h[v]-h[e.to];
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        pq.push(pi(dist[e.to],e.to));
                    }
                }
            }
        }

        // これ以上流せない
        if(dist[t]==INF) return -1;
        rep(v,V) h[v] += dist[v];
        // s-t間の最短路に沿って目一杯流す
        int d=f;
        for(int v=t; v!=s; v=prevv[v]) d = min(d,G[prevv[v]][preve[v]].cap);
        f -= d;
        res += d*h[t];

        for(int v=t; v!=s; v=prevv[v]){
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}

// 辺に最小流量制約がある場合
// e(u->v)に対して、最大流量c、最小流量b、コストdのとき
// e'(u->v)を用意して、
// e:{cap:c-b, cost:d} / e':{cap:b, cost:d-M(十分に大きい数)}
// としてからMCFを求め、それに M*Σb を足せば良い (d-Mが負になるかもしれないので注意)

// グラフに負のコストの辺がある場合
// ・ベルマンフォードを使う

// ・使われる辺の個数が等しいとき：
// それらのコストに適当なkを足して非負にしておき、あとでそれらを引く

// ・流す流量Fが一定であるとき：
// e(u->v): cap:c, cost:-dの辺に対して、

// 旧source(s),sink(t)
// 新しいsource(S),sink(T)を作成
// 辺の張り方
// v->u:{cap:c, cost:d} / u->T:{cap:c, cost:0} / S->v:{cap:c, cost:0}
// S->s:{cap:F, cost:0} / t->T:{cap:F, cost:0}

// このグラフに対して、
// min_cost_flow(S,T,F+Σc(コスト負の辺)) + Σc*(-d)
// がもとのグラフに対する最小費用流になる

/* GlocalMinCut*/
int V; // TODO:initialize
const int MAX_V = ; // TODO:initialize
const int G_INF = ; // TODO:initialize
vector<vector<int>> G;
// O(V^3)
int global_min_cut(){
    int ret = G_INF;
    vector<int> redV(V);
    rep(i,V) redV[i] = i;
    for(int r=V; r>1; --r){
        // calc Maximum Adjacent Order
        int u=0, v=0, cut=0;
        vector<int> w(r,0);
        rep(i,r){
            u = v;
            v = max_element(all(w)) - w.begin();
            cut = w[v];
            w[v] = -1;
            rep(nx,r)if(w[nx]>=0) w[nx] += G[redV[v]][redV[nx]];
        }
        // merge
        rep(i,r){
            G[redV[u]][redV[i]] += G[redV[v]][redV[i]];
            G[redV[i]][redV[u]] += G[redV[i]][redV[v]];
        }
        redV.erase(redV.begin()+v);
        // update
        ret = min(ret,cut);
    }
    return ret;
}

struct SCC{
    int V;
    vector<vector<int>> G, rG;
    vector<int> vs; // 帰りがけ順の並び
    vector<int> cmp; //属する強連結成分トポロジカル順序
    vector<bool> used;

    SCC(){}
    SCC(int n){
        V = n;
        G = vector<vector<int>>(n);
        rG = vector<vector<int>>(n);
    }
    void add_edge(int from, int to){
        G[from].pb(to);
        rG[to].pb(from);
    }
    void dfs(int v){
        used[v] = true;
        rep(i,G[v].size())if(!used[G[v][i]]) dfs(G[v][i]);
        vs.push_back(v);
    }
    void rdfs(int v, int k){
        used[v]=true;
        cmp[v]=k;
        rep(i,rG[v].size())if(!used[rG[v][i]]) rdfs(rG[v][i],k);
    }
    int scc(){
        used = vector<bool>(V,false);
        vs.clear();
        rep(i,V)if(!used[i]) dfs(i);
        used = vector<bool>(V,false);
        cmp = vector<int>(V);
        int num_scc = 0;
        for(int i=vs.size()-1; i>=0; --i)if(!used[vs[i]]) rdfs(vs[i],num_scc++);
        return num_scc;
    }
};

struct TwoSat{
    int v;
    SCC graph;
    // v literals
    // 0~v-1: true
    // v~2v-1: false
    TwoSat(int num_literal){
        v = num_literal;
        graph = SCC(2*v);
    }
    inline int num(int id, bool b){return id+(b?0:v);}
    void add_clause(int x, bool X, int y, bool Y){
        graph.add_edge(num(x,!X), num(y,Y));
        graph.add_edge(num(y,!Y), num(x,X));
    }
    // 割り当てが可能か調べる
    bool calc(){
        graph.scc();
        rep(i,v)if(graph.cmp[i]==graph.cmp[v+i]) return false;
        return true;
    }
    // リテラルの真偽値を返す
    vector<bool> get_literals(){
        assert(calc());
        vector<bool> res(v);
        rep(i,v) res[i] = (graph.cmp[i]>graph.cmp[v+i]);
        return res;
    }
};

// 最小有向全域木 O(VE)
using Edge = pair<ll,pair<int,int>>; // (重み, u->v)
const ll INF = LLONG_MAX/3;
// 辺集合, 頂点数, 根
ll Chu_Liu_Edmonds(const vector<Edge> es, int V, int root){
    // 頂点iに入ってくる辺(u->i)の中で、最小のコストの辺を管理 (コスト, u)
    vector<pair<ll,int>> mn(V, {INF,-1});
    for(Edge e:es){
        int u = e.se.fi, v = e.se.se;
        mn[v] = min(mn[v], {e.fi, u});
    }
    mn[root] = {0,-1};

    // 連結成分に分ける(1つの閉路に対して1つの番号を与える)
    vector<int> cmp(V);
    // この連結成分が閉路であるか
    vector<bool> cycle(V,false);
    int cc = 0;

    vector<bool> vis(V);
    rep(i,V){
        if(vis[i]) continue;
        vector<int> path;
        int now = i;
        while(now!=-1 && !vis[now]){
            vis[now] = true;
            path.pb(now);
            // 今張っている辺を逆方向にたどる
            now = mn[now].se;
        }
        if(now != -1){
            bool in_cycle = false;
            for(int j:path){
                cmp[j] = cc;
                if(j == now){
                    // 閉路の始点(これ以降のpathに入ってる頂点が閉路をなす)
                    in_cycle = true;
                    cycle[cc] = true;
                }
                if(!in_cycle) ++cc;
            }
            if(in_cycle) ++cc;
        }
        else{
            // 閉路なし
            for(int j:path) cmp[j] = cc++;
        }
    }
    if(cc == V){
        // すべての頂点が違う連結成分に分かれたので 閉路なし
        ll ans = 0;
        rep(i,V) ans += mn[i].fi;
        return ans;
    }
    // 閉路分のコスト
    ll cycle_cost = 0;
    rep(i,V)if(i!=root && cycle[cmp[i]]) cycle_cost += mn[i].fi;
    // コストを再設定
    vector<Edge> nes;
    for(Edge e:es){
        int u = e.se.fi, v = e.se.se;
        int cu = cmp[u], cv = cmp[v];
        if(cu == cv) continue; // 閉路内の辺は無視
        else if(cycle[cv]) nes.pb({e.fi - mn[v].fi, {cu,cv}}); // コストを再設定
        else nes.pb({e.fi, {cu,cv}});
    }
    return cycle_cost + Chu_Liu_Edmonds(nes, cc, cmp[root]);
};

/* Heavy-Light decomposition */
struct HL_decomposition{
    int n;
    vector<vector<int>> G;
    vector<int> vid, inv, depth, par, heavy, head, sub;
    /*
    vid : HL分解後のグラフでの頂点ID
    inv : HL分解前のグラフでのvid[i]の頂点ID
    depth : rootからの距離
    par : 根付き木上での親
    heavy : heavy-path上における頂点iの次の頂点ID
    head : 頂点iが属するheavy-pathの先頭の頂点ID
    sub : 部分木のサイズ
    */

    HL_decomposition(){}
    HL_decomposition(int sz) : n(sz), G(n), vid(n), inv(n), depth(n), par(n), heavy(n,-1), head(n), sub(n) {}

    void add_edge(int u, int v){
        G[u].pb(v); G[v].pb(u);
    }
    void build(int root = 0){
        dfs(root, -1);
        dfs2(root);
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
            // curを先頭とするheavy-pathを処理
            for(int i=cur; i!=-1; i=heavy[i]){
                vid[i] = k++;
                inv[vid[i]] = i;
                head[i] = cur;
                // heavy-pathの先頭になるなら、queにpushする
                for(int nx:G[i])if(nx != par[i] && nx != heavy[i]){
                    que.push(nx);
                }
            }
        }
    }
    int lca(int u, int v){
        while(1){
            if(vid[u] > vid[v]) swap(u,v);
            if(head[u] == head[v]) return u;
            v = par[head[v]];
        }
    }
};

// example
HL_decomposition hl;
LazySegTree st;
void _UPDATE(int p, int c, ll w){
    while(1){
        if(hl.head[p] == hl.head[c]){
            st.update(hl.vid[p]+1, hl.vid[c]+1, w);
            break;
        }
        else{
            st.update(hl.vid[hl.head[c]], hl.vid[c]+1, w);
            c = hl.par[hl.head[c]];
        }
    }
}
void UPDATE(int u, int v, ll w){
    int x = hl.lca(u,v);
    _UPDATE(x,u,w);
    _UPDATE(x,v,w);
}
