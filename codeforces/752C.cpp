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
    string s;
    cin >>n >>s;

    int ans=0;

    int idx=0;
    while(idx<n)
    {
        ++ans;
        int x=0,y=0;
        while(idx<n)
        {
            if(s[idx]=='R')
            {
                if(x<0) break;
                ++x;
            }
            else if(s[idx]=='L')
            {
                if(x>0) break;
                --x;
            }
            else if(s[idx]=='U')
            {
                if(y>0) break;
                --y;
            }
            else
            {
                if(y<0) break;
                ++y;
            }
            ++idx;
        }
    }

    cout << ans << endl;
    return 0;
}
