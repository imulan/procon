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

    int z=0;
    vector<int> a(n);
    rep(i,n)
    {
        cin >>a[i];
        z += !a[i];
    }

    int ans=0;
    rep(i,n)
    {
        if(a[i]) ans+=z;
        else --z;
    }

    cout << ans << endl;
    return 0;
}
