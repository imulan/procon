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

int a[2020][2020];

int main()
{
    ll n;
    cin >>n;

    ll U = n*(n-1)*(n-2)/6;
    ll sub = 0;

    int b = 0;
    rep(i,n)for(int j=i+1; j<n; ++j)
    {
        a[i][j] = b;
        a[j][i] = !b;
        b = !b;
    }

    rep(i,n)
    {
        ll in = 0, out = 0;
        rep(j,n)if(i!=j)
        {
            if(a[i][j]==1) ++in;
            else ++out;
        }

        sub += in*(in-1)/2;
        sub += out*(out-1)/2;
    }
    sub/=2;

    printf("%lld\n", U-sub);
    rep(i,n)for(int j=i+1; j<n; ++j) printf("%d", a[i][j]);
    printf("\n");
    return 0;
}
