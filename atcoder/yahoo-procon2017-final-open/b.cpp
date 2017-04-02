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
    int n,m,k;
    scanf(" %d %d %d", &n, &m, &k);

    vector<int> a(n),b(m);
    rep(i,n) scanf(" %d", &a[i]);
    rep(i,m) scanf(" %d", &b[i]);

    sort(all(a));
    sort(all(b));

    int l=-1,r=1010101010;
    while(r-l>1)
    {
        int mid = (l+r)/2;

        int x=0,y=0;
        int ct=0;
        while(x<n && y<m)
        {
            if(abs(a[x]-b[y])<=mid)
            {
                ++x;
                ++y;
                ++ct;
            }
            else
            {
                if(a[x]<b[y]) ++x;
                else ++y;
            }
        }

        if(ct>=k) r=mid;
        else l=mid;
    }

    printf("%d\n", r);
    return 0;
}
