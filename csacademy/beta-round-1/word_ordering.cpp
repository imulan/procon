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
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >>s;
    int n;
    cin >>n;
    vector<string> w(n);
    rep(i,n) cin >>w[i];

    string S="";
    rep(i,s.size()) S+=s[i]-'a'+'A';

    char m[150], inv_m[150];
    rep(i,s.size())
    {
        m[s[i]]='A'+i;
        inv_m['A'+i]=s[i];
    }
    rep(i,S.size())
    {
        m[S[i]]='a'+i;
        inv_m['a'+i]=S[i];
    }

    //変換
    rep(i,n)rep(j,w[i].size()) w[i][j]=m[w[i][j]];

    sort(all(w));

    //元に戻す
    rep(i,n)
    {
        rep(j,w[i].size()) w[i][j]=inv_m[w[i][j]];
        cout << w[i] << "\n";
    }

    return 0;
}
