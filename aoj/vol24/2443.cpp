#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=3700000;
const int INF=123456789;

int f[11];
int dp1[N], dp2[N];

map<vector<int>,int> M;
inline int get_idx(const vector<int> &a)
{
    if(M.count(a)) return M[a];

    int n = a.size();
    int ret=0;

    vector<bool> use(n,false);
    rep(i,n)
    {
        int ct=0;
        rep(j,a[i])if(!use[j]) ++ct;

        ret += ct*f[n-1-i];

        use[a[i]]=true;
    }
    return M[a]=ret;
}

inline vector<int> get_vec(int n, int idx)
{
    vector<int> ret(n);
    vector<bool> use(n,false);
    rep(i,n)
    {
        int s = idx/f[n-1-i];
        int j=0,ct=0;
        while(1)
        {
            if(!use[j])
            {
                ++ct;
                if(ct==s+1) break;
            }
            ++j;
        }

        use[j]=true;
        ret[i]=j;
        idx -= s*f[n-1-i];
    }
    return ret;
}

int main()
{
    f[0]=1;
    for(int i=1; i<=10; ++i) f[i] = f[i-1]*i;

    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n)
    {
        cin >>a[i];
        --a[i];
    }

    int g = get_idx(a);
    queue<int> que;

    fill(dp1,dp1+N,INF);
    dp1[0]=0;
    que.push(0);
    while(!que.empty())
    {
        int now = que.front();
        que.pop();

        vector<int> x = get_vec(n,now);
        // printf(" now %d\n", now);
        rep(i,n)for(int j=i+1; j<=n; ++j)
        {
            reverse(x.begin()+i, x.begin()+j);

            int nx = get_idx(x);
            // printf("  nx %d\n", nx);
            if(dp1[nx]>dp1[now]+1)
            {
                dp1[nx] = dp1[now]+1;
                if(dp1[nx]<4) que.push(nx);
            }

            reverse(x.begin()+i, x.begin()+j);
        }
    }

    fill(dp2,dp2+N,INF);
    dp2[g]=0;
    que.push(g);
    while(!que.empty())
    {
        int now = que.front();
        que.pop();

        vector<int> x = get_vec(n,now);
        rep(i,n)for(int j=i+1; j<=n; ++j)
        {
            reverse(x.begin()+i, x.begin()+j);

            int nx = get_idx(x);
            if(dp2[nx]>dp2[now]+1)
            {
                dp2[nx] = dp2[now]+1;
                if(dp2[nx]<4) que.push(nx);
            }

            reverse(x.begin()+i, x.begin()+j);
        }
    }

    int ans=9;
    rep(i,N)if(dp1[i]<INF && dp2[i]<INF) ans=min(ans,dp1[i]+dp2[i]);

    printf("%d\n", ans);
    return 0;
}
