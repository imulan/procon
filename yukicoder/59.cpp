#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int N=1000000;

struct SumSegTree{
    long n; vector<ll> dat;
    //初期化
    SumSegTree(long _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,0);
    }
    //k番目(0-indexed)の値に+a
    //負にはしない
    void update(long k, ll a){
        k+=n-1;
        dat[k]=max(dat[k]+a,0LL);
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=dat[2*k+1]+dat[2*k+2];
        }
    }
    //内部的に投げられるクエリ
    ll _query(long a, long b, long k, long l, long r){
        if(r<=a || b<=l) return 0;

        if(a<=l && r<=b) return dat[k];
        else{
            ll vl=_query(a,b,2*k+1,l,(l+r)/2);
            ll vr=_query(a,b,2*k+2,(l+r)/2,r);
            return vl+vr;
        }
    }
    //[a,b)の和を求める
    ll query(long a, long b){
        return _query(a,b,0,0,n);
    }
};

int main()
{
    int n,k;
    cin >>n >>k;

    SumSegTree st(N+2);
    rep(i,n)
    {
        int w;
        scanf(" %d", &w);

        if(w>0)
        {
            if(st.query(w,N+1)<k) st.update(w,1);
        }
        else
        {
            st.update(-w,-1);
        }
        //cout << st.query(0,N+1) << endl;;
    }

    cout << st.query(0,N+1) << endl;;
    return 0;
}
