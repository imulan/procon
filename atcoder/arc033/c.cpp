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

struct SumSegTree{
    long n; vector<ll> dat;
    //初期化
    SumSegTree(long _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,0);
    }
    //k番目(0-indexed)の値をaを加える
    void update(long k, ll a){
        k+=n-1;
        dat[k]+=a;
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

const long N=200001;

int main()
{
    SumSegTree segt(N);

    int Q=0;
    cin >>Q;

    rep(q,Q)
    {
        int t,x;
        scanf(" %d %d", &t, &x);
        if(t==1) segt.update(x,1);
        else
        {
            int l=1, r=N;
            while(r-l>1)
            {
                int med=(l+r)/2;
                if(segt.query(1,med)<x) l=med;
                else r=med;
            }

            segt.update(l,-1);
            printf("%d\n", l);
        }
    }

    return 0;
}
