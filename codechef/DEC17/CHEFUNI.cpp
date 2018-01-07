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

ll a,b,c;

ll f(ll y, ll z)
{
    if(y>z) swap(y,z);

    ll ret = y*b;
    z -= y;
    ret += z*a;

    return ret;
}

ll g(ll x, ll y, ll z)
{
    ll t = 0;
    if(x+y<z)
    {
        t = b*(x+y);
        z -= x+y;
        t += a*z;
    }
    else
    {
        ll sd = x+y+z;
        if(sd%2==0) t = b*(sd/2);
        else
        {
            t = b*(sd/2)+a;
            if(sd>=3)
            {
                sd-=3;
                t = min(t,b*(sd/2)+c);
            }
        }
    }
    return t;
}

ll solve()
{
    ll D[3];
    rep(i,3) cin >>D[i];
    sort(D,D+3);

    cin >>a >>b >>c;

    b = min(b,2*a);
    c = min({c,b+a,3*a});

    ll ans = LLONG_MAX;

    // 初手にCを積んでいく
    ll t = 0;
    ll d[3];
    rep(i,3) d[i]=D[i];

    ll k=d[0]/2;
    rep(i,3) d[i]-=2*k;
    t += k*min({2*c,3*b,6*a});

    // rep(i,3) printf(" d%d =%lld\n", i,d[i]);

    if(d[0]==1)
    {
        t += min({a+f(d[1],d[2]),b+f(d[1]-1,d[2]),b+f(d[1],d[2]-1),c+f(d[1]-1,d[2]-1)});
    }
    else t += f(d[1],d[2]);
    ans = min(ans,t);

    // 初手にBを積みまくる
    ans = min(ans,g(D[0],D[1],D[2]));

    // 限界までCを積んでからB
    ll x = D[0]+D[1]-D[2];
    if(x>0) ans = min(ans,g(D[0]-x,D[1]-x,D[2]-x)+x*c);

    return ans;
}

int main()
{
    int T;
    cin >>T;
    while(T--) printf("%lld\n", solve());
    return 0;
}
