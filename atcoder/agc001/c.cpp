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

typedef pair<int,int> pi;

struct edge{int to,cost;};
const int INF=12345678;

vector<edge> G[2000];

int d[2000][2000];

int main()
{
    int n,k;
    cin >>n >>k;

    vector<pi> E;

    rep(i,n-1)
    {
        int a,b;
        cin >>a >>b;
        --a;
        --b;

        G[a].pb(edge{b,1});
        G[b].pb(edge{a,1});
        E.pb(pi(a,b));
    }

    fill(d[0],d[2000],INF);
    rep(i,n)
    {
        //dijkstra
        priority_queue<pi,vector<pi>,greater<pi>> que;
        d[i][i]=0;
        que.push(pi(0,i));
        while(!que.empty())
        {
            pi p=que.top();
            que.pop();
            int v=p.se;

            if(d[i][v]<p.fi) continue;

            rep(j,G[v].size())
            {
                edge e=G[v][j];
                if(d[i][e.to]>d[i][v]+e.cost)
                {
                    d[i][e.to]=d[i][v]+e.cost;
                    que.push(pi(d[i][e.to],e.to));
                }
            }
        }
    }

    int ans=n;

    if(k%2==0)
    {
        rep(i,n)
        {
            int ct=0;
            rep(j,n) if(d[i][j]>k/2) ++ct;
            ans=min(ans,ct);
        }
    }
    else
    {
        rep(i,E.size())
        {
            int va=E[i].fi;
            int vb=E[i].se;

            int ct=0;
            rep(j,n) if(d[va][j]>(k-1)/2 && d[vb][j]>(k-1)/2) ++ct;
            ans=min(ans,ct);
        }
    }

    cout << ans << endl;
    return 0;
}
