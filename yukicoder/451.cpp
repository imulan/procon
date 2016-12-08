#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<ll,int> P;

const ll LIM=1000000000000000000LL;

vector<ll> solve(int n, vector<ll> &b)
{
    vector<ll> fail(1,-1);

    vector<P> a(n+2);
    a[1]=P(0LL,1);
    for(int i=2; i<=n+1; ++i)
    {
        ll val=a[i-1].fi-b[i-1];
        int x=a[i-1].se;
        if(i%2==0)
        {
            val*=-1;
            x*=-1;
        }

        if(abs(val)>LIM*2) return fail;
        a[i]=P(val,x);
    }

    // a[1]の値としてありうる範囲を調べる
    ll l=1, r=LIM;
    for(int i=2; i<=n+1; ++i)
    {
        if(a[i].se==-1)
        {
            l=max(l,a[i].fi-LIM);
            r=min(r,a[i].fi-1);
        }
        else
        {
            l=max(l,1-a[i].fi);
            r=min(r,LIM-a[i].fi);
        }
    }

    if(l>r) return fail;

    // 構成
    vector<ll> ret;
    ret.pb(n+1);
    ret.pb(l);
    for(int i=2; i<=n+1; ++i) ret.pb(a[i].fi + a[i].se*l);

    return ret;
}

int main()
{
    int n;
    scanf(" %d", &n);
    vector<ll> b(n+1);
    rep(i,n) scanf(" %lld", &b[i+1]);

    vector<ll> ans=solve(n,b);
    rep(i,ans.size()) printf("%lld\n", ans[i]);
    return 0;
}
