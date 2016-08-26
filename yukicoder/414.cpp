#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

ll div(ll n)
{
    for(ll i=2; i*i<=n; ++i)
    {
        if(n%i==0) return i;
    }

    return 1;
}

int main()
{
    ll m;
    cin >>m;

    ll x=div(m);
    cout << x << " " << m/x << endl;
    return 0;
}
