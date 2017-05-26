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
    int n,m,d;
    cin >>n >>m >>d;
    vector<string> s(n);
    rep(i,n) cin >>s[i];

    int ans = 0;

    // 縦
    rep(i,n-d+1)rep(j,m)
    {
        int ct=0;
        rep(y,d) ct+=(s[i+y][j]=='#');
        ans += (ct==0);
    }

    // 横
    rep(i,n)rep(j,m-d+1)
    {
        int ct=0;
        rep(x,d) ct+=(s[i][j+x]=='#');
        ans += (ct==0);
    }

    cout << ans << endl;
    return 0;
}
