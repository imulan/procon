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
    int n,c;
    scanf(" %d %d", &n, &c);
    vector<int> t(n);
    rep(i,n) scanf(" %d", &t[i]);

    int ans=1;

    for(int i=1; i<n; ++i)
    {
        if(t[i]-t[i-1]>c) ans=1;
        else ++ans;
    }

    cout << ans << endl;
    return 0;
}
