#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct SumSegTree{
    long n; vector<ll> dat;
    //初期化
    SumSegTree(long _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,0);
    }
    //k番目(0-indexed)の値をaに変更
    void update(long k, ll a){
        k+=n-1;
        dat[k]=a;
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

        ll vl=_query(a,b,2*k+1,l,(l+r)/2);
        ll vr=_query(a,b,2*k+2,(l+r)/2,r);
        return vl+vr;
    }
    //[a,b)の和
    ll query(long a, long b){
        return _query(a,b,0,0,n);
    }
};

int solve()
{
    int n;
    scanf(" %d", &n);

    vector<int> a(n),pos(n);
    rep(i,n)
    {
        scanf(" %d", &a[i]);
        --a[i];
        pos[a[i]] = i;
    }

    if(n==1) return 1;

    set<int> rpos;
    rep(i,n) rpos.insert(i);

    int ans=0;
    SumSegTree st(n);

    rpos.erase(pos[0]);
    st.update(pos[0],1);

    for(int i=1; i<n-1; ++i)
    {
        rpos.erase(pos[i]);

        int L = *rpos.begin(), R = *rpos.rbegin();
        ans = max(ans,(int)st.query(L,pos[i]));
        ans = max(ans,(int)st.query(pos[i],R));

        st.update(pos[i],1);
        // printf(" i= %d (posi = %d), L= %d, R= %d\n", i,pos[i],L,R);
    }

    return ans+2;
}

int main()
{
    printf("%d\n", solve());
    return 0;
}
