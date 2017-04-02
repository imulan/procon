#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;
typedef pair<int,pi> query;
typedef pair<ll,ll> pl;

struct SegTree{
    long n; vector<pl> dat;
    //初期化
    SegTree(long _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<pl>(2*n-1,pl(0,0));
    }
    //k番目(0-indexed)の値に+p(a,b)
    void add(long k, pl p){
        k+=n-1;
        dat[k].fi += p.fi;
        dat[k].se += p.se;
        //更新
        while(k>0){
            k=(k-1)/2;

            ll lx=dat[2*k+1].fi, ly=dat[2*k+1].se;
            ll rx=dat[2*k+2].fi, ry=dat[2*k+2].se;

            dat[k]=pl(lx+rx, max(rx+ly,ry));
        }
    }
    //内部的に投げられるクエリ
    pl _query(long a, long b, long k, long l, long r){
        if(r<=a || b<=l) return pl(0,0);

        if(a<=l && r<=b) return dat[k];

        pl vl=_query(a,b,2*k+1,l,(l+r)/2);
        pl vr=_query(a,b,2*k+2,(l+r)/2,r);

        ll lx=vl.fi, ly=vl.se;
        ll rx=vr.fi, ry=vr.se;

        return pl(lx+rx, max(rx+ly,ry));
    }
    //[a,b)の最大値を求める
    pl query(long a, long b){
        return _query(a,b,0,0,n);
    }
};

const int LAST_DAY = 1000000001;

int main()
{
    int Q;
    ll K;
    scanf(" %d %lld", &Q, &K);

    vector<int> days;

    vector<query> q(Q);
    rep(i,Q)
    {
        int x,D,A=-1;
        scanf(" %d %d", &x, &D);
        if(x==1) scanf(" %d", &A);

        q[i] = query(x,pi(D,A));
        days.pb(D);
    }
    days.pb(LAST_DAY);

    sort(all(days));
    days.erase(unique(all(days)), days.end());

    int D = days.size();

    map<int,int> day2id;
    rep(i,D) day2id[days[i]]=i;

    SegTree st(D);

    st.add(0,pl(K*days[0],0));
    for(int i=1; i<D; ++i) st.add(i,pl(K*(days[i]-days[i-1]),0));

    rep(i,Q)
    {
        int x=q[i].fi;
        pi p=q[i].se;

        int ID=day2id[p.fi];

        if(x==1) st.add(ID,pl(-p.se,0));
        else
        {
            pl val = st.query(0,ID+1);
            ll ans = K*p.fi - max(val.fi,val.se);
            printf("%lld\n", ans);
        }
    }
    return 0;
}
