#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct BIT{
    // [1,n]
    int n; vector<ll> bit;
    BIT(int _n){
        n = _n;
        bit = vector<ll>(n+1,0);
    }

    ll sum(int i){
        ll s = 0;
        while(i>0){
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    void add(int i, ll x){
        while(i<=n){
            bit[i] += x;
            i += i & -i;
        }
    }
};

template<class T>
struct treap{
    struct node_t{
        T val;
        node_t *lch,*rch;
        int pri;
        int cnt;
        T sum;
        T mn;

        node_t(T v, int p):val(v),pri(p),cnt(1),sum(v),mn(v){
            lch = rch = NULL;
        }
    };

    const T INF = 19191919;
    mt19937 mt;
    node_t *root;
    treap():root(NULL){
        const int seed = 232323;
        mt = mt19937(seed);
    }

    int count(node_t *t){ return t ? t->cnt : 0; }
    T sum(node_t *t){ return t ? t->sum : 0; }
    T min(node_t *t){ return t ? t->mn : INF; }

    node_t *update(node_t *t){
        t->cnt = count(t->lch) + count(t->rch) + 1;
        t->sum = sum(t->lch) + sum(t->rch) + t->val;
        t->mn = std::min({min(t->lch),min(t->rch),t->val});
        return t;
    }

    node_t *merge(node_t *l, node_t *r){
        if(!l || !r) return l?l:r;

        if(l->pri > r->pri){
            l->rch = merge(l->rch , r);
            return update(l);
        }
        else{
            r->lch = merge(l, r->lch);
            return update(r);
        }
    }

    pair<node_t*, node_t*> split(node_t *t, int k){ //[0,k), [k,n)
        if(!t) return {NULL,NULL};
        if(k<=count(t->lch)){
            auto s = split(t->lch,k);
            t->lch = s.second;
            return {s.first, update(t)};
        }
        else{
            auto s = split(t->rch, k-count(t->lch)-1);
            t->rch = s.first;
            return {update(t), s.second};
        }
    }

    node_t *insert(node_t *t, int k, T val, int pri){
        auto s = split(t,k);
        t = merge(s.fi, new node_t(val,pri));
        t = merge(t, s.se);
        return update(t);
    }

    node_t *erase(node_t *t, int k){
        auto s2 = split(t,k+1);
        auto s1 = split(s2.fi,k);
        t = merge(s1.fi,s2.se);
        return update(t);
    }

    node_t *find(node_t *t, int k){
        int c = count(t->lch);
        if(k<c) return find(t->lch,k);
        if(k==c) return t;
        return find(t->rch,k-c-1);
    }

    void insert(int k, T val){ root = insert(root,k,val,mt()); }
    void erase(int k){ root = erase(root,k); }
    node_t *find(int k){ return find(root,k); }

    T min(int l, int r){
        assert(l<r);
        auto sr = split(root,r);
        auto sl = split(sr.fi, l);
        auto lr = sl.se;
        T ret = min(lr);
        root = merge(merge(sl.fi,lr),sr.se);
        return ret;
    }
};

int main(){
    int n;
    ll K;
    scanf(" %d %lld", &n, &K);

    vector<int> x(n);
    rep(i,n) scanf(" %d", &x[i]);

    BIT bit(n+1);
    ll Kini = 0;
    rep(i,n){
        bit.add(x[i],1);
        Kini += bit.sum(n+1) - bit.sum(x[i]);
    }
    // printf(" Kini %lld\n", Kini);

    vector<int> ans(n);
    if(Kini<=K) ans = x;
    else{
        ll A = Kini - K;
        treap<int> T;
        rep(i,n) T.insert(i,x[i]);

        auto check = [&](int lim){


        };

        rep(i,n){
            ll lim = min(A,(ll)n-i-1);
            int tgt = T.min(0,lim+1);
            int l=-1, r=lim;
            while(r-l>1){
                int mid = (l+r)/2;
                int tmp = T.min(0,mid+1);
                // printf(" tgt,tmp %d %d\n",tgt, tmp);

                if(tgt < tmp) l=mid;
                else r=mid;
            }


            ans[i] = T.find(r)->val;

            // printf(" %d:: r %d ans %d\n",i,r,ans[i]);
            if(i<n-1){
                A -= r;
                T.erase(r);
            }
        }
    }

    rep(i,n) printf("%d\n", ans[i]);
    return 0;
}
