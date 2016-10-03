#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;

const int N=5000;

int dp[N];
int used[N];

int main()
{
    int T;
    scanf(" %d", &T);
    while(T--)
    {
        int n;
        scanf(" %d", &n);
        vector<pi> stick(n);
        rep(i,n) scanf(" %d %d", &stick[i].fi, &stick[i].se);

        sort(all(stick));
        vector<int> y(n);
        rep(i,n) y[i]=stick[i].se;

        // initialize
        fill(dp,dp+N,1);
        fill(used,used+N,0);

        rep(i,n)for(int j=i+1; j<n; ++j)
        {
            if(y[i]<=y[j]) dp[j] = max(dp[j],dp[i]+1);
        }

        vector<pi> a(n);
        rep(i,n) a[i]=pi(-dp[i],i);
        sort(all(a));

        int ans=0;
        rep(i,n)
        {
            int idx=a[i].se;
            if(used[idx]) continue;

            // printf("start %d\n", idx);

            used[idx]=1;
            ++ans;

            while(1)
            {
                int nx=-1;
                int h=0;
                for(int j=idx-1; j>=0; --j)
                {
                    if(!used[j] && h<y[j])
                    {
                        h=y[j];
                        nx=j;
                    }
                }

                // printf(" nx = %d\n", nx);
                if(nx==-1) break;
                used[nx]=1;
                idx=nx;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
