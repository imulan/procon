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
    int k;
    string s;
    cin >>k >>s;

    if(k==0)
    {
        cout << s << endl;
        return 0;
    }

    int S=s.size();

    ll ans=1234567890123456LL;
    rep(mask,1<<(S-1))
    {
        if(__builtin_popcount(mask)!=k) continue;

        int st=0;
        ll m=0;
        rep(i,S-1)
        {
            if(mask>>i&1)
            {
                m=max(m,atoll(s.substr(st,i-st).c_str()));
                st=i;
            }
        }
        m=max(m,atoll(s.substr(st,S-st).c_str()));

        ans=min(ans,m);
    }
    cout << ans << endl;
    return 0;
}
