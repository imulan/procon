#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

using pl = pair<ll,ll>;

vector<pl> pd,cm;
ll f(int pidx, int cidx){
    if(cm[cidx].fi - pd[pidx].fi < 0) return -1;
    return (cm[cidx].fi - pd[pidx].fi)*(cm[cidx].se - pd[pidx].se);
}

const int N = 500500;
int midx[N];
ll minima(int ly, int ry, int lx, int rx){
    if(ly > ry) return 0;
    if(ly == ry){
        int idx = lx;
        ll v = f(ly,lx);
        for(int j=lx+1; j<=rx; ++j){
            ll tv = f(ly,j);
            if(tv>=v){
                idx = j;
                v = tv;
            }
        }
        midx[ly] = idx;

        v = max(0LL, v);
        return v;
    }

    int my = (ly+ry)/2;
    ll ret = 0;
    ret = max(ret,minima(my,my,lx,rx));
    ret = max(ret,minima(ly,my-1,lx,midx[my]));
    ret = max(ret,minima(my+1,ry,midx[my],rx));
    return ret;
}

vector<pl> f(vector<pl> v){
    int V = v.size();

    sort(all(v), [](const pl &L, const pl &R){
        if(L.fi == R.fi) return L.se>R.se;
        return L.fi<R.fi;
    });

    vector<pl> ret;
    ret.pb(v[0]);
    for(int i=1; i<V; ++i)if(ret.back().se < v[i].se) ret.pb(v[i]);
    // dbg(ret);
    return ret;
}

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    rep(i,n){
        ll p,d;
        scanf(" %lld %lld", &p, &d);
        pd.pb({d,-p});
    }
    rep(i,m){
        ll p,d;
        scanf(" %lld %lld", &p, &d);
        cm.pb({-d,p});
    }

    pd = f(pd);
    cm = f(cm);

    n = pd.size();
    m = cm.size();

    rep(i,n) pd[i].se *= -1;
    rep(i,m) cm[i].fi *= -1;
    reverse(all(cm));

    printf("%lld\n", minima(0, n-1, 0, m-1));
    return 0;
}
