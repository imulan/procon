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
    int n,k;
    cin >>n >>k;
    vector<int> a(n);
    rep(i,n) cin >>a[i];
    sort(all(a));

    int ans=0;
    rep(i,k) ans += a[i];
    cout << ans << endl;
    return 0;
}
