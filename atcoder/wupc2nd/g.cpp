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
    ll get(long a){
        return query(0,a+1)-query(0,a);
    }
};

int main()
{
    int n,m,h;
    cin >>n >>m >>h;

    SumSegTree s(200001);
    rep(i,n)
    {
        ll a;
        scanf(" %lld", &a);
        s.update(i,a);
    }

    rep(Q,m)
    {
        char op[16];
        ll arg;
        scanf("%s %lld", op, &arg);

        if(op[0]=='a')
        {
            s.update(n,arg);
            ++n;
        }
        else
        {
            int l=0, r=n+1;
            while(r-l>1)
            {
                int mid=(l+r)/2;
                if(s.query(0,mid)>arg-h) r=mid;
                else l=mid;
            }

            if(l==n)
            {
                printf("miss\n");
                continue;
            }

            if(l+1<n && s.query(0,l+1)<arg+h)
            {
                printf("stop\n");
                continue;
            }

            printf("go\n");
            s.update(l,0);
            while(n>0 && s.query(0,n)-s.query(0,n-1)==0) --n;
        }
    }

    return 0;
}
