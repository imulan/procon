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

typedef pair<int,int> pi;

/******************************
 MaxSegTree.cpp  START
******************************/

/******************************
 区間の最大値を返すSegmentTree
******************************/

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
        dat[k]=max(dat[k],a);
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

/******************************
 MaxSegTree.cpp  END
******************************/

int main()
{
    int n;
    cin >>n;
    vector<pi> p(n);
    rep(i,n) scanf(" %d %d", &p[i].fi, &p[i].se);
    rep(i,n) p[i].se=-p[i].se;
    sort(all(p));
    rep(i,n) p[i].se=-p[i].se;

    MaxSegTree s(100001);
    rep(i,n)
    {
        ll res=s.query(0,p[i].se);
        s.update(p[i].se,res+1);
    }

    cout << s.query(0,100001) << endl;
    return 0;
}
