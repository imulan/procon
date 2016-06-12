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
    int r0,w0,c,r;
    while(cin >>r0 >>w0 >>c >>r,r0)
    {
        int ans=0;
        while(1)
        {
            double p=(double)(r0+ans*r)/c-w0;
            if(p>=0) break;
            ++ans;
        }

        cout << ans << endl;
    }
    return 0;
}
