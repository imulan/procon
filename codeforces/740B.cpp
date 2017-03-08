#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    int n,m;
    cin >>n >>m;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    int ans=0;
    rep(i,m)
    {
        int l,r;
        cin >>l >>r;
        --l;
        --r;

        int t=0;
        for(int j=l; j<=r; ++j) t+=a[j];

        if(t>0) ans+=t;
    }
    cout << ans << endl;
    return 0;
}
