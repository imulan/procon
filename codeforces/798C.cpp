#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

void solve()
{
    int n;
    scanf(" %d", &n);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    int g=__gcd(a[0],a[1]);
    for(int i=2; i<n; ++i) g = __gcd(g,a[i]);

    if(g>1)
    {
        printf("YES\n0\n");
        return;
    }

    int ret=0;
    int i=0;
    while(i<n)
    {
        if(a[i]%2==0) ++i;
        else
        {
            int start=i;
            while(i<n && a[i]%2==1) ++i;

            int r=i-start;
            if(r%2==0) ret+=r/2;
            else ret+=r/2+2;
        }
    }

    printf("YES\n%d\n", ret);
}

int main()
{
    solve();
    return 0;
}
