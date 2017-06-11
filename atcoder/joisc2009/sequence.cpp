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

const int c[25] = {0, 1, 3, 7, 15, 21, 63, 127, 63, 73, 889, 1533, 3255, 7905, 11811, 32767, 255, 273, 253921, 413385, 761763, 5461, 4194303, 2088705, 2097151};

ll calc(int m, ll x, const vector<int> &a)
{
    ll e = 0;
    rep(i,c[m]) e += a[i];

    ll t = x/c[m];
    ll v = 0;
    rep(i,x%c[m]) v += a[i];

    return e*t + v;
}

int main()
{
    int m;
    ll p,q;
    cin >>m >>p >>q;

    vector<int> a(c[m]);
    rep(i,m)
    {
        cin >>a[i];
        a[i]%=2;
    }
    for(int i=m; i<c[m]; ++i) a[i] = (a[i-1]+a[i-m])%2;

    cout << calc(m,q,a) - calc(m,p-1,a) << endl;
    return 0;
}
