#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    int n,k;
    ll x;
    cin >>n >>k >>x;

    int plus=0, minus=0, zero=0;
    vector<ll> a(n);
    rep(i,n)
    {
        scanf(" %lld", &a[i]);
        if(a[i]>0) ++plus;
        else if(a[i]<0) ++minus;
        else ++zero;
    }

    

    return 0;
}
