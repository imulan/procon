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
    rep(i,S-2)
    {
        int a=0;
        rep(j,3) a+=(s[i+j]=='O')?1:-1;
        if(a==3) return "East";
        if(a==-3) return "West";
    }
    return "NA";
}

int main()
{
    string s;
    cin >>s;
    cout << solve(s) << endl;
    return 0;
}
