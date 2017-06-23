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

int dp[10001]={};

int main()
{
    int n,m,L;
    cin >>n >>m >>L;
    vector<int> a(n),b(n),c(m),d(m);
    rep(i,n) cin >>a[i] >>b[i];
    rep(i,m) cin >>c[i] >>d[i];

    rep(i,m)for(int j=L; j>=0; --j)
    {
        if(j+c[i]<=L) dp[j+c[i]] = max(dp[j+c[i]], dp[j]+d[i]);
    }

    rep(i,L-1) dp[i+1]=max(dp[i+1],dp[i]);

    int ans = 0;
    rep(i,n)
    {
        if(a[i]>L) continue;
        ans = max(ans, b[i]+dp[L-a[i]]);
    }
    cout << ans << endl;
    return 0;
}
