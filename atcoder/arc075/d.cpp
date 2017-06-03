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
    ll a,b;
    cin >>n >>a >>b;

    vector<ll> h(n);
    rep(i,n) cin >>h[i];

    ll l=0, r=1000000000;
    while(r-l>1)
    {
        ll m = (l+r)/2;
        ll ct=0;
        rep(i,n)
        {
            ll p = h[i]-b*m;
            if(p<=0) continue;

            ll q = a-b;
            p = (p+q-1)/q;
            ct += p;
        }

        if(ct<=m) r=m;
        else l=m;
    }

    cout << r << endl;
    return 0;
}
