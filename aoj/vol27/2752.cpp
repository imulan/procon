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
    ll n;
    cin >>n;

    int ans=0;
    ll now=1;
    while(now<=n)
    {
        now*=2;
        ++ans;
    }
    cout << ans << endl;
    return 0;
}
