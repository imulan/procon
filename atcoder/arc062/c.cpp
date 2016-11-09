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
    scanf(" %d", &n);
    vector<int> t(n),a(n);
    rep(i,n) scanf(" %d %d", &t[i], &a[i]);

    ll x=t[0], y=a[0];
    for(int i=1; i<n; ++i)
    {
        ll p=x/t[i], q=y/a[i];
        if(x%t[i]!=0) ++p;
        if(y%a[i]!=0) ++q;

        ll k=max(p,q);
        x=k*t[i];
        y=k*a[i];
    }
    cout << x+y << endl;
    return 0;
}
