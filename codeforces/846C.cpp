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

const int N = 5010;
const ll INF = LLONG_MAX/3;
int n;
ll a[N],sa[N]={};

inline ll s(int l, int r)
{
    ll x = 0;
    if(l!=0) x = sa[l-1];
    ll y = 0;
    if(r!=0) y = sa[r-1];

    return y-x;
}

int main()
{
    cin >>n;
    rep(i,n) cin >>a[i];

    sa[0] = a[0];
    for(int i=1; i<n; ++i) sa[i] = sa[i-1]+a[i];

    ll res = -INF;
    int d[3]={};
    // delim1を全探索
    rep(i,n+1)
    {
        ll s0 = -INF;
        int d0 = -1;
        rep(j,i+1)
        {
            ll tt = s(0,j)-s(j,i);
            if(s0<tt)
            {
                s0 = tt;
                d0 = j;
            }
        }

        ll s2 = -INF;
        int d2 = -1;
        for(int j=i; j<=n; ++j)
        {
            ll tt = s(i,j)-s(j,n);
            if(s2<tt)
            {
                s2 = tt;
                d2 = j;
            }
        }

        ll t = s0+s2;
        if(res<t)
        {
            res = t;
            d[0] = d0;
            d[1] = i;
            d[2] = d2;
        }
    }

    rep(i,3) printf("%d%c", d[i],(i==2?'\n':' '));
    return 0;
}
