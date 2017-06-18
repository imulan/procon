#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

using pi = pair<int,int>;

int L;

inline void UNIQ(vector<pi> &v)
{
    sort(all(v));
    v.erase(unique(all(v)),v.end());
}

inline pi lc(int x, int y)
{
    if(x+y>L-1)
    {
        y-=(L-1-x);
        x=L-1;
    }
    else
    {
        x+=y;
        y=0;
    }
    return pi(x,y);
}

inline pi rc(int x, int y)
{
    if(x>y)
    {
        x-=y;
        y=0;
    }
    else
    {
        y-=x;
        x=0;
    }
    return pi(x,y);
}

ll cross_points(const vector<pi> &l, const vector<pi> &r)
{
    ll ret = 0;
    rep(i,r.size())
    {
        pi left = r[i], right;
        if(r[i].fi==0) right = pi(L-1-r[i].se,L-1);
        else right = pi(L-1,L-1-r[i].fi);

        int lidx = lower_bound(all(l),lc(left.fi,left.se)) - l.begin();
        int ridx = upper_bound(all(l),lc(right.fi,right.se)) - l.begin();

        ret += max(0,ridx-lidx);
    }
    return ret;
}

int main()
{
    int n;
    scanf(" %d %d", &L, &n);

    vector<pi> lw,lb,rw,rb;
    rep(i,n)
    {
        int x,y;
        scanf(" %d %d", &x, &y);

        pi pl=lc(x,y), pr=rc(x,y);

        if((pl.fi+pl.se)%2==0) lw.pb(pl);
        else lb.pb(pl);
        if((pr.fi+pr.se)%2==0) rw.pb(pr);
        else rb.pb(pr);
    }

    UNIQ(lw);
    UNIQ(lb);
    UNIQ(rw);
    UNIQ(rb);

    ll ans = 0;

    for(const auto &p:lw) ans += (p.se>0?L-p.se:p.fi+1);
    for(const auto &p:lb) ans += (p.se>0?L-p.se:p.fi+1);
    for(const auto &p:rw) ans += L-max(p.fi,p.se);
    for(const auto &p:rb) ans += L-max(p.fi,p.se);

    // 交点を取り除く
    ans -= cross_points(lw,rw);
    ans -= cross_points(lb,rb);

    printf("%lld\n", ans);
    return 0;
}
