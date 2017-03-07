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
    int n,s;
    scanf(" %d %d", &n, &s);
    --s;

    vector<int> a(n), ct(n);
    rep(i,n) scanf(" %d", &a[i]);

    int chief=0;
    int must=0;
    rep(i,n)
    {
        if(i==s) chief = (a[i]!=0);
        else
        {
            must += (a[i]==0);
            ++ct[a[i]];
        }
    }

    int ans = 1010101010;
    if(n==1) ans=0;

    int blank = 0;
    int can = 0;

    for(int i=1; i<n; ++i)
    {
        blank+=(ct[i]==0);
        if(ct[i]>1) can+=ct[i]-1;
    }

    for(int i=n-1; i>0; --i)
    {
        if(blank<=must) ans = min(ans,must);
        else
        {
            if(blank<=must+can) ans = min(ans,blank);
        }

        blank -= (ct[i]==0);
        must += ct[i];
        if(ct[i]>1) can -= ct[i]-1;
    }

    printf("%d\n", ans+chief);
    return 0;
}
