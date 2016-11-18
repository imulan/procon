#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

bool check(string s)
{
    int S=s.size();
    rep(i,S) if(!('0'<=s[i] && s[i]<='9')) return false;

    if(s[0]=='0' && S>1) return false;
    if(atoi(s.c_str())>12345) return false;
    return true;
}

int main()
{
    string a,b;
    cin >>a >>b;
    string ans="NG";
    if(check(a) && check(b)) ans="OK";
    cout << ans << endl;
    return 0;
}
