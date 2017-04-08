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
    cin >>n;
    vector<string> s(n);
    rep(i,n) cin >>s[i];

    int ct[50][26]={};
    rep(i,n)
    {
        rep(j,s[i].size()) ct[i][s[i][j]-'a']++;
    }

    int m[26];
    fill(m,m+26,12345);
    rep(i,n)rep(j,26) m[j]=min(m[j],ct[i][j]);

    string ans="";
    rep(i,26) ans += string(m[i],'a'+i);
    cout << ans << endl;
    return 0;
}
