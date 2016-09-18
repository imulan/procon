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

    if(s.size()<26)
    {
        printf("-1\n");
        return 0;
    }

    string ans=s;
    bool valid=false;
    rep(i,s.size()-26+1)
    {
        int ct[26]={0};
        rep(j,26)
        {
            if(s[i+j]!='?') ++ct[s[i+j]-'A'];
        }

        bool ok=true;
        ans=s;
        rep(j,26)
        {
            if(ans[i+j]=='?')
            {
                int idx=0;
                while(idx<26 && ct[idx]>0) ++idx;

                if(idx==26)
                {
                    ok=false;
                    break;
                }

                ans[i+j]=idx+'A';
                ++ct[idx];
            }
        }

        rep(j,26) if(ct[j]>1) ok=false;

        if(ok)
        {
            rep(j,s.size())
            {
                if(ans[j]=='?') ans[j]='A';
            }
            valid=true;
            break;
        }
    }

    if(!valid) ans="-1";
    cout << ans << endl;
    return 0;
}
