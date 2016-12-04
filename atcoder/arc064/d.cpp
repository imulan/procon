#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

string solve(string s)
{
    int S=s.size();

    if(s[0]==s[S-1])
    {
        if(S%2==1) return "Second";
    }
    else
    {
        if(S%2==0) return "Second";
    }

    return "First";
}

int main()
{
    string s;
    cin >>s;
    cout << solve(s) << endl;
    return 0;
}
