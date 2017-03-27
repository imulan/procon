#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int F(ll A, ll B)
{
    int a=0,b=0;
    while(A>0){A/=10;++a;}
    while(B>0){B/=10;++b;}
    return max(a,b);
}

int main()
{
    ll n;
    cin >>n;

    int ans=12345678;
    for(ll i=1; i*i<=n; ++i)if(n%i==0)
    {
        ans = min(ans, F(i,n/i));
    }

    cout << ans << endl;
    return 0;
}
