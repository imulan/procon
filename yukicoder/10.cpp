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

string dp[100001],newdp[100001];

int main()
{
    int n,total;
    cin >>n >>total;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    fill(dp,dp+total+1,"#");
    dp[a[0]]="";

    for(int i=1; i<n; ++i)
    {
        fill(newdp,newdp+total+1,"#");
        for(int j=1; j<=total; ++j)
        {
            int nxt=j+a[i];
            if(nxt<=total)
            {
                if(newdp[nxt]=="#") newdp[nxt]=dp[j]+"+";
                else newdp[nxt]=max(newdp[nxt],dp[j]+"+");
            }

            nxt=j*a[i];
            if(nxt<=total)
            {
                if(newdp[nxt]=="#") newdp[nxt]=dp[j]+"*";
                else newdp[nxt]=max(newdp[nxt],dp[j]+"*");
            }
        }

        rep(j,total+1) dp[j]=newdp[j];
    }

    cout << dp[total] << endl;
    return 0;
}
