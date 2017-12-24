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

const ll INF = LLONG_MAX/3;

struct Cycle
{
    int A;
    vector<ll> w;
    ll U;
    vector<ll> pre;

    Cycle(){}
    Cycle(vector<ll> _w)
    {
        A = _w.size();
        w = _w;

        U = 0;
        rep(i,A) U += w[i];

        pre = vector<ll>(A);
        for(int i=1; i<A; ++i) pre[i] = pre[i-1]+w[i-1];
    }

    ll dist(int from, int to)
    {
        if(from>to) swap(from,to);
        ll cost = pre[to]-pre[from];
        return min(cost,U-cost);
    }
};

void solve()
{
    int n,q;
    scanf(" %d %d", &n, &q);

    vector<Cycle> c(n);
    rep(i,n)
    {
        int a;
        scanf(" %d", &a);
        vector<ll> w(a);
        rep(j,a) scanf(" %lld", &w[j]);

        c[i] = Cycle(w);
    }

    vector<ll> lc(2*n);
    vector<int> L(n),R(n);
    rep(i,n)
    {
        int v1,v2,w;
        scanf(" %d %d %d", &v1, &v2, &w);
        --v1;
        --v2;

        R[i] = v1;
        L[(i+1)%n] = v2;
        lc[2*i+1] = w;
    }

    rep(i,n) lc[2*i] = c[i].dist(L[i],R[i]);

    ll LU = 0;
    rep(i,2*n) LU += lc[i];

    vector<ll> lp(2*n);
    for(int i=1; i<2*n; ++i) lp[i] = lp[i-1]+lc[i-1];

    while(q--)
    {
        int v1,c1,v2,c2;
        scanf(" %d %d %d %d", &v1, &c1, &v2, &c2);
        --v1; --c1; --v2; --c2;

        ll ans = INF;

        int x = 2*c1, y = 2*c2+1;
        if(x>y) swap(x,y);
        ll add = lp[y] - lp[x];
        add = min(add, LU-add);

        ans = min(ans, c[c1].dist(v1,L[c1])+c[c2].dist(R[c2],v2)+add);

        x = 2*c1+1, y = 2*c2;
        if(x>y) swap(x,y);
        add = lp[y] - lp[x];
        add = min(add, LU-add);

        ans = min(ans, c[c1].dist(v1,R[c1])+c[c2].dist(L[c2],v2)+add);

        printf("%lld\n", ans);
    }
}

int main()
{
    int T;
    scanf(" %d", &T);
    while(T--) solve();
    return 0;
}
