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
    int T;
    cin >>T;
    while(T--)
    {
        string d;
        cin >>d;

        int ct[2]={0};
        rep(i,d.size()) ct[d[i]-'0']++;

        string ans="No";
        if(ct[0]==1 || ct[1]==1) ans="Yes";
        cout << ans << endl;
    }
    return 0;
}
