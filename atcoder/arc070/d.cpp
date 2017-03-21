#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int n,k;
int a[5000];

const int N=10101;

int dp[5001];

int main()
{
    cin >>n >>k;
    rep(i,n) cin >>a[i];
    sort(a,a+n);

    int l=0, r=n+1;
    while(r-l>1)
    {
        int m = (l+r)/2;

        bool valid = false;
        if(a[m-1]<k)
        {
            valid = true;

            memset(dp,0,sizeof(dp));
            dp[0]=1;
            rep(i,n)
            {
                if(i==m-1) continue;

                for(int j=k; j>=0; --j)if(dp[j])
                {
                    int nx=min(k,j+a[i]);
                    dp[nx]=1;
                }
            }


            for(int i=k-a[m-1]; i<k; ++i)
            {
                if(dp[i])
                {
                    valid = false;
                    break;
                }
            }
        }

        if(valid) l=m;
        else r=m;
    }

    cout << l << endl;
    return 0;
}
