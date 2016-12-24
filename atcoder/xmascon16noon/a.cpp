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

    ll ans=0;
    int idx=0;
    rep(i,17)
    {
        if(n>>i&1)
        {
            cout << "? " << idx << " " << idx+(1<<i) << endl;

            ll val;
            cin >>val;

            ans+=val;
            idx+=1<<i;
        }
    }

    cout << "! " << ans << endl;
    return 0;
}
