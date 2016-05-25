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

bool num(char c)
{
    return ('0'<=c && c<='9');
}

int main()
{
    string s;
    cin >>s;

    string ans="";
    rep(i,s.size())
    {
        if(num(s[i]))
        {
            ans=s.substr(i,1);
            if(i+1<=s.size()-1 && num(s[i+1])) ans+=s.substr(i+1,1);

            break;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
