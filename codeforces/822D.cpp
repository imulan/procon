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

const ll mod = 1e9+7;
const ll INF = LLONG_MAX/3;

const int N = 5000001;
ll dp[N];
int min_p[N];

int main()
{
    int t,l,r;
    cin >>t >>l >>r;

    ll ans = 0;
    fill(dp,dp+N,INF);
    fill(min_p,min_p+N,19191919);

    for(int i=2; i<N; ++i)if(min_p[i]==19191919)
    {
        min_p[i]=i;
        for(int j=2; i*j<N; ++j) min_p[i*j] = min(min_p[i*j],i);
    }

    dp[1]=0;
    dp[2]=1;
    for(int i=2; i<N; ++i) dp[i] = dp[i/min_p[i]] + (ll)i*(min_p[i]-1)/2;

    ll mul = 1;
    for(int i=l; i<=r; ++i)
    {
        ll add = mul*(dp[i]%mod);
        add %= mod;

        (mul *= t)%=mod;
        (ans += add)%=mod;
    }

    cout << ans << endl;
    return 0;
}
