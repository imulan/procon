#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int mod=1000000007;
string a,b,c;

string fillX(string s)
{
    string ret=s;
    while(ret.size()<51) ret="X"+ret;
    return ret;
}

int dp[51][2];
int dfs(int now, int carry)
{
    if(dp[now][carry]>=0) return dp[now][carry];
    if(now==0)
    {
        if(carry==0) return 1;
        else return 0;
    }

    int ret=0;

    if(a[now]=='?' && b[now]=='?')
    {
        int idxa=0,idxb=0;
        if(a[now-1]=='X') idxa=1;
        if(b[now-1]=='X') idxb=1;
        for(int i=idxa; i<=9; ++i)for(int j=idxb; j<=9; ++j)
        {
            int val=i+j+carry;
            if(c[now]=='X')
            {
                if(val==0) ret+=dfs(now-1,val/10);
            }
            else if(c[now]=='?')
            {
                if(c[now-1]=='X')
                {
                    if(val%10!=0) (ret+=dfs(now-1,val/10))%=mod;
                }
                else (ret+=dfs(now-1,val/10))%=mod;
            }
            else
            {
                if(c[now]-'0'==val%10) (ret+=dfs(now-1,val/10))%=mod;
            }
        }
    }
    else if(a[now]=='?')
    {
        int val_b=b[now]-'0';
        if(b[now]=='X') val_b=0;

        int idxa=0;
        if(a[now-1]=='X') idxa=1;
        for(int i=idxa; i<=9; ++i)
        {
            int val=i+val_b+carry;
            if(c[now]=='X')
            {
                if(val==0) ret+=dfs(now-1,val/10);
            }
            else if(c[now]=='?')
            {
                if(c[now-1]=='X')
                {
                    if(val%10!=0) (ret+=dfs(now-1,val/10))%=mod;
                }
                else (ret+=dfs(now-1,val/10))%=mod;
            }
            else
            {
                if(c[now]-'0'==val%10) (ret+=dfs(now-1,val/10))%=mod;
            }
        }
    }
    else if(b[now]=='?')
    {
        int val_a=a[now]-'0';
        if(a[now]=='X') val_a=0;

        int idxb=0;
        if(b[now-1]=='X') idxb=1;
        for(int j=idxb; j<=9; ++j)
        {
            int val=val_a+j+carry;
            if(c[now]=='X')
            {
                if(val==0) ret+=dfs(now-1,val/10);
            }
            else if(c[now]=='?')
            {
                if(c[now-1]=='X')
                {
                    if(val%10!=0) (ret+=dfs(now-1,val/10))%=mod;
                }
                else (ret+=dfs(now-1,val/10))%=mod;
            }
            else
            {
                if(c[now]-'0'==val%10) (ret+=dfs(now-1,val/10))%=mod;
            }
        }

    }
    else
    {
        int val_a=a[now]-'0', val_b=b[now]-'0';
        if(a[now]=='X') val_a=0;
        if(b[now]=='X') val_b=0;

        int val=val_a+val_b+carry;
        if(c[now]=='X')
        {
            if(val==0) ret+=dfs(now-1,val/10);
        }
        else if(c[now]=='?')
        {
            if(c[now-1]=='X')
            {
                if(val%10!=0) (ret+=dfs(now-1,val/10))%=mod;
            }
            else (ret+=dfs(now-1,val/10))%=mod;
        }
        else
        {
            if(c[now]-'0'==val%10) (ret+=dfs(now-1,val/10))%=mod;
        }
    }

    return dp[now][carry]=ret;
}

int main()
{
    while(cin >>a)
    {
        if(a=="0") break;
        cin >>b >>c;

        a=fillX(a);
        b=fillX(b);
        c=fillX(c);

        memset(dp,-1,sizeof(dp));
        cout << dfs(50,0) << endl;
    }
    return 0;
}
