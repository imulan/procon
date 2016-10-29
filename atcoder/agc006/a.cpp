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
    int n;
    string s,t;
    cin >>n >>s >>t;

    int ans=2*n;
    for(int i=1; i<=n; ++i)
    {
        if(t.substr(0,i)==s.substr(n-i)) ans=min(ans,2*n-i);
    }

    cout << ans << endl;
    return 0;
}
