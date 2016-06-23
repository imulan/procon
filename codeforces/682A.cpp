#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int main()
{
    int n,m;
    cin >>n >>m;

    ll x[5],y[5];

    rep(i,5) x[i]=n/5;
    for(int i=1; i<=n%5; ++i) ++x[i];
    rep(i,5) y[i]=m/5;
    for(int i=1; i<=m%5; ++i) ++y[i];

    ll ans=0;
    rep(i,5)
    {
        //cout<<" "<<x[i]<<" * "<<y[(5-i)%5]<<endl;
        ans+=x[i]*y[(5-i)%5];
    }
    cout << ans << endl;
    return 0;
}
