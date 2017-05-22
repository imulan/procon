#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

#include <message.h>
#include "todd_and_steven.h"

const ll mod=1e9+7;

int main()
{
    ll N = NumberOfNodes();
    ll ID = MyNodeId();

    int T = GetToddLength();
    int S = GetStevenLength();

    if(ID==0)
    {
        int L=T+S;

        vector<ll> v(L);
        rep(i,T) v[i] = GetToddValue(i);
        rep(i,S) v[T+i] = GetStevenValue(i);

        sort(all(v));

        ll ans = 0;
        rep(i,L)
        {
            ans += v[i]^i;
            ans %= mod;
        }
        cout << ans << endl;
    }

    return 0;
}
