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

const int N = 500000;
int n;
int v[N];

vector<int> g(int l, int r)
{
    vector<int> res;
    int st = l;
    while(st<=r)
    {
        int idx = st;
        while(idx<=r && v[idx]) ++idx;
        res.pb(idx-st);
        st = idx+1;
    }
    return res;
}

const int INF = 19191919;
int calc(const vector<int> &a)
{
    int A = a.size();
    if(A<2) return 0;

    // no left right-1 right
    vector<vector<int>> dp(A+1,vector<int>(4,-INF));

    dp[0][0] = 0;
    for(int i=1; i<A; ++i)
    {
        rep(j,4)
        {
            dp[i][0] = max(dp[i][0], dp[i-1][j]);

            if(j==3) break;

            if(a[i-1]>1)
            {
                if(j<2) dp[i][1] = max(dp[i][1], dp[i-1][j]+a[i-1]-(j!=0));
                if(j==2) dp[i][1] = max(dp[i][1], dp[i-1][j]+1);
            }
            else if(a[i-1]==1 && j==0) dp[i][1] = max(dp[i][1], dp[i-1][j]+1);

            if(j==0 || a[i-1]>1) dp[i][2] = max(dp[i][2], dp[i-1][j]+a[i]-1);

            if(j==0 || a[i-1]>1) dp[i][3] = max(dp[i][3], dp[i-1][j]+a[i]);
        }
    }

    int ret = 0;
    rep(i,4) ret = max(ret,dp[A-1][i]);
    return ret;
}

int main()
{
    string s;
    cin >>n >>s;
    rep(i,n) v[i] = s[i]-'0';

    int ans = 0;

    int st = 0;
    while(st<n-1)
    {
        if(v[st]==0) ++st;
        else
        {
            int idx = st;
            while(idx<n-1 && (v[idx]!=0||v[idx+1]!=0)) ++idx;

            vector<int> d = g(st,idx);
            ans += calc(d);

            st = idx;
        }
    }
    cout << ans << endl;
    return 0;
}
