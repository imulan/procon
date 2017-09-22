#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)n; ++i)

using ll = long long;

int main()
{
    ll n;
    cin >>n;

    ll ans = 0;
    if(n<=52)
    {
        rep(i,n)
        {
            if(i%2==0) ans += 1;
            else ans += 2;
        }
    }
    else
    {
        ll add = 1;
        ll a = 26;
        while(1)
        {
            if(n-a<=0)
            {
                ans += add*n;
                break;
            }

            ans += add*a;
            n -= a;
            ++add;
            a*=26;
        }
    }

    cout << ans << endl;
    return 0;
}
