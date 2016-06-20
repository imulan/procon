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

int main()
{
    ll n;
    cin >>n;

    ll def=0;
    ll t=n;
    while(t>0)
    {
        def+=t;
        t/=2;
    }

    cout << 2*n-def << endl;
    return 0;
}
