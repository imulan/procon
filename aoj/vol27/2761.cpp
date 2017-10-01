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

int n,m;
int x[100],a[10],b[10],c[10];

int dp[101][101][10];
int dfs(int l, int r, int f)
{
    if(dp[l][r][f]>=0) return dp[l][r][f];

    if(r-l==1) return (x[l]==a[f]);

    int ret = 0;
    for(int i=l+1; i<r; ++i) ret |= dfs(l,i,b[f])&dfs(i,r,c[f]);

    return dp[l][r][f]=ret;
}

int main()
{
    cin >>n;
    rep(i,n) cin >>x[i];
    cin >>m;
    rep(i,m)
    {
        cin >>a[i] >>b[i] >>c[i];
        --b[i];
        --c[i];
    }

    memset(dp,-1,sizeof(dp));
    string ans = "No";
    if(dfs(0,n,0)==1) ans = "Yes";
    cout << ans << endl;
    return 0;
}
