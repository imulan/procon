#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll INF=123456789012LL;

int main()
{
    ll n,a,b,c;
    cin >>n >>a >>b >>c;

    ll ans = INF;
    rep(i,4)rep(j,4)rep(k,4)
    {
        if((n+i+2*j+3*k)%4==0) ans = min(ans,a*i+b*j+c*k);
    }

    cout << ans << endl;
    return 0;
}
