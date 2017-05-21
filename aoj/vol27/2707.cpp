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

    ll l=-1,r=1000000000000000000LL;
    while(r-l>1)
    {
        ll m = (l+r)/2;

        ll rem = m;
        rep(i,n-1)
        {
            ll sub = rem/k+1;
            rem-=sub;
        }

        if(rem>=0) r=m;
        else l=m;
    }

    cout << r << endl;
    return 0;
}
