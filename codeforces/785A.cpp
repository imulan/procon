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
    cin.tie(0);ios::sync_with_stdio(false);

    int n;
    cin >>n;

    int ans=0;
    rep(i,n)
    {
        string s;
        cin >>s;

        if(s[0]=='T') ans+=4;
        else if(s[0]=='C') ans+=6;
        else if(s[0]=='O') ans+=8;
        else if(s[0]=='D') ans+=12;
        else ans+=20;
    }

    cout << ans << endl;
    return 0;
}
