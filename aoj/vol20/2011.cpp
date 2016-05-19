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

typedef vector<int> vi;

int main()
{
    int n;
    while(cin >>n,n)
    {
        //schedule
        int s[50][31]={0};

        rep(i,n)
        {
            int f;
            cin >>f;
            rep(j,f)
            {
                int d;
                cin >>d;
                s[i][d]=1;
            }
        }

        int ans=-1;
        vector<vi> v(n,vi(n,0));

        rep(i,n) v[i][i]=1;

        //i-th day
        for(int i=1; i<=30; ++i)
        {
            vi G[50];
            rep(j,n)rep(k,j)
            {
                if(s[j][i] && s[k][i])
                {
                    G[j].pb(k);
                    G[k].pb(j);
                }
            }

            //root-j BFS
            vi vv(n);
            rep(j,n)
            {
                if(vv[j]) continue;

                vi vis(n);
                vis[j]=1;
                queue<int> que;
                que.push(j);
                while(!que.empty())
                {
                    int now=que.front();
                    que.pop();
                    rep(k,G[now].size())
                    {
                        int nx=G[now][k];
                        if(!vis[nx])
                        {
                            que.push(nx);
                            vis[nx]=1;
                        }
                    }
                }

                vi p(n);
                rep(k,n)
                {
                    if(vis[k])
                    {
                        rep(l,n) p[l]|=v[k][l];
                    }
                }

                rep(k,n)
                {
                    if(vis[k])
                    {
                        rep(l,n) v[k][l]|=p[l];
                    }
                }

                rep(k,n) vv[k]|=vis[k];
            }

            rep(j,n)
            {
                int ct=0;
                rep(k,n) ct+=v[j][k];
                if(ct==n)
                {
                    ans=i;
                    break;
                }
            }

            if(ans>0) break;
        }

        printf("%d\n", ans);
    }
    return 0;
}
