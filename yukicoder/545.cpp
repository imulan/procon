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

int main()
{
    int n;
    cin >>n;
    vector<ll> a(n),b(n);
    rep(i,n) cin >>a[i] >>b[i];

    int X = n/2, Y = n-X;

    vector<ll> x;
    rep(mask,1<<X)
    {
        ll v = 0;
        rep(i,X)
        {
            if(mask>>i&1) v += a[i];
            else v -= b[i];
        }
        x.pb(v);
    }

    sort(all(x));

    ll ans = LLONG_MAX;
    rep(mask,1<<Y)
    {
        ll v = 0;
        rep(i,Y)
        {
            if(mask>>i&1) v += a[X+i];
            else v -= b[X+i];
        }

        int idx = lower_bound(all(x),-v)-x.begin();

        for(int i=-1; i<=1; ++i)
        {
            int j=idx+i;
            if(0<=j && j<x.size()) ans = min(ans,abs(v+x[j]));
        }
    }

    cout << ans << endl;
    return 0;
}
