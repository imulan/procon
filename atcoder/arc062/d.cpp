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
    int n=s.size();

    int ans=0;
    int g=0,p=0;
    rep(i,n)
    {
        if(s[i]=='g')
        {
            if(p<g)
            {
                ++p;
                ++ans;
            }
            else ++g;
        }
        else
        {
            if(p<g) ++p;
            else
            {
                ++g;
                --ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
