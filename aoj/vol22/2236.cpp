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

const ll INF = 100000000000LL;
ll mul(ll x, ll y)
{
    if(x==0 || y==0) return 0;

    // x*y>INF
    if(x>INF/y) return INF;
    return x*y;
}

ll solve()
{
    int n;
    cin >>n;

    ll H,A,D,S;
    cin >>H >>A >>D >>S;

    vector<ll> h(n),a(n),d(n),s(n);
    rep(i,n) cin >>h[i] >>a[i] >>d[i] >>s[i];

    ll ret = 0;

    vector<pl> e;
    rep(i,n)
    {
        ll damage = max(0LL, a[i]-D);
        ll dd = max(0LL, A-d[i]);

        if(damage>0 && dd==0) return -1;

        if(dd>0)
        {
            ll turn = (h[i]+dd-1)/dd;
            if(S>s[i]) ret -= damage;

            e.pb({damage,turn});
        }
    }

    sort(all(e),[](const pl &l, const pl &r){ return l.fi*r.se > l.se*r.fi; });

    ll T = 0;
    rep(i,e.size())
    {
        T += e[i].se;
        ret += mul(e[i].fi,T);

        if(ret >= H) return -1;
    }

    return ret;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
