#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repl(i,a,b) for(int (i)=(int)(a); (i)<(int)(b); ++(i))
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x<<"="<<x<<endl
#define minch(x,y) x=min(x,y)
#define INF 1e16

typedef pair<ll,ll> P;

vector<P> g[1000001];
vector<ll> adj1;
vector<ll> adjN;

int main(){
    int N,M,K;
    vector<P> es;
    vector<ll> w;

    scanf("%d%d%d",&N,&M,&K);
    rep(i,M){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        a--;b--;
        g[a].push_back(P(b,c));
        g[b].push_back(P(a,c));
        es.push_back(P(a,b));
        w.push_back(c);
    }
    if(K>5){
        printf("-1\n");
        return 0;
    }
    adj1.resize(N,INF); adjN.resize(N,INF);
    for(P e : g[0]){
        minch(adj1[e.fi],e.se);
    }
    for(P e : g[N-1]){
        minch(adjN[e.fi],e.se);
    }
    ll res=INF;
    if(K==1){
        minch(res,adj1[N-1]);
    }else if(K==2){
        rep(i,N){
            if(i==0||i==N-1)continue;
            minch(res,adj1[i]+adjN[i]);
        }
    }else if(K==3){
        rep(i,M){
            int u=es[i].fi,v=es[i].se;
            if(u==0||u==N-1)continue;
            if(v==0||v==N-1)continue;
            minch(res,adj1[u]+adjN[v]+w[i]);
            minch(res,adj1[v]+adjN[u]+w[i]);
        }
    }else if(K==4){
        rep(i,N){
            if(i==0||i==N-1)continue;
            vector<P> v1,vN;
            for(P e : g[i]){
                int v=e.fi;
                ll ew=e.se;
                if(v!=0&&v!=N-1){
                    v1.push_back(P(adj1[v]+ew,v));
                    vN.push_back(P(adjN[v]+ew,v));
                }
            }
            sort(all(v1)); sort(all(vN));
            while(v1.size()>3)v1.pop_back();
            while(vN.size()>3)vN.pop_back();
            rep(j,v1.size())rep(k,vN.size()){
                int x=v1[j].se,y=vN[k].se;
                if(x==y)continue;
                minch(res,v1[j].fi+vN[k].fi);
            }
        }
    }else if(K==5){
        vector<P> v1[N],vN[N];
        rep(i,N){
            if(i==0||i==N-1)continue;
            for(P e : g[i]){
                int v=e.fi;
                ll ew=e.se;
                if(v!=0&&v!=N-1){
                    v1[i].push_back(P(adj1[v]+ew,v));
                    vN[i].push_back(P(adjN[v]+ew,v));
                }
            }
            sort(all(v1[i])); sort(all(vN[i]));
            while(v1[i].size()>3)v1[i].pop_back();
            while(vN[i].size()>3)vN[i].pop_back();
        }
        rep(i,M){
            int u=es[i].fi,v=es[i].se;
            if(u==0||u==N-1)continue;
            if(v==0||v==N-1)continue;
            rep(j,v1[u].size())rep(k,vN[v].size()){
                int x=v1[u][j].se,y=vN[v][k].se;
                if(x==v||y==u||x==y)continue;
                minch(res,v1[u][j].fi+vN[v][k].fi+w[i]);
            }
            rep(j,v1[v].size())rep(k,vN[u].size()){
                int x=v1[v][j].se,y=vN[u][k].se;
                if(x==u||y==v||x==y)continue;
                minch(res,v1[v][j].fi+vN[u][k].fi+w[i]);
            }
        }
    }
    if(res==INF) printf("-1\n");
    else printf("%lld\n",res);

    return 0;
}

