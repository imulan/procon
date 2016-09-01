#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int N=100000;
vector<int> G[N];

int main()
{
    int T;
    cin >>T;
    rep(times,T)
    {
        int n;
        cin >>n;

        rep(i,n) G[i].clear();

        vector<int> a(n);
        rep(i,n)
        {
            scanf(" %d", &a[i]);
            int nx=(i+1+a[i])%n;
            G[i].pb(nx);
            G[nx].pb(i);
        }

        vector<bool> vis(n,false);
        int ans=0;
        rep(i,n)
        {
            if(vis[i]) continue;

            queue<int> que;
            que.push(i);
            vis[i]=true;
            while(!que.empty())
            {
                int v=que.front();
                que.pop();
                rep(j,G[v].size())
                {
                    int nx=G[v][j];
                    if(!vis[nx])
                    {
                        vis[nx]=true;
                        que.push(nx);
                    }
                }
            }

            int now=i;
            int ct=0;
            map<int,int> m;
            vector<bool> tvis(n,false);
            while(!tvis[now])
            {
                tvis[now]=true;
                m[now] = ct++;
                now = (now+a[now]+1)%n;
            }
            ans += ct-m[now];
        }

        cout << ans << endl;
    }
    return 0;
}
