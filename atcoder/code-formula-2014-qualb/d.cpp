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

int n,a[60]={};

ll dp[60][50001];
ll dfs(int d, int r)
{
    if(d==60) return 1;
    if(dp[d][r]>=0) return dp[d][r];

    ll ret = 0;
    rep(i,10)
    {
        int nr = r+a[d]-i;
        if(nr>=0) (ret+=dfs(d+1,nr/10))%=mod;
    }

    return dp[d][r] = ret;
}

int main()
{
    cin >>n;
    rep(i,n) cin >>a[i];

    memset(dp,-1,sizeof(dp));
    cout << (dfs(0,0)-1+mod)%mod << endl;
    return 0;
}
