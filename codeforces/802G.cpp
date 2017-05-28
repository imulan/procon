#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const string H = "heidi";

string solve(string s)
{
    int S=s.size();
    int h=0;
    rep(i,S)
    {
        if(s[i]==H[h]) ++h;
        if(h==5) return "YES";
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
