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

const ll INF = LLONG_MAX/3;

int main()
{
    int n,c,v;
    cin >>n >>c >>v;

    vector<ll> dp(n+1,INF);
    dp[1] = 0;
    for(int i=1; i<n; ++i)
    {
        ll cost = c+v;
        for(int j=2*i; j<=2*n; j+=i)
        {
            dp[min(n,j)] = min(dp[min(n,j)],dp[i]+cost);
            cost += v;
        }
    }

    cout << dp[n] << endl;
    return 0;
}
