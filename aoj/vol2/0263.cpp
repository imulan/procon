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

const int INF = INT_MAX/3;

int dp[31][1<<16];

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);
    int n,c;
    while(cin >>n >>c,n)
    {
        vector<int> a(n),b(c);
        rep(i,n)rep(j,16)
        {
            int x;
            cin >>x;
            a[i] |= x<<j;
        }
        rep(i,c)rep(j,16)
        {
            int x;
            cin >>x;
            b[i] |= x<<j;
        }

        fill(dp[0],dp[31],-INF);
        dp[0][0]=0;

        rep(i,n)rep(mask,1<<16)
        {
            rep(j,c)
            {
                int mm = mask|a[i];
                int get = mm&b[j];
                int nmask = mm^get;
                dp[i+1][nmask] = max(dp[i+1][nmask], dp[i][mask]+__builtin_popcount(get));
            }
        }

        int ans = 0;
        rep(mask,1<<16) ans = max(ans,dp[n][mask]);
        cout << ans << endl;
    }
    return 0;
}
