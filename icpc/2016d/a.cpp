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

#define dbg(x) cout<<#x"="<<x<<endl
#define rep1(i,n) for(int (i)=1;(i)<=(int)(n);++(i))

int main()
{
    int n;
    while(cin >>n,n)
    {
        vector<int> a(n);
        rep(i,n) scanf(" %d", &a[i]);

        int ans=10000000;
        rep(i,n)rep(j,i) ans=min(ans,abs(a[i]-a[j]));

        cout << ans << endl;
    }
    return 0;
}
