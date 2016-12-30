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
    int n,k;
    cin >>n >>k;

    int r = 240-k;
    int ans=0;

    for(int i=1; i<=n; ++i)
    {
        if(r-i*5<0) break;

        ++ans;
        r-=i*5;
    }

    cout << ans << endl;
    return 0;
}
