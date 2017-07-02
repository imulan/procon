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

const int N=200002;
const ll INF = LLONG_MAX/3;
vector<int> L[N],R[N];
ll dp[N];

int main()
{
    int n,x;
    scanf(" %d %d", &n, &x);

    vector<int> l(n),r(n),c(n);
    rep(i,n)
    {
        scanf(" %d %d %d", &l[i], &r[i], &c[i]);
        L[l[i]].pb(i);
        R[r[i]].pb(i);
    }

    ll ans = INF;
    fill(dp,dp+N,INF);
    for(int i=N-1; i>0; --i)
    {
        for(const auto &v:R[i])
        {
            int d = r[v]-l[v]+1;
            int y = x-d;
            if(y<1) continue;

            ll t = c[v]+dp[y];
            ans = min(ans,t);
        }

        for(const auto &v:L[i])
        {
            int d = r[v]-l[v]+1;
            dp[d] = min(dp[d],(ll)c[v]);
        }
    }

    if(ans==INF) ans = -1;
    printf("%lld\n", ans);
    return 0;
}
