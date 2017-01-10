#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

double dp[21][401];

double calc(int h, int x, int y, int z)
{
    memset(dp,0,sizeof(dp));
    dp[0][0]=1.0;

    rep(i,x)
    {
        rep(j,401)
        {
            for(int k=1; k<=y; ++k)
            {
                if(j+k<=400) dp[i+1][j+k]+=dp[i][j]/y;
            }
        }
    }

    double ret=0;
    rep(i,401)
    {
        // printf(" i=%d: %.3f\n", i,dp[x][i]);
        if(i+z>=h) ret+=dp[x][i];
    }
    return ret;
}

double solve()
{
    int H,S;
    cin >>H >>S;

    double ret=0;

    rep(spells,S)
    {
        string s;
        cin >>s;

        int d_pos=-1, pm_pos=-1;
        rep(i,s.size())
        {
            if(s[i]=='d') d_pos=i;
            if(s[i]=='+' || s[i]=='-') pm_pos=i;
        }

        int X,Y,Z=0;
        if(pm_pos==-1)
        {
            X = atoi(s.substr(0,d_pos).c_str());
            Y = atoi(s.substr(d_pos+1).c_str());
        }
        else
        {
            X = atoi(s.substr(0,d_pos).c_str());
            Y = atoi(s.substr(d_pos+1,pm_pos-d_pos-1).c_str());
            Z = atoi(s.substr(pm_pos+1).c_str());
            if(s[pm_pos]=='-') Z = -Z;
        }

        // printf("X,Y,Z %d %d %d\n", X,Y,Z);
        ret = max(ret, calc(H,X,Y,Z));
    }

    return ret;
}

int main()
{
    int T;
    cin >>T;
    rep(cases,T)
    {
        printf("Case #%d: %.10f\n", cases+1, solve());
    }
    return 0;
}
