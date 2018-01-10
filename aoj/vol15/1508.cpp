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

template<class T>
struct treap{
    struct node_t{
        T val; // 値
        node_t *lch, *rch;
        int pri; // 優先度
        int cnt; // 部分木のサイズ
        T sum; // 部分木の値の和
        T mn; // 部分木の最小値

        node_t(T v, int p):val(v), pri(p), cnt(1), sum(v), mn(v){
            lch = rch = NULL;
        }
    };

    const T INF = 19191919; // TODO:initialize
    mt19937 mt;
    node_t *root;
    treap():root(NULL){
        const int seed = 364364;
        mt = mt19937(seed);
    }

    int count(node_t *t){ return t ? t->cnt : 0; }
    T sum(node_t *t){ return t ? t->sum : 0; }
    T min(node_t *t){ return t ? t->mn : INF; }

    node_t *update(node_t *t){
        t->cnt = count(t->lch) + count(t->rch) + 1;
        t->sum = sum(t->lch) + sum(t->rch) + t->val;
        t->mn = std::min({min(t->lch), min(t->rch), t->val});
        return t;
    }

    node_t *merge(node_t *l, node_t *r){
        if(!l || !r) return l?l:r;

        if(l->pri > r->pri){ // 左の部分木の根のほうが優先度が高い
            l->rch = merge(l->rch, r);
            return update(l);
        }
        else{
            r->lch = merge(l, r->lch);
            return update(r);
        }
    }

    pair<node_t*, node_t*> split(node_t *t, int k){ // [0,k), [k,n)
        if(!t) return {NULL,NULL};
        if(k <= count(t->lch)){
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
        t = merge(s.first, new node_t(val,pri));
        t = merge(t, s.second);
        return update(t);
    }

    node_t *erase(node_t *t, int k){
        auto s2 = split(t,k+1);
        auto s1 = split(s2.first, k);
        t = merge(s1.first, s2.second);
        return update(t);
    }

    node_t *find(node_t *t, int k){
        int c = count(t->lch);
        if(k < c) return find(t->lch,k);
        if(k == c) return t;
        return find(t->rch, k-c-1);
    }

    void insert(int k, T val){ root = insert(root, k, val, mt()); }
    void erase(int k){ root = erase(root, k); }
    node_t *find(int k){ return find(root,k); }

    // circular shift (右端の値が左端に来て、それ以外が右に1つずつシフト)
    void shift(int l, int r){
        if(r-l==1) return;
        assert(l<r);
        auto sr = split(root, r);
        auto sl = split(sr.first, l);
        auto lr = split(sl.second, r-l-1);
        root = merge(merge(sl.first, merge(lr.second, lr.first)), sr.second);
    }

    // [l,r)
    T min(int l, int r){
        assert(l<r);
        auto sr = split(root, r);
        auto sl = split(sr.first, l);
        auto lr = sl.second;
        T ret = min(lr);
        // 元に戻す
        root = merge(merge(sl.first, lr), sr.second);
        return ret;
    }
};

int main(){
    treap<int> t;

    int n,q;
    cin >>n >>q;
    rep(i,n){
        int a;
        cin >>a;
        t.insert(i,a);
    }

    while(q--){
        int x,y,z;
        cin >>x >>y >>z;
        if(x==0){
            t.shift(y,z+1);
        }
        else if(x==1){
            cout << t.min(y,z+1) << endl;
        }
        else{
            t.erase(y);
            t.insert(y,z);
        }
    }

    return 0;
}
