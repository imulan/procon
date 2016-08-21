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
};

int main()
{
    int n;
    cin >>n;
    vector<int> x(n),y(n);
    rep(i,n) scanf(" %d", &x[i]);
    rep(i,n) scanf(" %d", &y[i]);

    //aが昇順になるように変換
    vector<int> f(n+1);
    rep(i,n) f[x[i]]=i+1;
    rep(i,n) y[i]=f[y[i]];

    SumSegTree s(n+2);
    vector<int> num(n+1);
    rep(i,n)
    {
        num[y[i]]=s.query(y[i]+1,n+1);
        s.update(y[i],1);
    }

    //転倒数
    ll a=0;
    rep(i,n) a+=num[i+1];

    //存在しない場合
    if(a%2==1)
    {
        printf("-1\n");
        return 0;
    }

    //存在する場合
    ll ct=0;
    int now=0;
    while(now<n)
    {
        if(ct+num[now+1]>=a/2) break;

        ct+=num[now+1];
        ++now;
    }

    //答えになる数列
    vector<int> z;
    rep(i,now) z.pb(i+1);
    rep(i,n) if(y[i]>now) z.pb(y[i]);

    for(int i=n-1; i>now; --i)
    {
        if(z[i]<z[i-1])
        {
            swap(z[i],z[i-1]);
            ++ct;
        }
        if(ct==a/2) break;
    }

    rep(i,n)
    {
        if(i) printf(" ");
        //元の数値に変換して表示
        printf("%d", x[z[i]-1]);
    }
    printf("\n");
    return 0;
}
