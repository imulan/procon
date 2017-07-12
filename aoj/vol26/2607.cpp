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

const int N = 101010;
int dp[N];

int main()
{
    int n,d,x;
    cin >>n >>d >>x;
    vector<vector<int>> p(d,vector<int>(n));
    rep(i,d)rep(j,n) cin >>p[i][j];

    rep(i,d-1)
    {
        memset(dp,0,sizeof(dp));
        rep(j,n)rep(k,x+1)
        {
            if(k+p[i][j]<=x) dp[k+p[i][j]] = max(dp[k+p[i][j]], dp[k]+p[i+1][j]);
        }

        int v = x;
        rep(k,x+1) v = max(v,dp[k]+x-k);
        x = v;
    }

    cout << x << endl;
    return 0;
}
