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
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    int ans=123456789;

    for(int i=-100; i<=100; ++i)
    {
        int t=0;
        rep(j,n) t+=(a[j]-i)*(a[j]-i);
        ans=min(ans,t);
    }

    cout << ans << endl;
    return 0;
}
