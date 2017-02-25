#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<ll,int> pl;

struct MaxSegTree{
    long n; vector<pl> dat;
    //初期化
    MaxSegTree(long _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<pl>(2*n-1,pl(-1,1));
    }
    //k番目(0-indexed)の値をaに変更
    void update(long k, pl a){
        k+=n-1;
        dat[k]=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=max(dat[2*k+1],dat[2*k+2]);
        }
    }
    //内部的に投げられるクエリ
    pl _query(long a, long b, long k, long l, long r){
        if(r<=a || b<=l) return pl(-1,1);

        if(a<=l && r<=b) return dat[k];

        pl vl=_query(a,b,2*k+1,l,(l+r)/2);
        pl vr=_query(a,b,2*k+2,(l+r)/2,r);
        return max(vl,vr);
    }
    //[a,b)の最大値を求める
    pl query(long a, long b){
        return _query(a,b,0,0,n);
    }
};

int main()
{
    int n,d;
    ll k;
    cin >>n >>d >>k;

    ll ans=0;
    int p=-1,q=-1;

    MaxSegTree st(n);
    vector<int> x(n);
    rep(i,n)
    {
        scanf(" %d", &x[i]);
        st.update(i,pl(x[i],-i));
    }

    rep(i,n)
    {
        pl res = st.query(i,min(n,i+d+1));
        ll diff = res.fi - x[i];
        diff*=k;
        if(diff>ans)
        {
            ans = diff;
            p = i;
            q = -res.se;
        }
    }




    cout << ans << endl;
    if(p!=-1) printf("%d %d\n",p,q);
    return 0;
}
