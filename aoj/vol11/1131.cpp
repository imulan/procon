#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

ll p,q,a;
int n;

inline bool same(ll num, ll den)
{
    return num*q==den*p;
}

ll dfs(ll num, ll den, int dep, ll b)
{
    if(same(num,den)) return 1;

    if(dep==n) return 0;

    // printf(" now: %lld %lld %d %lld\n", num,den,dep,b);
    ll x=q*den,y=p*den-q*num;
    // printf("x=%lld y=%lld\n", x,y);

    ll l=x/y;
    if(x%y!=0) ++l;
    l=max(l,b);
    ll r=a/den;

    ll ret=0;
    for(ll i=l; i<=r; ++i) ret+=dfs(num*i+den, i*den, dep+1, i);
    return ret;
}

int main()
{
    while(cin >>p >>q >>a >>n,p) printf("%lld\n", dfs(0,1,0,1));
    return 0;
}
