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
    int w;
    scanf(" %d", &w);
    vector<int> a(w);
    rep(i,w) scanf(" %d", &a[i]);

    vector<int> ev(w,0);

    int now=0;
    int state=0;

    rep(i,w)
    {
        if(a[i]==0)
        {
            now=10000;
            state=0;
        }
        if(a[i]<0)
        {
            now=min(now,-a[i]);
            state=1;
        }

        ev[i]=max(ev[i],now);
        if(state) --now;
    }

    now=0;
    state=0;
    for(int i=w-1; i>=0; --i)
    {
        if(a[i]==0)
        {
            now=10000;
            state=0;
        }
        if(a[i]<0)
        {
            now=min(now,-a[i]);
            state=1;
        }

        ev[i]=max(ev[i],now);
        if(state) --now;
    }

    int ans=0;
    rep(i,w)
    {
        if(a[i]>0) ans+=min(a[i],ev[i]);
    }
    printf("%d\n", ans);
    return 0;
}
