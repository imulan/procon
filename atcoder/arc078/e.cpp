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

ll pw(ll x, ll n)
{
    ll ret = 1;
    rep(i,n) ret *= x;
    return ret;
}

bool query(ll n)
{
    cout << "? " << n << endl;
    cout << flush;

    char c;
    cin >>c;
    return c=='Y';

}

ll f1()
{
    for(int i=9; i>0; --i)
    {
        if(!query(pw(10,i)-1)) return pw(10,i);
    }
    return 1;
}

ll f2()
{
    int p = 1;
    while(query(pw(10,p))) ++p;

    ll l = pw(10,p-1), r = pw(10,p)-1;
    while(r-l>1)
    {
        ll m = (l+r)/2;
        if(query(m*10)) r=m;
        else l=m;

    }
    return r;
}

int main()
{
    ll ans;
    if(query(pw(10,10))) ans = f1();
    else ans = f2();

    cout << "! " << ans << endl;
    cout << flush;
    return 0;
}
