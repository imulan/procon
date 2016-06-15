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

const int mod=1000000007;
int dp[101][100001]={0};

int main()
{
    string n;
    int d;
    cin >>n >>d;

    int N=n.size();

    dp[0][0]=1;
    rep(i,N)
    {
        int add=0;
        for(int j=i; j<N; ++j)
        {
            add=10*add+(n[j]-'0');
            if(add>d) break;

            rep(k,d+1)
            {
                if(k+add>d) break;

                dp[j+1][k+add]+=dp[i][k];
                dp[j+1][k+add]%=mod;
            }
        }
    }

    int ans=0;
    rep(i,d+1) (ans+=dp[N][i])%=mod;
    cout << ans << endl;
    return 0;
}
