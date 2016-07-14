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

const ll mod=1e9+7;

ll mod_inv(ll x)
{
    ll pw[32];
    pw[0]=x;
    for(int i=1; i<32; ++i) pw[i]=(pw[i-1]*pw[i-1])%mod;

    ll ret=1;
    ll p=mod-2;
    rep(i,32) if(p>>i&1) (ret*=pw[i])%=mod;
    return ret;
}

ll fact[2000000]={0};

int main()
{
    fact[0]=1;
    for(ll i=1; i<2000000; ++i) fact[i]=(fact[i-1]*i)%mod;

    int TIMES;
    cin >>TIMES;
    rep(T,TIMES)
    {
        string s;
        cin >>s;

        ll a,b;
        for(int i=2; i<s.size(); ++i)
        {
            if(s[i]==',')
            {
                a=atoll(s.substr(2,i-2).c_str());
                b=atoll(s.substr(i+1,s.size()-i-1).c_str());
                break;
            }
        }

        //printf("a=%lld, b=%lld\n", a,b);

        ll ans=1;
        if(s[0]=='C')
        {
            if(a<b) ans=0;
            else
            {
                ans=fact[a];
                (ans*=mod_inv(fact[b]))%=mod;
                (ans*=mod_inv(fact[a-b]))%=mod;
            }
        }
        else if(s[0]=='P')
        {
            if(a<b) ans=0;
            else
            {
                ans=fact[a];
                (ans*=mod_inv(fact[a-b]))%=mod;
            }
        }
        else
        {
            if(a==0 && b==0) ans=1;
            else
            {
                ans=fact[a+b-1];
                (ans*=mod_inv(fact[b]))%=mod;
                (ans*=mod_inv(fact[a-1]))%=mod;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
