#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=3630000;
const int INF=123456789;

int f[11];
int dp[2][N];

inline int get_idx(const vector<int> &a)
{
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
    return ret;
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

    rep(d,2)
    {
        int start = d?get_idx(a):0;
        fill(dp[d],dp[d]+N,INF);
        dp[d][start]=0;
        queue<int> que;
        que.push(start);
        while(!que.empty())
        {
            int now = que.front();
            que.pop();

            vector<int> x = get_vec(n,now);
            rep(i,n)for(int j=i+2; j<=n; ++j)
            {
                reverse(x.begin()+i, x.begin()+j);

                int nx = get_idx(x);
                if(dp[d][nx]>dp[d][now]+1)
                {
                    dp[d][nx] = dp[d][now]+1;
                    if(dp[d][nx]<4) que.push(nx);
                }

                reverse(x.begin()+i, x.begin()+j);
            }
        }
    }

    int ans=9;
    rep(i,N)if(dp[0][i]<INF && dp[1][i]<INF) ans=min(ans,dp[0][i]+dp[1][i]);

    printf("%d\n", ans);
    return 0;
}
