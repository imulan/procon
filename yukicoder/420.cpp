#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int f(ll n)
{
    if(n==0) return 0;
    else return f(n/2) + n%2;
}

int main()
{
    int x;
    cin >>x;

    if(x>31)
    {
        printf("0 0\n");
        return 0;
    }

    // 組み合わせ
    ll c[32][32];
    c[0][0]=1;
    for(int i=1; i<32; ++i)
    {
        c[i][0]=c[i][i]=1;
        for(int j=1; j<i; ++j) c[i][j] = c[i-1][j-1]+c[i-1][j];
    }

    ll ans=0;
    if(x>0)
    {
        rep(i,31) ans+=(1LL<<i)*c[30][x-1];
    }

    printf("%lld %lld\n", c[31][x], ans);
    return 0;
}
