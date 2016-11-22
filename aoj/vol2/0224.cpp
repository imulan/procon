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

struct edge{ int to,cost; };
vector<edge> G[110];

const int INF=123456789;
int dist[64][110];

int m,n,k,d;

inline int convert(string s)
{
    if(s[0]=='H') return 0;
    else if(s[0]=='D') return m+n+1;
    else if(s[0]=='C') return s[1]-'0';
    else return m+atoi(s.substr(1).c_str());
}

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);
    while(cin >>m >>n >>k >>d,m)
    {
        rep(i,110) G[i].clear();
        fill(dist[0],dist[64],INF);

        vector<int> c(m);
        rep(i,m) cin >>c[i];

        rep(i,d)
        {
            string s,t;
            int e;
            cin >>s >>t >>e;
            int a=convert(s), b=convert(t);

            G[a].pb(edge{b,e});
            G[b].pb(edge{a,e});
        }

        queue<pi> que;
        que.push(pi(0,0));
        dist[0][0]=0;
        while(!que.empty())
        {
            pi now=que.front(); que.pop();
            int cake=now.fi;
            int v=now.se;
            rep(i,G[v].size())
            {
                edge e=G[v][i];
                if(1<=e.to && e.to<=m)
                {
                    if((cake>>(e.to-1))&1) continue;

                    int nc=cake|(1<<(e.to-1));
                    if(dist[nc][e.to]>dist[cake][v]+e.cost)
                    {
                        dist[nc][e.to]=dist[cake][v]+e.cost;
                        que.push(pi(nc,e.to));
                    }
                }
                else
                {
                    if(dist[cake][e.to]>dist[cake][v]+e.cost)
                    {
                        dist[cake][e.to]=dist[cake][v]+e.cost;
                        que.push(pi(cake,e.to));
                    }
                }
            }
        }

        int ans=INF;
        rep(i,1<<m)
        {
            if(dist[i][m+n+1]==INF) continue;

            int t=k*dist[i][m+n+1];
            rep(j,m) if(i>>j&1) t-=c[j];
            ans=min(ans,t);
        }
        cout << ans << endl;
    }
    return 0;
}
