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

ll solve()
{
    int n,d;
    cin >>n >>d;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    ll s = 0;
    rep(i,n) s+=a[i];

    if(s%n!=0) return -1;

    ll av = s/n;
    ll ans = 0;

    rep(i,n)if(i+d<n)
    {
        if(a[i]>av)
        {
            ll x = a[i]-av;
            ans += x;
            a[i] -= x;
            a[i+d] += x;
        }
        else if(a[i]<av)
        {
            ll x = av-a[i];
            ans += x;
            a[i] += x;
            a[i+d] -= x;
        }
    }

    rep(i,n)if(a[i]!=av) return -1;
    return ans;
}

int main()
{
    int T;
    cin >>T;
    while(T--) cout << solve() << endl;
    return 0;
}
