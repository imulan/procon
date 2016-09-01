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

struct MinSegTree{
    long n; vector<ll> dat;
    //初期化
    MinSegTree(long _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,LLONG_MAX);
    }
    //k番目(0-indexed)の値をaに変更
    void update(long k, ll a){
        k+=n-1;
        dat[k]=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=min(dat[2*k+1],dat[2*k+2]);
        }
    }
    //内部的に投げられるクエリ
    ll _query(long a, long b, long k, long l, long r){
        if(r<=a || b<=l) return LLONG_MAX;

        if(a<=l && r<=b) return dat[k];
        else{
            ll vl=_query(a,b,2*k+1,l,(l+r)/2);
            ll vr=_query(a,b,2*k+2,(l+r)/2,r);
            return min(vl,vr);
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
    cin >>n;

    MaxSegTree maxst(n);
    MinSegTree minst(n);

    rep(i,n)
    {
        int a;
        scanf(" %d", &a);
        maxst.update(i,a);
        minst.update(i,a);
    }

    int ans=1;
    int st=0;
    for(int i=1; i<n; ++i)
    {
        if(maxst.query(st,i) <= minst.query(i,n))
        {
            ++ans;
            st=i;
        }
    }
    cout << ans << endl;
    return 0;
}
