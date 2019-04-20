#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define pb push_bacK

using ll = long long;

int main()
{
    ll n,L,K;
    cin >>n >>L >>K;
    vector<ll> a(n),d(n);
    rep(i,n) cin >>a[i] >>d[i];

    vector<ll> s(n);
    rep(i,n) s[i] = L*(2*a[i]+(L-1)*d[i])/2;

    vector<ll> ims(n);
    ims[0] = s[0];
    for(int i=1; i<n; ++i) ims[i] = ims[i-1]+s[i];

    ll ans = 0;
    rep(i,n)
    {
        int st = i*L;
        int ed = st+K-1;
        if(ed<n*l)
        {
            int num = K/L;
            ll t = ims[i+num] - ims[i];
            
        }
    }


    cout << ans << endl;
}
