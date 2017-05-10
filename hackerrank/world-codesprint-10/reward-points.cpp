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
    int ans=0;
    rep(i,3)
    {
        int m;
        cin >>m;
        m = min(10,m);
        ans += 10*m;
    }
    cout << ans << endl;
    return 0;
}
