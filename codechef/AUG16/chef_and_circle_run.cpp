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
    int T;
    cin >>T;
    rep(times,T)
    {
        int n,start,end;
        cin >>n;
        vector<int> R(n);
        rep(i,n) scanf(" %d", &R[i]);
        cin >>start >>end;
        --start;
        --end;

        //スタート地点を0にするように回転
        vector<int> r(n);
        rep(i,n) r[i] = R[(i+start)%n];
        end-=start;
        start = 0;

        //前からと後ろからのそれぞれの累積和
        vector<ll> pre(n), suf(n);
        pre[0]=0;
        for(int i=1; i<n; ++i) pre[i]=pre[i-1]+r[i-1];
        suf[0]=0;
        suf[n-1]=r[n-1];
        for(int i=n-2; i>0; --i) suf[i]=suf[i+1]+r[i];

        // rep(i,n) printf("%d// pre: %lld, suf: %lld\n",i,pre[i],suf[i]);

        ll circle = pre[n-1]+r[n-1];

        //直接向かう
        ll ans = min(pre[end], suf[end]);
        //1周してから
        ans = min(ans, circle+pre[end]);
        ans = min(ans, circle+suf[end]);
        //折り返してから向かう
        for(int i=1; i<=end; ++i) ans = min(ans, 2*pre[i]+suf[end]);
        for(int i=end; i<n; ++i) ans = min(ans, 2*suf[i]+pre[end]);
        //通りすぎてから戻る
        for(int i=end+1; i<n; ++i) ans = min(ans, 2*pre[i]-pre[end]);
        for(int i=1; i<end; ++i) ans = min(ans, 2*suf[i]-suf[end]);

        MinSegTree st(n+1);
        st.update(end,0);
        for(int i=1; i<end; ++i) st.update(i,pre[end]-pre[i]);
        for(int i=end+1; i<n; ++i) st.update(i,pre[i]-pre[end]);

        for(int i=1; i<end; ++i) ans=min(ans,2*pre[i]+suf[end]+2*st.query(i,end));
        for(int i=end+1; i<n; ++i) ans=min(ans,2*suf[i]+pre[end]+2*st.query(end,i));

        cout << ans << endl;
    }
    return 0;
}
