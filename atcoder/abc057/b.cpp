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
    int n,m;
    cin >>n >>m;

    vector<int> a(n),b(n),c(m),d(m);
    rep(i,n) cin >>a[i] >>b[i];
    rep(i,m) cin >>c[i] >>d[i];

    rep(i,n)
    {
        int ans = -1;
        int nearest = 1234567890;

        rep(j,m)
        {
            int D = abs(a[i]-c[j]) + abs(b[i]-d[j]);
            if(nearest > D)
            {
                ans = j+1;
                nearest = D;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
