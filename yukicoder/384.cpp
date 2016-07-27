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
    ll h,w,n,k;
    cin >>h >>w >>n >>k;

    ll e=(h-1)+(w-1);
    // cout << e%n+1 << endl;

    string ans="NO";
    if(e%n+1==k) ans="YES";
    cout << ans << endl;
    return 0;
}
