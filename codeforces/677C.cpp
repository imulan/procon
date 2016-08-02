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

int main()
{
    string s;
    cin >>s;

    ll ct[64]={0};
    rep(i,64)rep(j,64) ++ct[i&j];

    rep(i,64) std::cout << ct[i] << std::endl;

    ll ans=1;
    ll mod=1e9+7;
    rep(i,s.size())
    {
        if('0'<=s[i] && s[i]<='9')
        {
            ans*=ct[s[i]-'0'];
            ans%=mod;
        }
        else if('A'<=s[i] && s[i]<='Z')
        {
            ans*=ct[s[i]-'A'+10];
            ans%=mod;
        }
        else if('a'<=s[i] && s[i]<='z')
        {
            ans*=ct[s[i]-'a'+36];
            ans%=mod;
        }
        else if(s[i]=='-')
        {
            ans*=ct[62];
            ans%=mod;
        }
        else
        {
            ans*=ct[63];
            ans%=mod;
        }
    }

    cout << ans << endl;

    return 0;
}
