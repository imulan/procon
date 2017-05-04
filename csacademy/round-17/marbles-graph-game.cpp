#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int V=100000;

int N,M,K;
int m[V];

bool vis[V]={}, win[V]={};
int turn[V]={};
vector<int> G[V],rG[V];
vector<int> tlist;

void dfs(int now)
{
    if(vis[now]) return;

    vis[now] = true;
    for(const auto &nx:G[now]) dfs(nx);
    tlist.pb(now);
}

int main()
{
    scanf(" %d %d %d", &N, &M, &K);
    rep(i,K)
    {
        scanf(" %d", &m[i]);
        --m[i];
    }
    rep(i,M)
    {
        int a,b;
        scanf(" %d %d", &a, &b);
        --a;
        --b;

        G[a].pb(b);
        rG[b].pb(a);
    }

    rep(i,N) dfs(i);
    // reverse(all(tlist));

    for(const auto &x:tlist)
    {
        for(const auto &nx:G[x]) win[x] |= !win[nx];
        if(win[x])
        {
            turn[x]=12345678;
            for(const auto &nx:G[x])if(!win[nx]) turn[x]=min(turn[x], turn[nx]+1);
        }
        else
        {
            for(const auto &nx:G[x])if(win[nx]) turn[x]=max(turn[x], turn[nx]+1);
        }        
        // printf(" x= %d, win = %d, turn = %d\n", x,win[x],turn[x]);
    }

    bool A=true;
    int T=12345678;
    rep(i,K)
    {
        if(T>turn[m[i]])
        {
            T = turn[m[i]];
            A = win[m[i]];
        }
    }
    cout << "BA"[A] << endl;
    return 0;
}
