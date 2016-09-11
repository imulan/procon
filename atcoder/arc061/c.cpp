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
    cin >>s;

    int S=s.size();

    ll ans=0;

    rep(mask,1<<(S-1))
    {
        int st=0;
        rep(i,S-1)
        {
            if(mask>>i&1)
            {
                ans+=atoll(s.substr(st,(i+1)-st).c_str());
                st=i+1;
            }
        }
        ans+=atoll(s.substr(st).c_str());
    }

    cout << ans << endl;
    return 0;
}
