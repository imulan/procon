#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

ll dp[200001]={0};

int main()
{
    int n,k;
    scanf(" %d %d", &n, &k);
    vector<int> t(n), d(n);
    int D=0;
    rep(i,n)
    {
        scanf(" %d %d", &t[i], &d[i]);
        D=max(D,d[i]);
    }

    int l=-1, r=D;
    while(r-l>1)
    {
        int m=(l+r)/2;

        bool ok=true;
        int b=-k;
        rep(i,n)
        {
            if(d[i]>m)
            {
                if(t[i]-b<k)
                {
                    ok=false;
                    break;
                }
                b=t[i];
            }
        }

        if(ok) r=m;
        else l=m;
    }

    vector<bool> yuki(n,true);
    int b=-k;
    rep(i,n)
    {
        if(d[i]>r)
        {
            b=t[i];
            yuki[i]=false;
        }
        else
        {
            if(t[i]-b<k) yuki[i]=false;
        }
    }
    b=2000000001;
    for(int i=n-1; i>=0; --i)
    {
        if(d[i]>r)
        {
            b=t[i];
            yuki[i]=false;
        }
        else
        {
            if(b-t[i]<k) yuki[i]=false;
        }
    }

    vector<int> yt,yd;
    rep(i,n)
    {
        if(yuki[i])
        {
            yt.pb(t[i]);
            yd.pb(d[i]);
        }
    }

    int Y=yt.size();
    int lidx=0;
    rep(i,Y)
    {
        while(i>lidx)
        {
            if(yt[i]-yt[lidx]<k) break;
            ++lidx;
        }
        dp[i+1] = max(dp[i],dp[lidx]+yd[i]);
    }

    ll sum=0;
    ll yuki_sum=dp[Y];
    rep(i,n)
    {
        sum+=d[i];
        if(d[i]>r) yuki_sum+=d[i];
    }

    printf("%d\n%lld\n",r,sum-yuki_sum);
    return 0;
}
