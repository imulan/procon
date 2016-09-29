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
    int q;
    scanf(" %d", &q);
    while(q--)
    {
        int n;
        scanf(" %d", &n);

        string ans="Yes";
        if(n%2==1) ans="No";
        cout << ans << endl;
    }
    return 0;
}
