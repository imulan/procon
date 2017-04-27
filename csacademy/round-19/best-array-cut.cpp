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

    int s=0;
    vector<int> a(n);
    rep(i,n)
    {
        cin >>a[i];
        s+=a[i];
    }

    vector<int> l(n);
    l[0]=a[0];
    for(int i=1; i<n; ++i) l[i]=l[i-1]+a[i];

    int ans=INT_MAX;
    rep(i,n-1)
    {
        int r=s-l[i];
        ans=min(ans,abs(l[i]-r));
    }
    cout << ans << endl;
    return 0;
}
