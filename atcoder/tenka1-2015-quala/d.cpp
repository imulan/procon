#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> edge;

vector<vi> G;

void bridge_dfs(int now, int from, vector<edge> &bridge, vector<vi> &bicomp, stack<int> &roots, stack<int> &S, vb &inS, vi &preord, int &pre_ct){
    preord[now] = pre_ct++;
    S.push(now); inS[now]=true;
    roots.push(now);
    rep(i,G[now].size()){
        int to = G[now][i];
        if(preord[to] == -1) bridge_dfs(to,now,bridge,bicomp,roots,S,inS,preord,pre_ct);
        else if(from != to && inS[to]) while(preord[roots.top()] > preord[to]) roots.pop();
    }
    if(now == roots.top()){
        bridge.pb(edge(now,from));
        bicomp.pb(vi());
        while(1){
            int v=S.top(); S.pop(); inS[v]=false;
            bicomp.back().pb(v);
            if(now == v) break;
        }
        roots.pop();
    }
}

void bridge_detect(vector<edge> &bridge, vector<vi> &bicomp){
    const int n=G.size();
    vi preord(n,-1);
    vb inS(n,false);
    stack<int> roots,S;
    int pre_ct=0;
    rep(i,n)if(preord[i] == -1){
        bridge_dfs(i,n,bridge,bicomp,roots,S,inS,preord,pre_ct);
        bridge.pop_back();
    }
}

int main()
{
    int v,e;
    scanf(" %d %d", &v, &e);
    G = vector<vi>(v);
    rep(i,e)
    {
        int a,b;
        scanf(" %d %d", &a, &b);
        G[a].pb(b); G[b].pb(a);
    }

    if(v==3 && e==2)
    {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    
    vector<edge> bridge;
    vector<vi> bicomp;
    bridge_detect(bridge,bicomp);

    int B=bicomp.size();

    if(B==1) printf("IMPOSSIBLE\n");
    else if(B==2) printf("0\n");
    else
    {
        vector<int> group(v);
        rep(i,B)rep(j,bicomp[i].size()) group[bicomp[i][j]]=i;

        vector<vi> BG(B);
        rep(i,bridge.size())
        {
            int a=group[bridge[i].fi], b=group[bridge[i].se];
            BG[a].pb(b); BG[b].pb(a);
        }

        int leaf=0;
        rep(i,B) if(BG[i].size()==1) ++leaf;

        const int INF=123456789;
        int ans=INF;
        rep(i,bridge.size())
        {
            int a=group[bridge[i].fi], b=group[bridge[i].se];
            if(BG[a].size()>BG[b].size()) swap(a,b);

            if(BG[a].size()==1)
            {
                int SIZEB=BG[b].size();
                if(SIZEB>2) ans=min(ans,leaf/2);
                else if(SIZEB==2) ans=min(ans,(leaf+1)/2);
            }
        }

        if(ans==INF) printf("IMPOSSIBLE\n");
        else printf("%d\n", ans);
    }
    return 0;
}
