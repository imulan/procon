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

    int a=0, b=0, c=0, d=0;
    rep(i,s.size())
    {
        if(s[i]=='N') ++a;
        else if(s[i]=='S') ++b;
        else if(s[i]=='E') ++c;
        else if(s[i]=='W') ++d;
    }

    string ans="Yes";
    if( (a>0&&b==0) || (a==0&&b>0) || (c>0&&d==0) || (c==0&&d>0) ) ans="No";
    
    cout << ans << endl;
    return 0;
}
