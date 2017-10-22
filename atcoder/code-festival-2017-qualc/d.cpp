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
const int N = 222222;
const int A = 26;

int dp[N];
int memo[1<<A];

int main()
{
    string s;
    cin >>s;
    int S = s.size();

    fill(dp,dp+N,INF);
    fill(memo,memo+(1<<A),INF);

    vector<int> v;
    v.pb(0);
    rep(i,26) v.pb(1<<i);

    dp[0] = 0;
    memo[0] = 0;

    int ai = 0;
    rep(i,S)
    {
        int x = s[i]-'a';
        ai ^= (1<<x);

        for(int j:v) dp[i+1] = min(dp[i+1],memo[ai^j]+1);
        memo[ai] = min(memo[ai],dp[i+1]);
    }

    printf("%d\n", dp[S]);
    return 0;
}
