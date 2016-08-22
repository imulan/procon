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
    cin >>n;
    vector<ll> x(n), y(n);
    rep(i,n) scanf(" %lld", &x[i]);
    rep(i,n) scanf(" %lld", &y[i]);
    sort(all(x));
    sort(all(y));

    ll sumx=0,sumy=0;
    rep(i,n)
    {
        sumx+=x[i];
        sumy+=y[i];
    }

    ll ans=0;
    if(sumx!=sumy) ans=-1;
    else
    {
        rep(i,n)
        {
            ll diff=x[i]-y[i];
            if(diff>0) ans+=diff;
        }
    }

    cout << ans << endl;
    return 0;
}
