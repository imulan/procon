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

using pi = pair<int,int>;

struct BIT{
    // [1,n]
    int n; vector<ll> bit;
    // 初期化
    BIT(){}
    BIT(int _n){
        n = _n;
        bit = vector<ll>(n+1,0);
    }
    // sum of [1,i]
    ll sum(int i){
        ll s = 0;
        while(i>0){
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    // add x in i-th element
    void add(int i, ll x){
        while(i<=n){
            // dbg(i);
            bit[i] += x;
            i += i & -i;
        }
    }

    // [l,r]
    void add(int l, int r, ll x){
        // printf("ADD %d %d %lld\n",l,r,x);
        l = (l+1)/2;
        r = (r+1)/2;
        add(l+1,x);
        add(r+2,-x);
    }

};

BIT b[2];

vector<pi> e,o;
const int P = 1100010;

void init(){
    e.pb({0,0});
    int now = 0;
    for(int i=1; i<1500; ++i){
        now += i;
        if(now>=P) break;
        if(now%2==1) o.pb({now,i});
        else e.pb({now,i});
    }

    rep(i,2) b[i] = BIT(P);
}

void FROG(int p, int m){
    // printf(" F %d %d\n",p,m);
    int idx = (p+1)/2;

    int l = p, r = p;
    for(const auto &w:e){
        int a = w.se;
        int nl = max(0,p-w.fi), nr = min(P-1,p+w.fi);

        b[p%2].add(nl,l,m*a);
        b[p%2].add(r,nr,m*a);

        l = max(0,nl-2);
        r = min(P-1,nr+2);
    }

    l = p-1;
    r = p+1;
    for(const auto &w:o){
        int a = w.se;
        int nl = max(0,p-w.fi), nr = min(P-1,p+w.fi);

        b[!(p%2)].add(nl,l,m*a);
        b[!(p%2)].add(r,nr,m*a);

        l = max(0,nl-2);
        r = min(P-1,nr+2);
    }
}

ll ANS(int p){
    return b[p%2].sum((p+1)/2 +1);
}

int main(){
    init();

    int n,t;
    scanf(" %d %d", &n, &t);
    ++t;

    rep(i,n){
        int p;
        scanf(" %d", &p);
        ++p;
        FROG(p,1);
    }

    int C;
    scanf(" %d", &C);
    rep(_,C){
        char q;
        int a;
        scanf(" %c %d", &q, &a);
        ++a;
        if(q=='t'){
            t = a;
        }
        else{
            int m = 1;
            if(q=='-') m = -1;
            FROG(a,m);
        }

        printf("%lld\n", ANS(t));
    }
    return 0;
}
