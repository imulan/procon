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
    ll a,b;
    cin >>a >>b;

    int ans=0;
    while(a<=b)
    {
        a*=3;
        b*=2;
        ++ans;
    }
    cout << ans << endl;
    return 0;
}
