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
using P = pair<ll,pi>;

int main()
{
    int n;
    cin >>n;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    int m;
    cin >>m;
    vector<ll> b(m);
    rep(i,m) cin >>b[i];

    ll sa = accumulate(all(a),0LL), sb = accumulate(all(b),0LL);

    vector<pi> ans;
    ll val = abs(sa - sb);

    vector<P> v;
    rep(i,n)rep(j,m) v.pb(P(-a[i]+b[j],pi(i,j)));
    sort(all(v));
    int V = v.size();

    rep(i,n)rep(j,m)
    {
        sa = sa - a[i] + b[j];
        sb = sb - b[j] + a[i];

        if(abs(sa-sb)<val)
        {
            val = abs(sa-sb);
            ans.resize(0);
            ans.pb({i,j});
        }

        ll d = sa-sb;
        int idx = lower_bound(all(v),P(-d/2,pi(-1,-1)))-v.begin();
        for(int k=-1; k<=1; ++k)
        {
            int vv = idx+k;
            if(0<=vv && vv<V && v[vv].se.fi!=i && v[vv].se.se!=j)
            {
                sa += v[vv].fi;
                sb -= v[vv].fi;

                if(abs(sa-sb)<val)
                {
                    val = abs(sa-sb);
                    ans.resize(0);
                    ans.pb({i,j});
                    ans.pb(v[vv].se);
                }

                sa -= v[vv].fi;
                sb += v[vv].fi;
            }
        }

        sa = sa + a[i] - b[j];
        sb = sb + b[j] - a[i];
    }

    cout << val << endl;
    cout << ans.size() << endl;
    rep(i,ans.size()) cout << ans[i].fi+1 << " " << ans[i].se+1 << endl;
    return 0;
}
