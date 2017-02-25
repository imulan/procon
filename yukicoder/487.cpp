#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int solve(int m)
{
    int ret = 1;
    rep(i,2017)
    {
        ret*=(2017*2017)%m;
        ret%=m;
    }
    return (ret+2017)%m;
}

int main()
{
    int m;
    cin >>m;
    cout << solve(m) << endl;
    return 0;
}
