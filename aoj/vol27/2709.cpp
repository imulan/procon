#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int n,m,k;
int d[16],v[100][100];

const int INF=123456789;
const int N=1<<16;
int dp[N];

int main()
{
    scanf(" %d %d %d", &n, &m, &k);
    rep(i,m)
    {
        scanf(" %d", &d[i]);
        --d[i];
    }
    rep(i,n)rep(j,k)
    {
        scanf(" %d", &v[i][j]);
        --v[i][j];
    }

    fill(dp,dp+N,INF);
    int start = (1<<m)-1;
    dp[start] = 0;

    queue<int> que;
    que.push(start);
    while(!que.empty())
    {
        int mask = que.front();
        que.pop();

        // printf("mask = %d\n", mask);

        rep(i,k)
        {
            int nx=0;
            rep(j,m)if(mask>>j&1)
            {
                int next_room = v[d[j]][i];
                // printf(" next_room = %d\n", next_room);
                rep(d_idx,m)
                {
                    if(d[d_idx] == next_room)
                    {
                        nx |= (1<<d_idx);
                        break;
                    }
                }
            }

            // printf("i = %d, nx = %d\n", i,nx);
            if(dp[nx] > dp[mask]+1)
            {
                dp[nx] = dp[mask]+1;
                que.push(nx);
            }
        }
    }

    printf("%d\n", dp[0]);
    return 0;
}
