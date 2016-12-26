#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,ll> P;

P ans(0,0);

inline ll cube(ll x)
{
    return x*x*x;
}

void rec(ll m, int depth, ll sum)
{
    if(m==0)
    {
        ans = max(ans,P(depth,sum));
        return;
    }

    ll a=1;
    while(cube(a+1)<=m) ++a;

    rec(m-cube(a), depth+1, sum+cube(a));
    if(a-1>0) rec(cube(a)-1-cube(a-1), depth+1, sum+cube(a-1));
}

int main()
{
    ll m;
    cin >>m;
    rec(m,0,0);
    printf("%d %lld\n", ans.fi, ans.se);
    return 0;
}
