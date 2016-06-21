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

typedef pair<int,int> pi;

int main()
{
    int n;
    cin >>n;
    vector<int> v(n);
    rep(i,n) cin >>v[i];

    int dp[1001][2]={0};
    pi p[1001][2];
    for(int i=1; i<=n; ++i)
    {
        dp[i][0]=dp[i-1][1]+v[i-1];
        p[i][0]=pi(i-1,1);

        if(dp[i-1][1]>=dp[i-1][0])
        {
            dp[i][1]=dp[i-1][1];
            p[i][1]=pi(i-1,1);
        }
        else
        {
            dp[i][1]=dp[i-1][0];
            p[i][1]=pi(i-1,0);
        }
    }

    //rep(i,n+1) printf("%d %d\n", dp[i][0],dp[i][1]);

    int ans=max(dp[n][0],dp[n][1]);
    vector<int> a;

    //経路復元
    pi st;
    if(dp[n][0]>dp[n][1]) st=pi(n,0);
    else st=pi(n,1);

    while(1)
    {
        if(st.fi==0) break;

        pi nst=p[st.fi][st.se];
        if(st.se==0 && nst.se==1) a.pb(st.fi);

        st=nst;
    }

    reverse(all(a));

    //output
    cout << ans << endl;
    rep(i,a.size())
    {
        if(i) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}
