#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    ll n,m,x,y;
    cin >>n >>m >>x >>y;

    ll l=0,r=n+1;
    while(r-l>1)
    {
        ll mid=(l+r)/2;
        ll candy = m+(n-mid)*y;
        if(candy>=mid*x) l=mid;
        else r=mid;
    }
    cout << l << endl;
    return 0;
}
