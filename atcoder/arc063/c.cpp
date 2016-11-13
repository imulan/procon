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
    int S=s.size();

    int ans=0;
    rep(i,S-1) ans+=(s[i]!=s[i+1]);
    cout << ans << endl;
    return 0;
}
