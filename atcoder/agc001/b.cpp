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
    ll n,x;
    cin >>n >>x;

    ll ans=x;

    ll len=n;
    ll y=len-x;

    while(1)
    {
        //printf("len=%lld y=%lld\n",len,y);
        ll num=len/y;

        if(len%y==0)
        {
            ans+=(num-1)*2*y;
            break;
        }
        else
        {
            ans+=(1+(num-1)*2)*y;
            ll tlen=len;
            len=y;
            y=tlen-y*num;

            ans+=y;
        }
    }

    cout << ans << endl;
    return 0;
}
