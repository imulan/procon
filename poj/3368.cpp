#include <cstdio>
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
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
        dat=vector<ll>(2*n-1,0);
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
        if(r<=a || b<=l) return 0;

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
    while(scanf(" %d", &n),n)
    {
        int Q;
        scanf(" %d", &Q);
        vector<int> a(n);
        rep(i,n) scanf(" %d", &a[i]);

        vector<int> start;
        MaxSegTree st(n);
        int p=0;
        rep(i,n)
        {
            if(a[p]!=a[i])
            {
                start.pb(p);
                for(int j=p; j<i; ++j) st.update(j,i-p);
                // printf("p=%d, i=%d\n", p,i);
                p=i;
            }
        }
        start.pb(p);
        start.pb(n);

        // rep(i,start.size()) printf("  start[%d]=%d\n", i,start[i]);
        while(Q--)
        {
            int x,y;
            scanf(" %d %d", &x, &y);
            --x;
            --y;

            // xを含む区間の次の区間の始点
            int l_idx=upper_bound(all(start),x)-start.begin();
            // yを含む区間の始点
            int r_idx=upper_bound(all(start),y)-start.begin()-1;

            // printf("l,r %d, %d: (%d,%d)\n", l_idx, r_idx,start[l_idx], start[r_idx]);
            int ans;
            if(l_idx>r_idx) ans=y-x+1;
            else
            {
                ans=st.query(start[l_idx],start[r_idx]);
                ans=max(ans,start[l_idx]-x);
                ans=max(ans,y-start[r_idx]+1);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
