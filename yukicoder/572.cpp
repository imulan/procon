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

const ll INF = LLONG_MAX/4;

ll n;
int m;
int a[30][30];

ll dp1[30][30][31];
ll f(int from, int to, int step)
{
    if(dp1[from][to][step]>=0) return dp1[from][to][step];
    if(step==0)
    {
        if(from==to) return 0;
        return -INF;
    }

    ll ret = 0;
    rep(i,m) ret = max(ret, f(i,to,step-1)+a[from][i]);

    return dp1[from][to][step] = ret;
}

ll dp2[30][62];
ll g(int s, int elim)
{
    if(dp2[s][elim]>=0) return dp2[s][elim];
    ll rem = n-elim;
    if(rem<0) return -INF;

    ll ret = 0;
    for(int i=1; i<=30; ++i)
    {
        if(rem%i==0) ret = max(ret,(rem/i)*f(s,s,i));
    }

    return dp2[s][elim] = ret;
}

int main()
{
    cin >>n >>m;
    --n;

    rep(i,m)rep(j,m) cin >>a[i][j];

    memset(dp1,-1,sizeof(dp1));
    memset(dp2,-1,sizeof(dp2));

    ll ans = 0;

    rep(i,m)rep(j,m)rep(k,m)rep(ii,31)rep(jj,31)
    {
        ans = max(ans, f(i,k,ii) + g(k,ii+jj) + f(k,j,jj));
    }

    cout << ans << endl;
    return 0;
}
