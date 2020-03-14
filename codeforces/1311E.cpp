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

using pi = pair<int,int>;
using pl = pair<ll,ll>;

struct SegTree{
    int n; vector<ll> dat,num;
    // 初期化
    SegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,0);
        num=vector<ll>(2*n-1,0);
    }

    void add(int k, ll a, bool f){
        k+=n-1;
        dat[k]+=a;
        if(f) ++num[k];
        else --num[k];
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k] = dat[2*k+1]+dat[2*k+2];
            num[k] = num[2*k+1]+num[2*k+2];
        }
    }
    // 内部的に投げられるクエリ
    pl _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return {0,0};

        if(a<=l && r<=b) return {dat[k],num[k]};

        pl vl=_query(a,b,2*k+1,l,(l+r)/2);
        pl vr=_query(a,b,2*k+2,(l+r)/2,r);
        return {vl.fi+vr.fi, vl.se+vr.se};
    }
    // [a,b)
    pl query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

int main(){
    int n;
    scanf(" %d", &n);

    vector<pi> p(n);
    vector<int> uv;

    rep(i,n) scanf(" %d", &p[i].fi);
    rep(i,n){
        scanf(" %d", &p[i].se);
        uv.pb(p[i].se);
    }
    sort(all(p));

    sort(all(uv));
    uv.erase(unique(all(uv)), uv.end());
    int V = uv.size();

    SegTree L(V);
    ll ans = 0;
    rep(i,n){
        ll x = p[i].fi, v = p[i].se;
        int vidx = lower_bound(all(uv),v) - uv.begin();

        pl t = L.query(0,vidx+1);
        ans += t.se*x - t.fi;

        L.add(vidx,x,true);
    }
    printf("%lld\n", ans);
    return 0;
}
