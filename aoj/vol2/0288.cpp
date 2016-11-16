#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;

const int INF=1234567;
int c[101][101];

int main()
{
    int D,N;
    int a[100],e[100],r[100];
    while(scanf(" %d %d", &D, &N),D)
    {
        rep(i,N) scanf(" %d %d %d", &a[i], &e[i], &r[i]);

        fill(c[0],c[101],INF);
        c[D][0]=0;
        queue<pi> que;
        que.push(pi(D,0));
        while(!que.empty())
        {
            pi v=que.front();
            que.pop();
            int rem=v.fi, ex=v.se;
            rep(i,N)
            {
                if(ex<r[i]) continue;

                int nr=max(0,rem-a[i]), ne=min(100,ex+e[i]);
                if(c[nr][ne] > c[rem][ex]+1)
                {
                    c[nr][ne] = c[rem][ex]+1;
                    que.push(pi(nr,ne));
                }
            }
        }

        int ans=INF;
        rep(i,101) ans=min(ans,c[0][i]);

        if(ans==INF) printf("NA\n");
        else printf("%d\n", ans);
    }
    return 0;
}
