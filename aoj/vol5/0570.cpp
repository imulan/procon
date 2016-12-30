#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int mod=10000;

int M;

// a桁目まで決定, 最後に選んだ数b, 今の和のMでの剰余c, S未満が確定d, leading zeroかどうかe, 次上に行くか下に行くかf
int dp[506][10][500][2][2][2];
string s;
int dfs(int a, int b, int c, int d, int e, int f)
{
    if(dp[a][b][c][d][e][f]>=0) return dp[a][b][c][d][e][f];

    if(a==505) return c==0;

    // 1桁を考慮
    if(a==504 && e==1)
    {
        int ub=9;
        if(d==0) ub=s[a]-'0';

        int ret=0;
        for(int i=1; i<=ub; ++i) ret+=(i%M==0);
        return ret;
    }

    int ret=0;

    if(e==1)
    {
        // 次の桁もleading zeroを続ける
        if(d==0)
        {
            ret+=dfs(a+1,0,c,(s[a]!='0'),1,f);
            ret%=mod;
        }
        else
        {
            ret+=dfs(a+1,0,c,d,1,f);
            ret%=mod;
        }

        // leading zeroをやめる
        if(d==0)
        {
            int ub = s[a]-'0';
            if(ub>0)
            {
                // printf("a= %d, ub= %d\n", a,ub);

                for(int i=1; i<ub; ++i)
                {
                    ret+=dfs(a+1,i,(c*10+i)%M,1,0,0);
                    ret%=mod;

                    ret+=dfs(a+1,i,(c*10+i)%M,1,0,1);
                    ret%=mod;
                }
                ret+=dfs(a+1,ub,(c*10+ub)%M,0,0,0);
                ret%=mod;

                ret+=dfs(a+1,ub,(c*10+ub)%M,0,0,1);
                ret%=mod;
            }
        }
        else
        {
            for(int i=1; i<10; ++i)
            {
                ret+=dfs(a+1,i,(c*10+i)%M,1,0,0);
                ret%=mod;

                ret+=dfs(a+1,i,(c*10+i)%M,1,0,1);
                ret%=mod;
            }
        }
    }
    else
    {
        // 下降
        if(f==0)
        {
            if(d==0)
            {
                int ub=s[a]-'0';
                rep(i,b)
                {
                    if(i<ub)
                    {
                        ret+=dfs(a+1,i,(c*10+i)%M,1,e,!f);
                        ret%=mod;
                    }
                    else if(i==ub)
                    {
                        ret+=dfs(a+1,i,(c*10+i)%M,0,e,!f);
                        ret%=mod;
                    }
                }
            }
            else
            {
                rep(i,b)
                {
                    ret+=dfs(a+1,i,(c*10+i)%M,1,e,!f);
                    ret%=mod;
                }
            }
        }
        else
        {
            if(d==0)
            {
                int ub=s[a]-'0';
                for(int i=b+1; i<10; ++i)
                {
                    if(i<ub)
                    {
                        ret+=dfs(a+1,i,(c*10+i)%M,1,e,!f);
                        ret%=mod;
                    }
                    else if(i==ub)
                    {
                        ret+=dfs(a+1,i,(c*10+i)%M,0,e,!f);
                        ret%=mod;
                    }
                }
            }
            else
            {
                for(int i=b+1; i<10; ++i)
                {
                    ret+=dfs(a+1,i,(c*10+i)%M,1,e,!f);
                    ret%=mod;
                }
            }
        }
    }

    return dp[a][b][c][d][e][f]=ret;
}

inline string fill_leadingzero(string c)
{
    string ret=c;
    while(ret.size()<505) ret = "0"+ret;
    return ret;
}

int isValid(string c)
{
    int C=c.size();
    rep(i,C-1)
    {
        if(c[i]==c[i+1]) return 0;
    }

    int ud=1;
    if(c[0]<c[1]) ud=0;

    for(int i=1; i<C-1; ++i)
    {
        if(ud==1)
        {
            if(c[i]>c[i+1]) return 0;
        }
        else
        {
            if(c[i]<c[i+1]) return 0;
        }

        ud = !ud;
    }

    int sum=0;
    rep(i,C)
    {
        sum = sum*10 + (c[i]-'0');
        sum%=M;
    }

    return sum==0;
}

int main()
{
    string A,B;
    cin >>A >>B >>M;

    int ans=0;

    memset(dp,-1,sizeof(dp));
    s=fill_leadingzero(B);
    ans+=dfs(0,0,0,0,1,0);

    memset(dp,-1,sizeof(dp));
    s=fill_leadingzero(A);
    ans-=dfs(0,0,0,0,1,0);

    ans+=isValid(A);
    ans = (ans+mod)%mod;

    printf("%d\n", ans);
    return 0;
}
