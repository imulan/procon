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

const int N = 300000;
vector<int> G[N];

vector<int> et;
int ct = 0;
int L[N],R[N];
void dfs(int x, int par){
    L[x] = ct++;
    for(int e:G[x])if(e!=par){
        dfs(e,x);
    }
    R[x] = ct;
}

const int B = 100;
struct SegTree{
    int n; vector<bitset<B>> dat;
    //初期化
    SegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat = vector<bitset<B>>(2*n-1,bitset<B>());
    }

    void update(int k, int idx){
        k+=n-1;
        dat[k].reset();
        dat[k].set(idx);
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k] = dat[2*k+1]^dat[2*k+2];
        }
    }

    bitset<B> _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return bitset<B>();

        if(a<=l && r<=b) return dat[k];

        bitset<B> vl = _query(a,b,2*k+1,l,(l+r)/2);
        bitset<B> vr = _query(a,b,2*k+2,(l+r)/2,r);
        return vl^vr;
    }
    //[a,b)
    bitset<B> query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

int main(){
    int n,q;
    scanf(" %d %d", &n, &q);

    vector<int> c(n);
    rep(i,n) scanf(" %d", &c[i]);

    for(int i=1; i<n; ++i){
        int p;
        scanf(" %d", &p);
        --p;
        G[p].pb(i);
        G[i].pb(p);
    }

    dfs(0,-1);
    // rep(i,n) printf(" %d: %d %d\n", i,L[i],R[i]);

    SegTree st(n);
    rep(i,n) st.update(L[i],c[i]-1);

    rep(_,q){
        int k,x;
        scanf(" %d %d", &k, &x);
        if(k==0){
            --x;
            bitset<B> res = st.query(L[x],R[x]);
            printf("%d\n", res.count());
        }
        else{
            --k;
            --x;
            st.update(L[x],k);
        }
    }

    return 0;
}
