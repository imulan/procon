#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int dp[8200]={0};

inline bool check(int a, int b, int c)
{
    if(a==0) return false;
    if(b!=c) return false;
    if(a==b) return false;
    return true;
}

inline int score(int a, int b, int c)
{
    return 100*a+10*b+c;
}

int main()
{
    string s;
    cin >>s;

    int L=s.size();
    vector<int> a(L);
    rep(i,L) a[i]=s[i]-'0';

    rep(mask,1<<L)
    {
        rep(k,L)if(!(mask>>k&1))rep(j,k)if(!(mask>>j&1))rep(i,j)if(!(mask>>i&1))
        {
            if(i==j || i==k || j==k) continue;
            if(!check(a[i],a[j],a[k])) continue;

            int nxmask = mask|(1<<i)|(1<<j)|(1<<k);
            dp[nxmask] = max(dp[nxmask], dp[mask]+score(a[i],a[j],a[k]));
        }
    }

    int ans=0;
    rep(i,1<<L) ans=max(ans,dp[i]);
    cout << ans << endl;
    return 0;
}
