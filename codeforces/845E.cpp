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

using pl = pair<ll,ll>;

pl calc(ll X, ll Y, const vector<ll> &x, const vector<ll> &y, ll m)
{
    int k = x.size();

    ll lx=X,rx=1;
    vector<ll> cx;
    cx.pb(1);
    cx.pb(X);
    rep(i,k)
    {
        for(ll j:vector<ll>({x[i]-m-1,x[i]-m,x[i]+m,x[i]+m+1}))
        {
            ll nx = j;
            if(nx<1) nx=1;
            if(nx>X) nx=X;
            cx.pb(nx);
        }
    }
    sort(all(cx));
    cx.erase(unique(all(cx)),cx.end());

    // このx座標が全て覆われているかcheck
    for(ll i:cx)
    {
        vector<pl> range;
        rep(j,k)
        {
            ll LX=max(1LL,x[j]-m), RX=min(X,x[j]+m);
            ll LY=max(1LL,y[j]-m), RY=min(Y,y[j]+m);
            if(LX<=i && i<=RX) range.pb({RY,LY});
        }
        sort(all(range));

        ll now=1;
        for(const auto &p:range)
        {
            ll L=p.se, R=p.fi;
            if(L<=now && now<=R) now=R+1;
        }

        if(now!=Y+1)
        {
            lx = min(lx,i);
            rx = max(rx,i);
        }
    }

    return {lx,rx};
}

int main()
{
    ll X,Y;
    int k;
    cin >>X >>Y >>k;
    vector<ll> x(k),y(k);
    rep(i,k) cin >>x[i] >>y[i];

    ll ng=-1,ok=max(X,Y);
    while(ok-ng>1)
    {
        ll m=(ng+ok)/2;

        pl range_x = calc(X,Y,x,y,m);
        pl range_y = calc(Y,X,y,x,m);

        ll need=0;
        need = max(need,(range_x.se - range_x.fi + 1)/2);
        need = max(need,(range_y.se - range_y.fi + 1)/2);
        // printf(" m: %lld, need %lld\n", m,need);
        if(need<=m) ok=m;
        else ng=m;
    }
    cout << ok << endl;
    return 0;
}
