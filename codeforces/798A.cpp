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
    rep(i,S)
    {
        if(i != S-1-i && s[i] == s[S-1-i]) continue;

        string t=s;
        t[i] = t[S-1-i];
        bool ok=true;
        rep(j,S)if(t[j]!=t[S-1-j]) ok=false;
        if(ok) return "YES";
    }
    return "NO";
}

int main()
{
    string s;
    cin >>s;
    cout << solve(s) << endl;
    return 0;
}
