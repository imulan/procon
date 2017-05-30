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
    int n;
    cin >>n;
    vector<int> d(n);
    rep(i,n) cin >>d[i];

    ll ans = 0;
    int i=0;
    while(i<n)
    {
        if(d[i]==0)
        {
            ++i;
            continue;
        }

        int st=i;
        while(i<n && d[i]!=0) ++i;

        ll L=i-st;
        ans += L*(L+1)/2;
    }
    cout << ans << endl;
    return 0;
}
