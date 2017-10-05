#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

int dp[1<<13][13][13];
int dfs(int m, int l, int r)
{
    if(dp[m][l][r]>=0) return dp[m][l][r];
    if(m==0) return 1;

    int enemy = 0;
    rep(i,13)if(!(l<=i && i<=r) && !(m>>i&1)) enemy |= 1<<i;

    int ret = 0;
    bool pass = true;
    if(l-1>=0 && (m>>(l-1))&1)
    {
        pass = false;
        ret |= !dfs(enemy, l-1, r);
    }
    if(r+1<=12 && (m>>(r+1))&1)
    {
        pass = false;
        ret |= !dfs(enemy, l, r+1);
    }

    if(pass) ret |= !dfs(enemy,l,r);

    return dp[m][l][r] = ret;
}

int main()
{
    memset(dp,-1,sizeof(dp));

    int n;
    cin >>n;
    while(n--)
    {
        int mask = 0;
        rep(i,6)
        {
            int f;
            cin >>f;
            --f;

            mask |= 1<<f;
        }

        string ans = "no";
        if(dfs(mask,6,6)==1) ans = "yes";
        cout << ans << endl;
    }
    return 0;
}
