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

        node_t(T v, int p):val(v), pri(p), cnt(1){
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

    node_t *update(node_t *t){
        t->cnt = count(t->lch) + count(t->rch) + 1;
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
};

vector<treap<int>> t;

inline void read(int i){
    t[i].insert(0,'#');
    int j=1;
    while(1){
        char c;
        scanf("%c", &c);
        if(c=='\n') break;
        t[i].insert(j++, c-'a');
    }
}

void CHANGE(int a, int b, int c, int d){
    auto pa = t[a].split(t[a].root, b);
    auto pc = t[c].split(t[c].root, d);

    t[a].root = t[a].merge(pa.fi, pc.se);
    t[c].root = t[c].merge(pc.fi, pa.se);
}

void UPDATE(int a, int b, int c){
    t[a].erase(b);
    t[a].insert(b,c);
}

int main(){
    int n,q;
    scanf("%d %d ", &n, &q);

    t.resize(n);
    rep(i,n) read(i);

    // query
    rep(i,q){
        int tp;
        scanf(" %d", &tp);
        if(tp==1){
            int a,b,c,d;
            scanf(" %d %d %d %d", &a, &b, &c, &d);
            --a; --c;
            CHANGE(a,b,c,d);
        }
        else{
            int a,b;
            char c;
            scanf(" %d %d %c", &a, &b, &c);
            --a;
            UPDATE(a,b,c-'a');
        }
    }

    // 復元
    rep(i,n){
        int sz = t[i].count(t[i].root);
        rep(j,sz-1) printf("%c", t[i].find(j+1)->val+'a');
        printf("\n");
    }
    return 0;
}
