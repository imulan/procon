#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct MaxSegTree{
    long n; vector<ll> dat;
    //初期化
    MaxSegTree(long _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,LLONG_MIN);
    }
    //k番目(0-indexed)の値をaに変更
    void update(long k, ll a){
        k+=n-1;
        dat[k]=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=max(dat[2*k+1],dat[2*k+2]);
        }
    }
    //内部的に投げられるクエリ
    ll _query(long a, long b, long k, long l, long r){
        if(r<=a || b<=l) return LLONG_MIN;

        if(a<=l && r<=b) return dat[k];
        else{
            ll vl=_query(a,b,2*k+1,l,(l+r)/2);
            ll vr=_query(a,b,2*k+2,(l+r)/2,r);
            return max(vl,vr);
        }
    }
    //[a,b)の最大値を求める
    ll query(long a, long b){
        return _query(a,b,0,0,n);
    }
};

int main()
{
    int n;
    scanf(" %d", &n);

    MaxSegTree st(n+1);
    vector<int> h(n);
    rep(i,n)
    {
        scanf(" %d", &h[i]);
        st.update(i,h[i]);
    }

    rep(i,n)
    {
        int ans=0;

        // iより左について、rまでは見える
        int l=-1, r=i;
        while(r-l>1)
        {
            int m=(l+r)/2;
            if(st.query(m,i)<=h[i]) r=m;
            else l=m;
        }
        ans+=i-r;
        // iより右について、lまでは見える
        l=i, r=n;
        while(r-l>1)
        {
            int m=(l+r)/2;
            if(st.query(i,m+1)<=h[i]) l=m;
            else r=m;
        }
        ans+=l-i;

        printf("%d\n", ans);
    }

    return 0;
}
