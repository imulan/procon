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

using pi = pair<int,int>;

const int V=100001;

int n;
int p[V];
vector<int> c[V];
int a[V]={};

int d[V]={};
int dp[V];

int main()
{
    scanf(" %d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf(" %d %d", &p[i], &a[i]);
        c[p[i]].pb(i);
    }

    queue<int> que;
    que.push(0);
    while(!que.empty())
    {
        int v=que.front();
        que.pop();
        for(const auto &nx:c[v])
        {
            d[nx] = d[v]+1;
            que.push(nx);
        }
    }

    priority_queue<pi> pq;
    for(int i=1; i<=n; ++i) pq.push(pi(d[i],i));

    fill(dp,dp+V,-V);
    while(!pq.empty())
    {
        pi now=pq.top();
        pq.pop();
        int v=now.se;

        int s=0;
        for(const auto &nx:c[v])if(dp[nx]>0) s+=dp[nx];

        dp[v] = a[v]+s;
    }

    int ans=-V;
    for(int i=1; i<=n; ++i) ans=max(ans,dp[i]);
    printf("%d\n", ans);
    return 0;
}
