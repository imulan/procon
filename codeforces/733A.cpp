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
    s="A"+s+"A";

    string v="AEIOUY";

    int ans=1;
    int b=0;
    for(int i=1; i<=s.size(); ++i)
    {
        bool vowel=false;
        rep(j,v.size()) if(s[i-1]==v[j]) vowel=true;

        if(vowel)
        {
            ans=max(ans,i-b);
            b=i;
        }
    }

    cout << ans << endl;
    return 0;
}
