#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct StarrySkyTree{
    long n; vector<ll> dat,segAdd;
    // 初期化
    StarrySkyTree(long _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,0);
        segAdd=vector<ll>(2*n-1,0);
    }
    // 区間和: [a,b)に+x
    void _add(long a, long b, ll x, long k, long l, long r){
        //  交差しない区間であれば終了
        if(r<=a || b<=l) return;

        // 今注目している区間[l,r)が[a,b)に完全に内包される時
        if(a<=l && r<=b){
            segAdd[k] += x;
            return;
        }

        // 子の区間に渡す
        _add(a,b,x,2*k+1,l,(l+r)/2);
        _add(a,b,x,2*k+2,(l+r)/2,r);

        dat[k] = max(dat[2*k+1]+segAdd[2*k+1], dat[2*k+2]+segAdd[2*k+2]);
    }
    void add(long a, long b, ll x)
    {
        _add(a,b,x,0,0,n);
    }

    //内部的に投げられるクエリ
    ll _query(long a, long b, long k, long l, long r){
        if(r<=a || b<=l) return 0;

        if(a<=l && r<=b) return dat[k]+segAdd[k];
        else{
            ll vl=_query(a,b,2*k+1,l,(l+r)/2);
            ll vr=_query(a,b,2*k+2,(l+r)/2,r);
            return max(vl,vr)+segAdd[k];
        }
    }
    //[a,b)の最大値を求める
    ll query(long a, long b){
        return _query(a,b,0,0,n);
    }
};

typedef pair<long,long> pi;
typedef pair<pi,long> P;

int main()
{
    int n;
    long w,h;
    while(scanf(" %d %ld %ld", &n, &w, &h) != EOF)
    {
        --w;
        --h;

        vector<P> p(n);
        rep(i,n) scanf(" %ld %ld %ld", &p[i].fi.fi, &p[i].fi.se, &p[i].se);
        sort(all(p));

        vector<long> x,y;
        rep(i,n)
        {
            x.pb(p[i].fi.fi);
            y.pb(p[i].fi.se);
        }
        sort(all(x));
        x.erase(unique(all(x)),x.end());
        sort(all(y));
        y.erase(unique(all(y)),y.end());

        int X=x.size();
        int Y=y.size();

        StarrySkyTree st(Y);

        int idx=0;
        while(idx<n && p[0].fi.fi+w>=p[idx].fi.fi)
        {
            int lb = lower_bound(all(y),p[idx].fi.se-h) - y.begin();
            int rb = lower_bound(all(y),p[idx].fi.se) - y.begin();
            st.add(lb,rb+1, p[idx].se);

            // printf(" idx %d (%d, %d)\n", idx,lb,rb);
            ++idx;
        }
        // printf("idx %d\n", idx);

        ll ans=1;
        int now=0;

        rep(i,X)
        {
            // printf("i= %d query : %d\n", i,st.query(0,Y));
            // rep(j,Y) printf(" j= %d: %lld\n", j,st.query(j,j+1));

            int tnow=now;
            while(now<n && p[now].fi.fi==x[i])
            {
                int lb = lower_bound(all(y),p[now].fi.se-h) - y.begin();
                int rb = lower_bound(all(y),p[now].fi.se) - y.begin();
                ans = max(ans, st.query(lb,rb+1));
                ++now;

                // printf(" query i= %d:  %lld\n", i,st.query(lb,rb+1));
            }

            now=tnow;
            while(now<n && p[now].fi.fi==x[i])
            {
                int lb = lower_bound(all(y),p[i].fi.se-h) - y.begin();
                int rb = lower_bound(all(y),p[i].fi.se) - y.begin();
                st.add(lb,rb+1, -p[i].se);
                ++now;
            }

            while(i+1<X && idx<n && x[i+1]+w>=p[idx].fi.fi)
            {
                int lb = lower_bound(all(y),p[idx].fi.se-h) - y.begin();
                int rb = lower_bound(all(y),p[idx].fi.se) - y.begin();
                st.add(lb,rb+1, p[idx].se);

                ++idx;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
