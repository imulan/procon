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

const ll INF = LLONG_MAX/3;

template<typename T>
class SegTree {
private:
//   const T INF = 123456789123456789LL;//TODO;
  int n;
  vector<T> segMin, segAdd;
  void _add(int a, int b, T x, int k, int l, int r){
    if(r<=a || b<=l) return;
    if(a<=l && r<=b){ segAdd[k]+=x; return; }
    int cl = k*2+1, cr = k*2+2;
    _add(a,b,x,cl,l,(l+r)/2);
    _add(a,b,x,cr,(l+r)/2,r);
    segMin[k] = min(segMin[cl]+segAdd[cl], segMin[cr]+segAdd[cr]);
  }
  T _min(int a, int b, int k, int l, int r) const {
    if(r<=a || b<=l) return INF;
    if(a<=l && r<=b) return segMin[k]+segAdd[k];
    return min(_min(a,b,k*2+1,l,(l+r)/2), _min(a,b,k*2+2,(l+r)/2,r)) + segAdd[k];
  }
public:
  SegTree(){}
  SegTree(vector<T> &v){
    int n_ = v.size();
    n=1;
    while(n<n_) n*=2;
    segMin.resize(2*n-1);
    segAdd.resize(2*n-1, 0);
    rep(i,n_) segMin[n+i-1] = v[i];
    for(int i=n-2; i>=0; i--) segMin[i] = min(segMin[2*i+1], segMin[2*i+2]);
  }
  inline void add(int a, int b, T x){ _add(a,b,x,0,0,n); } // add x in [a,b)
  inline T getMin(int a,int b){ return _min(a,b,0,0,n); } // range min in [a,b)
};

int main(){
    int n;
    scanf(" %d", &n);

    vector<ll> a(n+1);
    for(int i=1; i<=n; ++i){
        scanf(" %lld", &a[i]);
        --a[i];
    }

    vector<ll> v(n+1);
    v[0] = 0;
    for(int i=1; i<=n; ++i) v[i] = a[i] - v[i-1];

    vector<ll> vv[2];
    rep(i,2) vv[i] = vector<ll>(n+1,INF);

    rep(i,n+1){
        vv[i%2][i] = v[i];
    }

    vector<SegTree<ll>> st(2);
    rep(i,2) st[i] = SegTree<ll>(vv[i]);

    int Q;
    scanf(" %d", &Q);
    while(Q--){
        int t,l,r;
        scanf(" %d %d %d", &t, &l, &r);
        ++l;
        ++r;

        // printf("---a\n");
        // rep(j,n+1) printf(" %lld", st[j%2].getMin(j,j+1));
        // printf("\n");

        if(t==1){
            int k;
            scanf(" %d", &k);

            if((r+1-l)%2==1){
                // 区間の長さが奇数
                st[l%2].add(l,n+1,k);
                st[!(l%2)].add(r+1,n+1,-k);
            }
            else{
                st[l%2].add(l,r+1,k);
            }
        }
        else{
            int eo = l%2;
            ll val = st[!eo].getMin(l-1,l);
            ll x = st[eo].getMin(l,r+1) + val;
            ll y = st[!eo].getMin(l,r+1) - val;


            int ans = 1;
            if(min(x,y)<0) ans = 0;

            // 終端
            ll add = val;
            if(r%2 == (l-1)%2) add = -add;
            ll e = st[r%2].getMin(r,r+1) + add;
            if(e != 0) ans = 0;

            // dbg(val);
            // printf(" x,y %lld %lld\n", x,y);
            // dbg(e);
            // printf("  ANS:: %d\n", ans);
            printf("%d\n", ans);
        }
    }

    return 0;
}
