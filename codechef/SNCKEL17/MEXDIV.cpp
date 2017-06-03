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

const ll mod=1e9+7;

const int N=500001;
ll dp[N]={};

ll solve()
{
    int n,k;
    scanf(" %d %d", &n, &k);

    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    if(n+1<k) k=n+1;

    int z=k+1;
    vector<int> ct(k+1);

    dp[0]=1;
    int idx=0;
    ll s=0;
    rep(i,n)
    {
        if(a[i]<=k)
        {
            if(ct[a[i]]==0) --z;
            ++ct[a[i]];
        }

        (s+=dp[i])%=mod;

        while(idx<=i && z==0)
        {
            if(a[idx]<=k)
            {
                --ct[a[idx]];
                if(ct[a[idx]]==0) ++z;
            }
            s = (s-dp[idx]+mod)%mod;
            ++idx;
        }

        dp[i+1]=s;
    }

    return dp[n];
}

int main()
{
    printf("%lld\n", solve());
    return 0;
}
