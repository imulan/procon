#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N = 150000;

vector<int> G[N];

string solve()
{
    int n,m;
    scanf(" %d %d", &n, &m);
    rep(i,m)
    {
        int a,b;
        scanf(" %d %d", &a, &b);
        --a;
        --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    ll expected_m = 0;
    vector<bool> vis(n,false);
    rep(i,n)
    {
        if(vis[i]) continue;

        ll connected = 1;
        vis[i] = true;
        queue<int> que;
        que.push(i);
        while(!que.empty())
        {
            int v=que.front();
            que.pop();
            rep(j,G[v].size())
            {
                int nx = G[v][j];
                if(!vis[nx])
                {
                    vis[nx] = true;
                    que.push(nx);
                    ++connected;
                }
            }
        }

        expected_m += connected * (connected-1) / 2;
    }

    return (expected_m == m)?"YES":"NO";
}

int main()
{
    cout << solve() << endl;
    return 0;
}
