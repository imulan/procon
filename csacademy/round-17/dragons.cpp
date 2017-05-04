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
    int n,m,a[50][50];
    cin >>n >>m;
    rep(i,n)rep(j,m) cin >>a[i][j];

    int ans=0;
    rep(i,n)rep(j,m)if(a[i][j]==0)
    {
        int t=12345;
        rep(y,n)rep(x,m)if(a[y][x]==1)
        {
            t = min(t, max(abs(y-i),abs(x-j)));
        }
        ans = max(ans,t);
    }

    cout << ans << endl;
    return 0;
}
