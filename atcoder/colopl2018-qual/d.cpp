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

const int N = 5005;
ll dp[N]={}, nx[N], ans[N];

ll deq[N];
int main()
{
    int n,x;
    cin >>n >>x;

    vector<ll> t(n);
    rep(i,n) cin >>t[i];

    rep(i,n) dp[i]=x;
    ans[1]=x;

    for(int i=1; i<n; ++i)
    {
        fill(nx,nx+N,0);

        vector<ll> s(n);
        rep(j,n) s[j] = dp[j]-t[j];

        int p=0,q=0;

        ll T = LLONG_MIN/3;
        int idx = 0;
        for(int j=0; j<n; ++j)
        {

            while(idx<j && t[j]-t[idx]>=x)
            {
                T = max(T,dp[idx]);
                ++idx;
            }

            while(p<q && s[deq[q-1]]<=s[j]) --q;
            deq[q++] = j;

            while(deq[p]<idx) ++p;

            // printf(" %d %d\n", p,q);
            // nx[j] = max(T+x, S.query(idx,n)+t[j]);
            nx[j] = max(T+x, s[deq[p]]+t[j]);

        }

        rep(j,N-1) nx[j+1] = max(nx[j+1],nx[j]);

        ans[i+1]=0;
        rep(j,N)
        {
            dp[j]=nx[j];
            ans[i+1]=max(ans[i+1],dp[j]);
        }
    }

    for(int i=1; i<=n; ++i) cout << ans[i] << endl;
    return 0;
}
