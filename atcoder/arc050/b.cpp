#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int main()
{
    ll r,b,x,y;
    cin >>r >>b >>x >>y;

    ll L=0, R=1000000000000000000LL;

    while(R-L>1)
    {
        ll med=(L+R)/2;
        bool ok=true;

        ll p=r-med,q=b-med;

        if(p<0 || q<0) ok=false;
        else
        {
            if(p/(x-1)+q/(y-1)<med) ok=false;
        }

        if(ok) L=med;
        else R=med;
    }

    cout << L << endl;
    return 0;
}
