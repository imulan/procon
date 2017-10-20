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

const int N = 100000;
const int INF = 19191919;

int n,L,W;
int a[N],b[N];

vector<int> p;

inline int ID(int x)
{
    int idx = lower_bound(b,b+n,x)-b;
    if(a[idx]<=x && x<=b[idx]) return idx;
    return -1;
}

int main()
{
    cin >>n >>L >>W;
    rep(i,n) cin >>a[i] >>b[i];

    rep(i,n)
    {
        p.pb(a[i]);
        p.pb(b[i]);
    }

    rep(i,n)
    {
        int x;
        x = a[i]-W;
        if(ID(x)!=-1) p.pb(x);

        x = a[i]+W;
        if(ID(x)!=-1) p.pb(x);

        x = b[i]-W;
        if(ID(x)!=-1) p.pb(x);

        x = b[i]+W;
        if(ID(x)!=-1) p.pb(x);
    }

    int now = L;
    while(1)
    {
        int nx = now - W;
        if(ID(nx)==-1) break;
        if(ID(now)==ID(nx)) break;

        p.pb(nx);
        now = nx;
    }

    now = 0;
    while(1)
    {
        int nx = now + W;
        if(ID(nx)==-1) break;
        if(ID(now)==ID(nx)) break;

        p.pb(nx);
        now = nx;
    }

    sort(all(p));
    p.erase(unique(all(p)),p.end());

    int P = p.size();
    vector<int> dp(P,INF);
    dp[0] = 0;
    rep(i,P)
    {
        if(i<P-1 && ID(p[i])==ID(p[i+1])) dp[i+1] = min(dp[i+1],dp[i]);

        int nx = p[i]+W;
        if(nx <= L)
        {
            int idx = lower_bound(all(p),nx) - p.begin();
            if(p[idx]==nx) dp[idx] = min(dp[idx], dp[i]+1);
        }
    }

    // dbg(p);
    // dbg(dp);

    int ans = dp[P-1];
    if(ans==INF) ans = -1;
    cout << ans << endl;
    return 0;
}
