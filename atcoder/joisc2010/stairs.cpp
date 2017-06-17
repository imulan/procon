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

const int mod=1234567;
int dp[500001]={};

int main()
{
    int n;
    ll p;
    scanf(" %d %lld", &n, &p);
    vector<ll> h(n);
    rep(i,n) scanf(" %lld", &h[i]);

    vector<ll> sumh(n+1);
    rep(i,n) sumh[i+1] = sumh[i]+h[i];

    dp[0]=1;
    int idx = 0,sum = 0;
    rep(i,n)
    {
        (sum += dp[i])%=mod;
        while(sumh[i+1] - sumh[idx]>p)
        {
            sum = (sum-dp[idx]+mod)%mod;
            ++idx;
        }
        dp[i+1] = sum;
    }

    printf("%d\n", dp[n]);
    return 0;
}
