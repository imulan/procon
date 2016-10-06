#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;
typedef pair<int,pi> P;

int main()
{
    int n;
    scanf(" %d", &n);

    vector<P> p(n);
    rep(i,n)
    {
        int h,a,c;
        scanf(" %d %d %d", &h, &a, &c);
        p[i]=P(a,pi(h,c));
    }
    sort(all(p));

    vector<bool> dp(40001);
    dp[0]=true;
    rep(i,n)
    {
        vector<bool> nxt(40001,false);
        int a=p[i].fi, h=p[i].se.fi, c=p[i].se.se;
        rep(j,40001)
        {
            if(!dp[j]) continue;

            rep(k,c+1)
            {
                if(j+h*k>a) break;
                nxt[j+h*k]=true;
            }
        }
        dp=nxt;
    }

    int ans=0;
    for(int i=40000; i>=0; --i)
    {
        if(dp[i])
        {
            ans=i;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
