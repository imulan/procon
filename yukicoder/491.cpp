#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

ll n;

ll dfs(int digit, string val, int lim)
{
    if(digit == (lim+1)/2)
    {
        string t=val;
        int r=val.size();
        if(lim%2==1) --r;

        for(int i=r-1; i>=0; --i) t+=val[i];

        string zeros="";
        rep(i,9-lim) zeros+='0';

        string a=t+zeros+t;

        return atoll(a.c_str())<=n;
    }

    ll ret = 0;

    int l=0;
    if(digit==0) l=1;

    for(int i=l; i<10; ++i)
    {
        char c = '0'+i;
        ret+=dfs(digit+1,val+c,lim);
    }

    return ret;
}

int main()
{
    cin >>n;

    ll ans = 0;

    for(int i=1; i<10; ++i)
    {
        ans += dfs(0,"",i);
    }

    cout << ans << endl;
    return 0;
}
