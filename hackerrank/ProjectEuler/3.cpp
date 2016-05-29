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

const int N=1000000;

ll solve(ll x)
{
    ll ans=0;
    for(ll i=2; i*i<=x; ++i)
    {
        if(x%i==0)
        {
            ans=max(ans,i);
            while(x%i==0) x/=i;
        }
    }

    if(x>1) ans=max(ans,x);
    return ans;
}

int main()
{
    int T;
    cin >>T;
    rep(t,T)
    {
        ll n;
        cin >>n;

        cout << solve(n) << endl;
    }
    return 0;
}
