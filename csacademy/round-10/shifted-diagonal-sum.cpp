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
    int n;
    cin >>n;
    vector<vector<int>> a(n,vector<int>(n));
    rep(i,n)rep(j,n) cin >>a[i][j];

    int ans = -INT_MAX;
    rep(i,n)
    {
        int t=0;
        rep(j,n) t+=a[(i+j)%n][j];
        ans = max(ans,t);
    }
    cout << ans << endl;
    return 0;
}
