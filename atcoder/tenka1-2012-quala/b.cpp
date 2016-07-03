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
    getline(cin,s);

    string ans="";

    int S=s.size();
    int now=0;
    while(now<S)
    {
        if(s[now]==' ')
        {
            int ed=now;
            while(ed<S && s[ed]==' ') ++ed;

            ans+=",";
            now=ed;
        }
        else ans+=s[now++];
    }

    cout << ans << endl;
    return 0;
}
