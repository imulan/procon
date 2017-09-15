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

int ct(ll n, int d)
{
    int r = 0;
    while(n%d==0)
    {
        n/=d;
        ++r;
    }
    return r;
}

int dp[201][5001]={};

int main()
{
    int n,k;
    cin >>n >>k;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    fill(dp[0],dp[201],-19191919);
    dp[0][0] = 0;
    rep(i,n)
    {
        int T = ct(a[i],2);
        int F = ct(a[i],5);

        for(int j=k-1; j>=0; --j)
        {
            for(int f=5000; f>=0; --f)
            {
                int nf = min(5000, f+F);
                dp[j+1][nf] = max(dp[j+1][nf], dp[j][f]+T);
            }
        }
    }

    int ans = 0;
    rep(i,5001) ans = max(ans,min(dp[k][i],i));
    cout << ans << endl;
    return 0;
}
