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
    int n,k;
    cin >>n >>k;
    vector<int> a(k);
    rep(i,k) cin >>a[i];

    int now=0;
    rep(i,k)
    {
        if(now+a[i]<=n) now+=a[i];
        else
        {
            int img = now+a[i];
            now = n-(img-n);
        }

        if(now==n) break;
    }
    return now;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
