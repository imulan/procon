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
    ll m[3];
    rep(i,3) cin >>m[i];

    ll ans=3000000000000000000LL;
    ll a[7][3]={
        {0,0,0},
        {0,0,1},
        {0,1,0},
        {1,0,0},
        {0,1,1},
        {1,0,1},
        {1,1,0}
    };

    rep(i,7)
    {
        bool minus=false;
        ll b[3];
        rep(j,3)
        {
            b[j]=m[j]-a[i][j];
            if(b[j]<0) minus=true;
        }

        if(minus) continue;

        ll max_b=max({b[0],b[1],b[2]});

        ll tmp=0;
        rep(j,3) tmp+=max_b-b[j];
        ans=min(ans,tmp);
    }

    cout << ans << endl;
    return 0;
}
