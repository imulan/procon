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

const ll MOD=1e9+7;

ll mod_pow(ll x, ll n, ll mod)
{
    ll pw[60];
    pw[0]=x%mod;
    for(int i=1; i<60; ++i) pw[i]=(pw[i-1]*pw[i-1])%mod;

    ll ret=1;
    rep(i,60) if(n>>i&1) (ret*=pw[i])%=mod;
    return ret;
}


int main()
{
    string s;
    cin >>s;

    int sp[2];
    int SP=0;
    rep(i,s.size())
    {
        if(s[i]=='^') sp[SP++]=i;
    }

    ll a,b,c;
    a=atoll(s.substr(0,sp[0]).c_str());
    b=atoll(s.substr(sp[0]+1,sp[1]-sp[0]-1).c_str());
    c=atoll(s.substr(sp[1]+1).c_str());
    //printf("%lld %lld %lld\n", a,b,c);

    ll x,y;
    if(a%MOD==0) x=y=0;
    else
    {
        x=mod_pow(a,b,MOD);
        x=mod_pow(x,c,MOD);

        ll Y=mod_pow(b,c,MOD-1);
        y=mod_pow(a,Y,MOD);
    }
    cout << x << " " << y << endl;
    return 0;
}
