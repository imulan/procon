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

const int INF=12345678;

//weight,price
typedef pair<int,int> pi;

int main()
{
    int s,d,m;
    while(cin >>s >>d >>m)
    {
        vector<vector<pi>> kanmi(s);
        vector<int> f(d);

        rep(i,s)
        {
            int k;
            cin >>k;
            rep(j,k)
            {
                int w,p;
                cin >>w >>p;
                kanmi[i].pb(pi(w,p));
            }
        }
        rep(i,d) cin >>f[i];

        //i円払った時に増やせる体重の最大値
        int dp[301]={0};

        rep(i,d)
        {
            //その日のj番目の甘味を買うか？
            rep(j,kanmi[f[i]].size())
            {
                for(int x=m; x>=0; --x)
                {
                    //買える
                    if(x+kanmi[f[i]][j].se<=m)
                    {
                        dp[x+kanmi[f[i]][j].se] = max(dp[x+kanmi[f[i]][j].se], dp[x]+kanmi[f[i]][j].fi);
                    }
                }

            }
        }

        int ax=0,ay=0;
        rep(i,m+1)
        {
            //printf("dp[%d]=%d\n", i,dp[i]);
            if(dp[i]>ax)
            {
                ax=dp[i];
                ay=i;
            }
        }

        printf("%d %d\n",ax,ay);
    }
    return 0;
}
