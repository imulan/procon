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
    ll a,b,c;
    cin >>a >>b >>c;

    ll ans=0;
    if(a%2==1 && b%2==1 && c%2==1) ans=min({a*b,b*c,c*a});

    cout << ans << endl;
    return 0;
}
