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

struct edge
{
    int to;
    ll cost;
};

vector<edge> G[100000];
ll dist[100000]={0};

int main()
{
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    vector<int> p(n);
    rep(i,n-1)
    {
        int P,C;
        scanf(" %d %d",&P,&C);
        --P;

        p[i+1]=P;

        G[i+1].pb(edge{P,C});
        G[P].pb(edge{i+1,C});
    }

    queue<int> que;
    que.push(0);
    while(!que.empty())
    {
        int now=que.front();
        que.pop();
        rep(i,G[now].size())
        {
            int nx=G[now][i].to;
            if(nx==p[now]) continue;

            que.push(nx);
            dist[nx]=max(dist[nx],dist[now]+G[now][i].cost);
        }
    }

    vector<bool> cut(n,false);
    rep(i,n)
    {
        if(dist[i]>a[i]) cut[i]=true;
        //cout <<" "<<i<<" , "<<cut[i]<<endl;
    }

    que.push(0);
    while(!que.empty())
    {
        int now=que.front();
        que.pop();
        rep(i,G[now].size())
        {
            int nx=G[now][i].to;
            if(nx==p[now]) continue;

            que.push(nx);
            if(cut[now]) cut[nx]=true;
        }
    }

    int ans=0;
    rep(i,n)
    {
        if(cut[i]) ++ans;
    }

    cout << ans << endl;
    return 0;
}
