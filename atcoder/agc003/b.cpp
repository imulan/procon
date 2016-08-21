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
    rep(i,n) scanf(" %d", &a[i]);

    ll ans=0;
    rep(i,n)
    {
        //i同士
        ans += a[i]/2;
        a[i] -= (a[i]/2)*2;
        if(i<n-1)
        {
            //iとi+1
            if(a[i]==1 && a[i+1]>0)
            {
                ans+=1;
                --a[i];
                --a[i+1];
            }
        }
    }
    ans+=a[n-1]/2;

    cout << ans << endl;
    return 0;
}
