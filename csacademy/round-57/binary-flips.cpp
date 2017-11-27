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

using vl = vector<ll>;
const ll mod = 1e9+7;

vector<vl> make_table(int n, int k)
{
    vector<vl> dp(k+1,vl(n+1));
    dp[0][0] = 1;
    rep(i,k)rep(j,n+1)
    {
        if(j+1<=n) (dp[i+1][j+1]+=dp[i][j]*(n-j))%=mod;
        if(j-1>=0) (dp[i+1][j-1]+=dp[i][j]*j)%=mod;
    }
    return dp;
}

ll solve(int n, int m, int k, int s)
{
    vector<vl> dr = make_table(n,k), dc = make_table(m,k);

    ll ans = 0;
    rep(r1,n+1)rep(c1,m+1)
    {
        if(r1*(m-c1) + c1*(n-r1) == s) (ans += (dr[k][r1]*dc[k][c1])%mod) %= mod;
    }
    return ans;
}

int main()
{
    int T;
    cin >>T;
    while(T--)
    {
        int n,m,k,s;
        cin >>n >>m >>k >>s;
        cout << solve(n,m,k,s) << endl;
    }
    return 0;
}
