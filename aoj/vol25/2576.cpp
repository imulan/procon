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

const int INF = 19191919;
int dp[15];

int main()
{
    int D;
    cin >>D;

    fill(dp,dp+15,-INF);
    dp[0]=0;

    int x;
    cin >>x;
    while(x--)
    {
        string s;
        int v;
        cin >>s >>v;
        if(s!="D") continue;
        for(int i=D-1; i>=0; --i) dp[i+1] = max(dp[i+1],dp[i]+v);
    }

    cin >>x;
    while(x--)
    {
        string s;
        int v;
        cin >>s >>v;
        if(s!="DD") continue;
        for(int i=D-1; i>=0; --i)dp[i+2] = max(dp[i+2],dp[i]+v);
    }

    int ans = 0;
    rep(i,D+1) ans = max(ans,dp[i]);
    cout << ans << endl;
    return 0;
}
