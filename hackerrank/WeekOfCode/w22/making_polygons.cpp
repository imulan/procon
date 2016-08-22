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
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    int ans=0;
    if(n==1) ans=2;
    else
    {
        while(1)
        {
            sort(all(a), greater<int>());

            int sum=0;
            rep(i,a.size()) sum+=a[i];
            if(a[0]<sum-a[0]) break;

            int x=a[0]/2;
            int y=a[0]-x;

            vector<int> newa;
            newa.pb(x);
            newa.pb(y);
            for(int i=1; i<a.size(); ++i) newa.pb(a[i]);

            a=newa;
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
