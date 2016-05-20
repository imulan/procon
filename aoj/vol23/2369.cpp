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

map<string,bool> dp;

bool cat(string s)
{
    if(s=="") return true;
    if(dp.find(s)!=dp.end()) return dp[s];

    bool ret=false;

    if(s.size()>2 && s[0]=='m' && s[s.size()-1])
    {
        string t=s.substr(1,s.size()-2);
        rep(i,t.size())
        {
            if(t[i]=='e')
            {
                string x=t.substr(0,i);
                string y=t.substr(i+1);
                ret|=cat(x)&cat(y);
            }
        }
    }

    return dp[s]=ret;
}

int main()
{
    string s;
    cin >>s;

    dp.clear();

    string ans="Rabbit";
    if(cat(s)) ans="Cat";
    cout << ans << endl;
    return 0;
}
