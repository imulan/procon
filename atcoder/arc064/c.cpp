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
    int n,x;
    scanf(" %d %d", &n, &x);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    ll ans=0;
    for(int i=1; i<n; ++i)
    {
        if(a[i-1]+a[i]>x)
        {
            if(a[i-1]<x)
            {
                ans+=a[i]-(x-a[i-1]);
                a[i]=x-a[i-1];
            }
            else
            {
                ans+=a[i];
                a[i]=0;
            }
        }
    }
    for(int i=n-1; i>0; --i)
    {
        if(a[i-1]+a[i]>x)
        {
            if(a[i]<x)
            {
                ans+=a[i-1]-(x-a[i]);
                a[i-1]=x-a[i];
            }
            else
            {
                ans+=a[i-1];
                a[i-1]=0;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
