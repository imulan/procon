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

const int N = 1000000;
int n;
int a[N];

vector<int> f(int x)
{
    vector<int> r;
    int t = x;
    for(int i=2; i*i<=x; ++i)
    {
        if(t%i==0)
        {
            r.pb(i);
            while(t%i==0) t/=i;
        }
    }
    if(t>1) r.pb(t);
    return r;
}

int l[N],r[N];
int par[N];

bool dfs(int L, int R, int p)
{
    if(L>R) return true;

    int now = L;
    int m=1, d=R-L;
    while(d>=0)
    {
        if(l[now]<=L && R<=r[now])
        {
            if(dfs(L,now-1,now) && dfs(now+1,R,now))
            {
                par[now] = p;
                return true;
            }
            return false;
        }

        now += m*d;
        --d;
        m*=-1;
    }
    return false;
}

const int M = 10000000;
vector<int> idx[M];

bool prime[M];

int main()
{
    fill(prime,prime+M,true);
    prime[0]=prime[1]=false;
    for(int i=2; i<M; ++i)
    {
        if(prime[i])for(int j=2*i; j<M; j+=i) prime[j]=false;
    }

    scanf(" %d", &n);
    rep(i,n) scanf(" %d", &a[i]);

    rep(i,N)
    {
        l[i]=0;
        r[i]=n-1;
    }

    rep(i,n)
    {
        for(const auto &d:f(a[i])) idx[d].pb(i);
    }

    rep(pp,M)if(prime[pp])
    {
        vector<int> q=idx[pp];
        int Q = q.size();
        rep(i,Q-1)
        {
            r[q[i]] = min(r[q[i]], q[i+1]-1);
            l[q[i+1]] = max(l[q[i+1]], q[i]+1);
        }
    }

    if(dfs(0,n-1,-1)) rep(i,n) printf("%d%c", par[i]+1, " \n"[i==n-1]);
    else printf("impossible\n");
    return 0;
}
