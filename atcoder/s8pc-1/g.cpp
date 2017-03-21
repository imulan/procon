#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll INF = 123456789012345LL;

ll fast[16][1<<16];
ll path[16][1<<16]={};

void solve()
{
    int n,m;
    cin >>n >>m;

    ll d[16][16]={}, t[16][16]={};
    while(m--)
    {
        int x,y;
        ll D,T;
        cin >>x >>y >>D >>T;
        --x;
        --y;

        d[x][y]=d[y][x]=D;
        t[x][y]=t[y][x]=T;
    }

    if(n==1)
    {
        printf("0 1\n");
        return;
    }

    // まず最短時間を求める
    fill(fast[0],fast[16],INF);
    fast[0][1]=0;
    for(int mask=1; mask<(1<<n); ++mask)
    {
        rep(last,n)if(mask>>last&1)
        {
            rep(nx,n)if(!(mask>>nx&1) && d[last][nx]>0)
            {
                ll arrive_time = fast[last][mask]+d[last][nx];

                // 通行中に封鎖されるのでダメ
                if(arrive_time > t[last][nx]) continue;

                int nmask = mask+(1<<nx);
                fast[nx][nmask] = min(fast[nx][nmask], arrive_time);
            }
        }
    }

    ll FAST = INF;
    for(int i=1; i<n; ++i)
    {
        if(fast[i][(1<<n)-1]<INF && d[i][0]>0)
        {
            ll arrive_time = fast[i][(1<<n)-1]+d[i][0];
            if(arrive_time > t[i][0]) continue;

            FAST = min(FAST,arrive_time);
        }
    }

    if(FAST == INF)
    {
        printf("IMPOSSIBLE\n");
        return;
    }

    // 経路が存在することが確定したので、何通りか数える
    path[0][1]=1;
    for(int mask=1; mask<(1<<n); ++mask)
    {
        rep(last,n)if(mask>>last&1)
        {
            rep(nx,n)if(!(mask>>nx&1) && d[last][nx]>0)
            {
                ll arrive_time = fast[last][mask]+d[last][nx];

                // 通行中に封鎖されるのでダメ
                if(arrive_time > t[last][nx]) continue;

                int nmask = mask+(1<<nx);
                if(arrive_time == fast[nx][nmask])
                {
                    path[nx][nmask] += path[last][mask];
                }
            }
        }
    }

    ll PATH = 0;
    for(int i=1; i<n; ++i)
    {
        if(fast[i][(1<<n)-1]<INF && d[i][0]>0)
        {
            ll arrive_time = fast[i][(1<<n)-1]+d[i][0];
            if(arrive_time > t[i][0]) continue;

            if(arrive_time == FAST) PATH+=path[i][(1<<n)-1];
        }
    }

    printf("%lld %lld\n", FAST, PATH);
}

int main()
{
    solve();
    return 0;
}
