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
    string s;
    ll n;
    cin >>s >>n;

    ll S=s.size();
    ll num=n/S;

    ll ct=0;
    rep(i,s.size())
    {
        if(s[i]=='a') ++ct;
    }

    ll ans=ct*num;

    n-=num*S;
    rep(i,n)
    {
        if(s[i]=='a') ++ans;
    }

    cout << ans << endl;
    return 0;
}
