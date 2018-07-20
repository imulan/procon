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

struct SegTree{
    int n; vector<ll> dat;
    //初期化
    SegTree(){}
    SegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,LLONG_MAX);
    }
    ll get(int k){
        return dat[k+n-1];
    }
    //k番目(0-indexed)の値をaに変更
    void update(int k, ll a){
        k+=n-1;
        dat[k]=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=min(dat[2*k+1],dat[2*k+2]);
        }
    }
    //内部的に投げられるクエリ
    ll _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return LLONG_MAX;
        if(a<=l && r<=b) return dat[k];

        ll vl=_query(a,b,2*k+1,l,(l+r)/2);
        ll vr=_query(a,b,2*k+2,(l+r)/2,r);
        return min(vl,vr);
    }
    //[a,b)
    ll query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

int main(){
    int n;
    scanf(" %d", &n);

    SegTree t[2];
    rep(i,2){
        t[i] = SegTree(n);
        rep(j,n){
            int x;
            scanf(" %d", &x);
            t[i].update(j,x);
        }
    }

    set<int> upd;
    rep(i,n) upd.insert(i);

    int Q;
    scanf(" %d", &Q);
    while(Q--){
        int x,y,z;
        scanf(" %d %d %d", &x, &y, &z);
        if(x<=2){
            x -= 1;
            t[x].update(y-1,z);
            upd.insert(y-1);
        }
        else if(x<=4){
            x -= 3;
            printf("%lld\n", t[x].query(y-1,z));
        }
        else{
            x -= 5;
            for(int idx:upd) t[x].update(idx, t[!x].get(idx));
            upd.clear();
        }
    }
    return 0;
}
