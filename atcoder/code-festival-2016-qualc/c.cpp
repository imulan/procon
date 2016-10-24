#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll mod=1e9+7;

int main()
{
    int n;
    scanf(" %d", &n);
    vector<int> t(n),a(n);
    rep(i,n) scanf(" %d", &t[i]);
    rep(i,n) scanf(" %d", &a[i]);

    bool ok=(t[n-1]==a[0]);

    for(int i=1; i<n; ++i)
    {
        if(t[i-1]<t[i])
        {
            if(a[i]<t[i]) ok=false;
        }
    }
    for(int i=n-2; i>=0; --i)
    {
        if(a[i+1]<a[i])
        {
            if(t[i]<a[i]) ok=false;
        }
    }

    ll ans=0;
    if(ok)
    {
        ans=1;
        for(int i=1; i<n-1; ++i)
        {
            if(t[i]==t[i-1] && a[i]==a[i+1]) (ans*=min(t[i],a[i]))%=mod;
        }
    }
    cout << ans << endl;
    return 0;
}
