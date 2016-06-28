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

bool dp[5001][5001];

int main()
{
    string s,t;
    cin >>s >>t;

    if(s.size()>t.size()) printf("No\n");
    else if(s.size()==t.size())
    {
        if(s==t) printf("Yes\n");
        else printf("No\n");
    }
    else
    {
        if(s[0]!=t[0]) printf("No\n");
        else
        {
            fill(dp[0],dp[5001],false);
            dp[0][0]=true;

            int S=s.size(), T=t.size();

            rep(i,S)rep(j,T)
            {
                if(dp[i][j])
                {
                    //printf("%d,%d\n", i,j);

                    //s[i]とt[j]が同じ文字なので両方挿入
                    if(i+1<=S && j+1<=T)
                    {
                        //ここから先やる意味がない
                        if(dp[i+1][j+1]) continue;

                        if(s[i]==t[j])
                        {
                            dp[i+1][j+1]=true;
                            if(j+2<=T && t[j]!=t[j+1])
                            {
                                for(int k=j+2; k<=T; ++k) dp[i+1][k]=true;
                            }
                        }
                    }
                }
            }

            //rep(i,S+1)rep(j,T+1) printf("dp[%d][%d]= %d\n", i,j,(int)dp[i][j]);

            string ans="No";
            if(dp[S][T]) ans="Yes";
            cout << ans << endl;
        }
    }

    return 0;
}
