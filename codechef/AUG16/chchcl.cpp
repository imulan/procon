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

int main()
{
    int T;
    cin >>T;
    rep(times,T)
    {
        int n,m;
        cin >>n >>m;

        string ans="Yes";
        if(n%2==1 && m%2==1) ans="No";
        cout << ans << endl;
    }
    return 0;
}
