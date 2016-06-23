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
    int n;
    cin >>n;

    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);
    sort(all(a));

    int ans=1;
    rep(i,n)
    {
        if(a[i]>=ans) ++ans;
    }

    cout << ans << endl;
    return 0;
}
