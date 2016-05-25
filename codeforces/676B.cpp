#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int main()
{
    int n,t;
    cin >>n >>t;

    double a[10][10]={0};
    double eps=1e-6;

    rep(T,t)
    {
        a[0][0]+=1;

        rep(i,n-1)rep(j,i+1)
        {
            if(a[i][j]>1)
            {
                double t=(a[i][j]-1)/2;
                a[i][j]=1;
                a[i+1][j]+=t;
                a[i+1][j+1]+=t;
            }
        }

        rep(i,n) a[n-1][i]=min(a[n-1][i],1.0);
    }

    int ans=0;
    rep(i,n)rep(j,n)
    {
        if(fabs(a[i][j]-1)<eps) ++ans;
    }

    cout << ans << endl;
    return 0;
}
