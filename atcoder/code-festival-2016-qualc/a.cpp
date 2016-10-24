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

    int c=-1,f=-1;
    rep(i,S)
    {
        if(s[i]=='C')
        {
            c=i;
            break;
        }
    }
    for(int i=S-1; i>=0; --i)
    {
        if(s[i]=='F')
        {
            f=i;
            break;
        }
    }

    string ans="No";
    if(c!=-1 && f!=-1 && c<f) ans="Yes";
    cout << ans << endl;
    return 0;
}
