#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    int n;
    ll k;
    scanf(" %d %lld", &n, &k);
    vector<ll> a(n),b(n);
    rep(i,n) scanf(" %lld", &a[i]);
    rep(i,n) scanf(" %lld", &b[i]);
    sort(all(a));
    sort(all(b));

    ll l=0, r=1000000000000000000LL;

    while(r-l>1)
    {
        ll med=(l+r)/2;
        ll ct=0;
        rep(i,n) ct+=upper_bound(all(b), med/a[i])-b.begin();

        if(ct<k) l=med;
        else r=med;
    }

    cout << r << endl;
    return 0;
}
