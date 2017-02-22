#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

ll sqsum(ll n)
{
    return n*(n+1)/2;
}

bool ok(int n, int m, int k, int x)
{
    ll need = 0;

    // 左側
    int b = k;
    if(b<x) need += sqsum(x) - sqsum(x-b);
    else need += sqsum(x) + b-x;

    // 右側
    b = n-k+1;
    if(b<x) need += sqsum(x) - sqsum(x-b);
    else need += sqsum(x) + b-x;

    need -= x;

    return need <= m;
}

int main()
{
    int n,m,k;
    cin >>n >>m >>k;

    int l=1, r=m+1;
    while(r-l>1)
    {
        int mid = (l+r)/2;
        if(ok(n,m,k,mid)) l=mid;
        else r=mid;
    }
    cout << l << endl;
    return 0;
}
