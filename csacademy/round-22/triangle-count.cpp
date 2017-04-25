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
    vector<int> a(n);
    rep(i,n) cin >>a[i];
    sort(all(a));

    int ans=0;
    rep(k,n)rep(j,k)rep(i,j)
    {
        if(a[i]+a[j]>a[k]) ++ans;
    }
    cout << ans << endl;
    return 0;
}
