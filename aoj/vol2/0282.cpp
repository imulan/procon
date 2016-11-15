#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;

struct MaxSegTree{
    int n; vector<pi> dat;
    //初期化
    MaxSegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<pi>(2*n-1);
    }
    //k番目(0-indexed)の値を更新
    void init(int k){
        int id=k;
        k+=n-1;
        dat[k]=pi(0,-id);
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=max(dat[2*k+1],dat[2*k+2]);
        }
    }
    //k番目(0-indexed)の値を+a
    void add(int k, int a){
        k+=n-1;
        dat[k].fi+=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=max(dat[2*k+1],dat[2*k+2]);
        }
    }
    //内部的に投げられるクエリ
    pi _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return pi(-1200000000,0);

        if(a<=l && r<=b) return dat[k];
        else{
            pi vl=_query(a,b,2*k+1,l,(l+r)/2);
            pi vr=_query(a,b,2*k+2,(l+r)/2,r);
            return max(vl,vr);
        }
    }
    //[a,b)の最大値を求める
    pi query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

int main()
{
    int n,R,L;
    scanf(" %d %d %d", &n, &R, &L);

    MaxSegTree st(n);
    rep(i,n) st.init(i);

    vector<int> a(n,0);
    int T=0;
    while(R--)
    {
        int d,t,x;
        scanf(" %d %d %d", &d, &t, &x);
        --d;

        pi m=st.query(0,n);
        int id=-m.se;
        a[id]+=t-T;
        T=t;

        st.add(d,x);
    }
    pi m = st.query(0,n);
    int id = -m.se;
    a[id]+=L-T;

    int ans=-1;
    int maxT=0;
    rep(i,n)
    {
        if(maxT<a[i])
        {
            maxT=a[i];
            ans=i+1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
