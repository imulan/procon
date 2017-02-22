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
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    int m,d;
    cin >>m >>d;

    --m;
    int ans = 1;
    int r = days[m]-(8-d);

    ans += (r+6)/7;

    cout << ans << endl;
    return 0;
}
