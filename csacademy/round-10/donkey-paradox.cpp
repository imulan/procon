#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    int n,m;
    cin >>n >>m;
    int x[2],y[2];
    rep(i,2) cin >>y[i] >>x[i];

    int ans=0;
    for(int Y=1; Y<=n; ++Y)for(int X=1; X<=m; ++X)
    {
        int d[2];
        rep(i,2) d[i]=abs(x[i]-X)+abs(y[i]-Y);
        ans += (d[0]==d[1]);
    }
    cout << ans << endl;
    return 0;
}
