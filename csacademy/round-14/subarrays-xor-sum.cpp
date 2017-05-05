#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll mod = 1e9+7;

int main()
{
    int n,A,B;
    cin >>n >>A >>B;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    ll ans = 0;
    rep(b,30)
    {
        vector<int> x(n);
        rep(i,n) x[i] = (a[i]>>b&1);

        vector<int> pre(n+1);
        rep(i,n) pre[i+1] = pre[i]^x[i];

        int l=-B, r=-A;
        ll ct[2]={};
        rep(i,n)
        {
            if(-1<=r && r<n) ++ct[pre[r+1]];
            ++r;

            (ans += ct[!pre[i+1]]*(1<<b))%=mod;;

            if(-1<=l && l<n) --ct[pre[l+1]];
            ++l;
        }
    }

    cout << ans << endl;
    return 0;
}
