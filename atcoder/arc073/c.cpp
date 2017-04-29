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
    int n,T;
    cin >>n >>T;
    vector<int> t(n);
    rep(i,n) cin >>t[i];

    ll ans=T;
    for(int i=1; i<n; ++i)
    {
        if(t[i]-t[i-1]>T) ans+=T;
        else ans+=t[i]-t[i-1];
    }

    cout << ans << endl;
    return 0;
}
