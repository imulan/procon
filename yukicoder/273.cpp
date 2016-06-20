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

bool isKaibun(string s)
{
    int n=s.size();
    rep(i,n/2)
    {
        if(s[i]!=s[n-1-i]) return false;
    }
    return true;
}

int main()
{
    string s;
    cin >>s;

    int n=s.size();

    //まず全ての始点と終点に関して回分か調べておく
    bool k[50][50];
    rep(i,n)for(int j=i; j<n; ++j)
    {
        k[i][j]=isKaibun(s.substr(i,j-i+1));
    }

    //iを始点とするときの回文長の最大値
    int dp[51]={0};

    //まず0が始点の時は終点は0~n-2まで
    rep(i,n-1)
    {
        if(k[0][i]) dp[i+1]=max(dp[i+1],i+1);
    }

    for(int i=1; i<n; ++i)
    {
        for(int j=i; j<n; ++j)
        {
            if(k[i][j]) dp[j+1]=max({dp[j+1],dp[i],j-i+1});
        }
    }

    cout << dp[n] << endl;
    return 0;
}
