#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

ll fact(ll n)
{
    ll ret=1;
    for(ll i=2; i<=n; ++i) ret*=i;
    return ret;
}

int main()
{
    string s;
    cin >>s;

    int ct[26]={0};
    rep(i,s.size()) ++ct[s[i]-'a'];

    int odd=0;
    int o_idx=-1;
    rep(i,26)
    {
        if(ct[i]%2==1)
        {
            ++odd;
            o_idx=i;
        }
    }

    if(odd>1) printf("0\n");
    else
    {
        int S=s.size();
        if(odd==1)
        {
            --ct[o_idx];
            --S;
        }

        ll ans=fact(S/2);
        rep(i,26) ans/=fact(ct[i]/2);

        printf("%lld\n", ans);
    }
    return 0;
}
