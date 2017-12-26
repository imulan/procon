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

struct SegTree{
    int n;
    vector<ll> dat,x;

    SegTree(int _n){
        n=1;
        while(n<_n) n*=2;

        dat=vector<ll>(2*n-1,0);
        x=vector<ll>(2*n-1,1);
    }

    int count(int k, int L)
    {
        // 葉ノード
        if(k>=n-1) return dat[k]>L;

        if(dat[2*k+1]<L) return count(2*k+2,L);

        int ret = count(2*k+1,L);
        ret += x[k] - x[2*k+1];
        return ret;
    }

    void add(int k, ll a){
        k+=n-1;
        dat[k]+=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k] = max(dat[2*k+1],dat[2*k+2]);
            x[k] = x[2*k+1] + count(2*k+2,dat[2*k+1]);
        }
    }

    ll _maxquery(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return -1;

        if(a<=l && r<=b) return dat[k];

        ll vl=_maxquery(a,b,2*k+1,l,(l+r)/2);
        ll vr=_maxquery(a,b,2*k+2,(l+r)/2,r);
        return max(vl,vr);
    }
    //[a,b)
    ll maxquery(int a, int b){
        return _maxquery(a,b,0,0,n);
    }

    int _find_h(int a, int b, int k, int l, int r, ll val)
    {
        // この区間の最大値がval未満
        if(dat[k]<val) return r;
        // 区間内に値が1つ
        if(l==r-1) return l;

        // 左の子ノードの終点がa以下
        if((l+r)/2<=a) return _find_h(a,b,2*k+2,(l+r)/2,r,val);

        int ret = _find_h(a,b,2*k+1,l,(l+r)/2,val);
        if(ret<(l+r)/2) return ret;
        return _find_h(a,b,2*k+2,(l+r)/2,r,val);
    }
    //[a,b)でval以上になる最小のindex
    int find_h(int a, int b, ll val)
    {
        return _find_h(a,b,0,0,n,val);
    }

    pi _query(int a, int b, int k, int l, int r, int L)
    {
        if(r<=a || b<=l) return {0,-1};
        if(a<=l && r<=b) return {count(k,L),dat[k]};

        pi vl = _query(a,b,2*k+1,l,(l+r)/2,L);
        pi vr = _query(a,b,2*k+2,(l+r)/2,r,max(L,vl.se));

        return {vl.fi+vr.fi, max(vl.se,vr.se)};
    }

    int query(int k, int L, int R)
    {
        return _query(k,min(n,find_h(k,n,R)+1),0,0,n,L-1).fi;
    }
};

void solve()
{
    int n,Q;
    scanf(" %d %d", &n, &Q);

    SegTree st(n);
    rep(i,n)
    {
        int a;
        scanf(" %d", &a);
        st.add(i,a);
    }

    while(Q--)
    {
        char c;
        int idx;
        scanf(" %c %d", &c, &idx);
        --idx;
        if(c=='+')
        {
            int X;
            scanf(" %d", &X);
            st.add(idx,X);
        }
        else
        {
            int L,R;
            scanf(" %d %d", &L, &R);
            printf("%d\n", st.query(idx,L,R));
        }
    }
}

int main()
{
    int T;
    scanf(" %d", &T);
    while(T--) solve();
    return 0;
}
