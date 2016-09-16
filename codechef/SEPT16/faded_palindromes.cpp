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
    int T;
    cin >>T;
    while(T--)
    {
        string s;
        cin >>s;
        int S=s.size();

        string ans="";
        rep(i,S)
        {
            if(s[i]=='.')
            {
                if(i==S-1-i) ans+='a';
                else
                {
                    if(s[S-1-i]=='.') ans+='a';
                    else ans+=s[S-1-i];
                }
            }
            else
            {
                ans+=s[i];
                if(i!=S-1-i && s[S-1-i]!='.' && s[i]!=s[S-1-i])
                {
                    ans="-1";
                    break;
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}
