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
    int n;
    cin >>n;
    vector<string> s(n);
    rep(i,n) cin >>s[i];

    bool valid=false;

    rep(i,n)
    {
        if(s[i][0]=='O' && s[i][1]=='O')
        {
            valid=true;
            s[i][0]='+';
            s[i][1]='+';
            break;
        }
    }

    if(!valid)
    {
        rep(i,n)
        {
            if(s[i][3]=='O' && s[i][4]=='O')
            {
                valid=true;
                s[i][3]='+';
                s[i][4]='+';
                break;
            }
        }
    }

    if(valid)
    {
        printf("YES\n");
        rep(i,n) cout << s[i] << endl;
    }
    else printf("NO\n");
    return 0;
}
