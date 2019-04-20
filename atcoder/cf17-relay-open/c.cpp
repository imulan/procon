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
    int n,k;
    cin >>n >>k;
    vector<ll> w(n),d(n);
    rep(i,n) cin >>w[i] >>d[i];

    ll l=0, r=LLONG_MAX/3;
    while(r-l>1)
    {
        ll m = (l+r)/2;
        ll ct = 0;
        rep(i,n)
        {
            ll v = m-w[i];
            if(v<0) continue;

            ll p = v/d[i];
            ct += p+1;
        }

        if(ct<k) l = m;
        else r = m;
    }

    cout << r << endl;
    return 0;
}
