#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    int n;
    string s;
    cin >>n >>s;

    int dp[100]={0};

    rep(i,3) if(s[i]=='X') dp[i]=1;
    for(int i=3; i<n; ++i) dp[i]=min({dp[i-1],dp[i-2],dp[i-3]})+(s[i]=='X');

    cout << dp[n-1] << endl;
    return 0;
}
