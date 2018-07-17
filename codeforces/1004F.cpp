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

const int INF = 19191919;
const int B = 20;

int x;

struct Seg{
    // [l,r)
    int l,r;
    int rpos[B],lpos[B];
    ll val;

    Seg(){
        l=-1;
        r=-1;
        fill(lpos,lpos+B,INF);
        fill(rpos,rpos+B,-INF);
        val = 0;
    }
    Seg(int idx, int s){
        l = idx;
        r = idx+1;
        val = (s>=x);

        fill(lpos,lpos+B,INF);
        fill(rpos,rpos+B,-INF);
        rep(i,B){
            if(s>>i&1){
                lpos[i] = min(lpos[i], idx);
                rpos[i] = max(rpos[i], idx);
            }
        }
    }
};

void merge(Seg &ret, const Seg &L, const Seg &R){
    if(L.l==-1){
        ret = R;
        return;
    }
    if(R.l==-1){
        ret = L;
        return;
    }

    ret.l = L.l;
    ret.r = R.r;

    rep(i,B){
        ret.lpos[i] = min(L.lpos[i], R.lpos[i]);
        ret.rpos[i] = max(L.rpos[i], R.rpos[i]);
    }

    // calc val
    ret.val = L.val+R.val;

    // L.rpos と R.lposに注目
    pi pl[B],pr[B+1];
    rep(i,B){
        pl[i] = {L.rpos[i],i};
        pr[i] = {R.lpos[i],i};
    }
    pr[B] = {R.l,-1};
    sort(pl,pl+B, greater<pi>());
    sort(pr,pr+B+1, greater<pi>());

    int rmask = (1<<B)-1, lmask = 0;
    int lidx = 0;
    rep(i,B+1){
        int b = pr[i].se;
        int Rlen = 0;
        if(i==0 || pr[i-1].fi==INF) Rlen = R.r-1 - pr[i].fi + 1;
        else Rlen = pr[i-1].fi-1 - pr[i].fi + 1;
        Rlen = max(Rlen,0);

        while(lidx<B && (rmask|lmask)<x){
            lmask |= (1<<pl[lidx].se);
            ++lidx;
        }

        int Llen = 0;
        if(lidx==0) Llen = L.r-1-L.l+1;
        else Llen = pl[lidx-1].fi-L.l+1;
        Llen = max(Llen,0);

        if((rmask|lmask)>=x) ret.val += (ll)Rlen*Llen;
        if(b>=0) rmask ^= (1<<b);
    }
}

struct SegTree{
    int n; vector<Seg> dat;
    //初期化
    SegTree(int _n, vector<int> &a){
        n=1;
        while(n<_n) n*=2;
        dat=vector<Seg>(2*n-1);

        a.resize(n);
        rep(i,n){
            int idx = i+n-1;
            dat[idx] = Seg(i,a[i]);
        }
        for(int i=n-2; i>=0; --i){
            merge(dat[i],dat[2*i+1],dat[2*i+2]);
        }
    }

    //k番目(0-indexed)の値をaに変更
    void update(int k, int a){
        int idx = k;
        k+=n-1;
        dat[k] = Seg(idx,a);

        //更新
        while(k>0){
            k=(k-1)/2;
            merge(dat[k],dat[2*k+1],dat[2*k+2]);
        }
    }
    //内部的に投げられるクエリ
    Seg _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return Seg();

        if(a<=l && r<=b) return dat[k];

        Seg vl=_query(a,b,2*k+1,l,(l+r)/2);
        Seg vr=_query(a,b,2*k+2,(l+r)/2,r);
        Seg ret;
        merge(ret,vl,vr);
        return ret;
    }
    //[a,b)の最大値を求める
    ll query(int a, int b){
        return _query(a,b,0,0,n).val;
    }
};


int main(){
    int n,m;
    scanf(" %d %d %d", &n, &m, &x);

    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    SegTree st(n,a);
    while(m--){
        int t,p,q;
        scanf(" %d %d %d", &t, &p, &q);
        if(t==1){
            --p;
            st.update(p,q);
        }
        else{
            --p;
            --q;
            printf("%lld\n", st.query(p,q+1));
        }
    }
    return 0;
}
