#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int solve()
{
    int n;
    cin >>n;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    rep(i,n)
    {
        a[i]=-a[i];

        ll sum=0;
        rep(j,n) sum+=a[j];
        if(sum==0) return i+1;

        a[i]=-a[i];
    }

    return -1;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
