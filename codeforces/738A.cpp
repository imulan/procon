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

    int i=0;
    string ans="";
    while(i<n)
    {
        if(i<n-2)
        {
            if(s.substr(i,3)=="ogo")
            {
                ans += "***";
                i+=3;
                while(i<n-1)
                {
                    if(s.substr(i,2)=="go") i+=2;
                    else break;
                }
            }
            else ans += s[i++];
        }
        else ans += s[i++];
    }

    cout << ans << endl;
    return 0;
}
