#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

void solve(int h, int w)
{
    if(h>w) swap(h,w);
    int g=__gcd(h,w);
    h/=g;
    w/=g;

    if(h==w)
    {
        printf("1 0\n");
        return;
    }

    // h!=w
    ll a=1, b=1;
    if(h%2==1 && w%2==1)
    {
        ll mul=(ll)h*w;
        b=mul/2;
        a=mul-b;
    }

    printf("%lld %lld\n", a,b);
}

int main()
{
    int T;
    scanf(" %d", &T);
    while(T--)
    {
        int h,w;
        scanf(" %d %d", &h, &w);
        solve(h,w);
    }
    return 0;
}
