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

    int ans=0;
    string io="IO";

    rep(i,s.size())
    {
        if(s[i]==io[ans%2]) ++ans;
    }

    if(ans>0 && ans%2==0) --ans;
    cout << ans << endl;
    return 0;
}
