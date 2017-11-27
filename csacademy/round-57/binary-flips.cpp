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

const ll mod = 1e9+7;

vector<ll> make_table(int n, int k)
{
    vector<ll> dp(n+1);
    dp[0] = 1;
    rep(i,k)
    {
        vector<ll> nx(n+1);
        rep(j,n+1)
        {
            if(j+1<=n) (nx[j+1]+=dp[j]*(n-j))%=mod;
            if(j-1>=0) (nx[j-1]+=dp[j]*j)%=mod;
        }
        dp = nx;
    }
    return dp;
}

ll solve(int n, int m, int k, int s)
{
    vector<ll> dr = make_table(n,k), dc = make_table(m,k);
    ll ans = 0;
    rep(r1,n+1)rep(c1,m+1)
    {
        if(r1*(m-c1) + c1*(n-r1) == s) (ans += dr[r1]*dc[c1])%=mod;
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
