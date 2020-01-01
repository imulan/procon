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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template<class Key>
using ordered_set = __gnu_pbds::tree<Key, __gnu_pbds::null_type, less<Key>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

// multisetではないので注意．適当にindex貼ったりする必要がある．あと定数倍重い．
// find_by_order(idx)
// order_of_key(key)  ... lower_bound

using vi = vector<int>;
using os = ordered_set<int>;

struct BIT{
    // [1,n]
    int n; vector<os> bit;
    // 初期化
    BIT(int _n){
        n = _n;
        bit = vector<os>(n+1);
    }
    // sum of [1,i]
    int sum(int i, int lv, int rv){
        int s = 0;
        while(i>0){
            s += bit[i].order_of_key(rv+1) - bit[i].order_of_key(lv);
            i -= i & -i;
        }
        return s;
    }
    // add x in i-th element
    void add(int i, int x){
        ++i;
        while(i<=n){
            bit[i].insert(x);
            i += i & -i;
        }
    }

    void remove(int i, int x){
        ++i;
        while(i<=n){
            bit[i].erase(x);
            i += i & -i;
        }
    }

    int query(int l, int r, int lv, int rv){
        return sum(r+1,lv,rv)-sum(l,lv,rv);
    }
};

int main(){
    int n,q;
    scanf(" %d %d", &n, &q);

    vi a(n),b(n);
    rep(i,n) scanf(" %d", &a[i]);
    rep(i,n) scanf(" %d", &b[i]);

    vi mm(n+1);
    rep(i,n) mm[b[i]] = i;

    rep(i,n) a[i] = mm[a[i]];
    rep(i,n) b[i] = mm[b[i]];

    vi a_idx(n);
    rep(i,n) a_idx[a[i]] = i;

    BIT bit(n);
    rep(i,n) bit.add(i,a[i]);

    rep(i,q){
        int t;
        scanf(" %d", &t);
        if(t==1){
            int la,ra,lb,rb;
            scanf(" %d %d %d %d", &la, &ra, &lb, &rb);
            --la;
            --ra;
            --lb;
            --rb;
            printf("%d\n", bit.query(la,ra,lb,rb));
        }
        else{
            int x,y;
            scanf(" %d %d", &x, &y);
            --x;
            --y;

            bit.remove(a_idx[x],x);
            bit.remove(a_idx[y],y);
            swap(a_idx[x], a_idx[y]);
            bit.add(a_idx[x],x);
            bit.add(a_idx[y],y);
        }
    }
    return 0;
}
