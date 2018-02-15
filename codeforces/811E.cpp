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

const int N = 10, M = 100000;

struct node{
    int n;
    int l[N],r[N];
    int cc = 0;

    node(){}
    node(int _n){
        n = _n;
    }

    // unite ID x & ID y
    void unite(int x, int y){
        --cc;
        rep(i,n){
            if(l[i]==x) l[i] = y;
            if(r[i]==x) r[i] = y;
        }

    }
};


int n,m;
int grid[N][M];

node dat[3*M];

// b.lとposの列が一致
node merge(node a, node b, int pos){
    if(a.cc == 0) return b;
    if(b.cc == 0) return a;

    node ret(n);
    rep(i,n){
        ret.l[i] = a.l[i];
        ret.r[i] = b.r[i];
    }
    ret.cc = a.cc + b.cc;

    rep(i,n){
        if(grid[i][pos-1] == grid[i][pos]){
            int ID_l = a.r[i], ID_r = b.l[i];
            if(ID_l != ID_r){
                ret.unite(ID_l, ID_r);
                a.unite(ID_l, ID_r);
            }
        }
    }

    return ret;
}

void build(int k, int l, int r){
    if(l+1==r){
        dat[k] = node(n);
        rep(i,n) dat[k].l[i] = dat[k].r[i] = l*n+i;
        dat[k].cc = n;

        for(int i=1; i<n; ++i){
            if(grid[i][l] == grid[i-1][l]) dat[k].unite(dat[k].l[i],dat[k].l[i-1]);
        }
        return;
    }

    build(2*k+1, l, (l+r)/2);
    build(2*k+2, (l+r)/2, r);
    dat[k] = merge(dat[2*k+1], dat[2*k+2], (l+r)/2);
}

// [a,b)
node query(int a, int b, int k, int l, int r){
    if(r<=a || b<=l) return node();
    if(a<=l && r<=b) return dat[k];

    node vl = query(a,b,2*k+1,l,(l+r)/2);
    node vr = query(a,b,2*k+2,(l+r)/2,r);
    return merge(vl, vr, (l+r)/2);
}

int main(){
    int q;
    scanf(" %d %d %d", &n, &m, &q);
    rep(i,n)rep(j,m) scanf(" %d", &grid[i][j]);

    build(0,0,m);

    while(q--){
        int ql,qr;
        scanf(" %d %d", &ql, &qr);
        --ql;
        node res = query(ql,qr,0,0,m);
        printf("%d\n", res.cc);
    }
    return 0;
}
