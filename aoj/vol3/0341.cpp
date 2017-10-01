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

int dp[1001][1001]={};

int main()
{
    string t,b;
    cin >>t >>b;

    int T = t.size(), B = b.size();

    dp[0][0] = 1;
    rep(i,B)
    {
        int s = dp[i][0];
        rep(j,T)
        {
            if(b[i]==t[j]) dp[i+1][j+1] = s;
            (s += dp[i][j+1]) %= mod;;
        }
    }

    int ans = 0;
    rep(i,T+1) (ans += dp[B][i]) %= mod;
    cout << ans << endl;
    return 0;
}
