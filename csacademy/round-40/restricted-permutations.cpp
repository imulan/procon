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

const int mod = 1e9+7;

// iまで並べた,iより前にj個数がある
int dp[2020][2020]={};

int main()
{
    int n;
    cin >>n;
    vector<int> x(n-1);
    rep(i,n-1) cin >>x[i];

    dp[0][0]=1;
    rep(i,n-1)
    {
        int s = 0;
        if(x[i]==0)
        {
            for(int j=1; j<=i+1; ++j)
            {
                (s += dp[i][j-1])%=mod;
                dp[i+1][j] = s;
            }
        }
        else
        {
            for(int j=i; j>=0; --j)
            {
                (s += dp[i][j])%=mod;
                dp[i+1][j] = s;
            }
        }
    }

    int ans = 0;
    rep(i,n) (ans+=dp[n-1][i])%=mod;
    cout << ans << endl;
    return 0;
}
