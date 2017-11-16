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

int ds(ll n)
{
    int r = 0;
    while(n>0)
    {
        r += n%10;
        n/=10;
    }
    return r;
}

ll f(ll n)
{
    return n-ds(n);
}

int main()
{
    ll n,s;
    cin >>n >>s;

    ll l=0, r=n+1;
    while(r-l>1)
    {
        ll m = (l+r)/2;
        if(f(m)>=s) r=m;
        else l=m;
    }
    cout << n-l << endl;
    return 0;
}
