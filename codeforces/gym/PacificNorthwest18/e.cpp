#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define INF (1<<28)

struct edge{
	int to,cap,rev;
	edge(){}
	edge(int tt,int cc,int rr){
		to=tt;
		cap=cc;
		rev=rr;
	}
};


class dinic{
public:
	vector<edge> G[1805];
	int level[1805];
	int iter[1805];
	void add_edge(int from,int to,int cap){
		G[from].push_back(edge(to,cap,G[to].size()));
		G[to].push_back(edge(from,0,G[from].size()-1));
	}

	void bfs(int s){
		memset(level,-1,sizeof(level));
		queue<int> que;
		level[s]=0;
		que.push(s);
		while(que.size()){
			int v=que.front();
			que.pop();
			for(int i=0;i<G[v].size();i++){
				edge &e=G[v][i];
				if(e.cap>0 && level[e.to]<0){
					level[e.to]=level[v]+1;
					que.push(e.to);
				}
			}
		}
	}

	int dfs(int v,int t,int f){
		if(v==t)return f;
		int res=0;
		for(int &i=iter[v];i<G[v].size();i++){
			edge &e=G[v][i];
			if(e.cap>0 && level[v]<level[e.to]){
				int d=dfs(e.to,t,min(e.cap,f));
				if(d>0){
					e.cap-=d;
					G[e.to][e.rev].cap+=d;
					res+=d;
					f-=d;
					if(f==0)break;
				}
			}
		}
		return res;
	}

	int max_flow(int s,int t){
		int flow=0;
		while(1){
			bfs(s);
			if(level[t]<0)return flow;
			memset(iter,0,sizeof(iter));
			int f;
			while((f=dfs(s,t,INF))>0){
				flow+=f;
			}
		}
	}
};

int n,m,c;
dinic di;
int sx,sy;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int fie[35][35];
ll cost[30];

int main(){
    scanf("%d%d%d",&m,&n,&c);
    memset(fie,-1,sizeof(fie));
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        for(int j=0;j<m;j++){
            if(str[j]=='B'){
                sy=i;
                sx=j;
            }else if(str[j]=='.'){
            }else{
                fie[i][j]=str[j]-'a';
            }   
        }
    }
    if(sx==0 || sx==(m-1) || sy==0 || sy==(n-1)){
        printf("%d\n",-1);
        return 0;
    }
    for(int i=0;i<c;i++){
        scanf("%lld",&cost[i]);
    }
    int S=n*m*2;
    int T=S+1;
    di.add_edge(S,sy*m+sx,INF);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(fie[i][j]==-1){
                di.add_edge(i*m+j,n*m+i*m+j,INF);
            }else{
                di.add_edge(i*m+j,n*m+i*m+j,cost[fie[i][j]]);
            }
            for(int k=0;k<4;k++){
                int nx=j+dx[k];
                int ny=i+dy[k];
                if(nx==-1 || nx==m || ny==-1 || ny==n){
                    di.add_edge(n*m+i*m+j,T,INF);
                }else{
                    di.add_edge(n*m+i*m+j,ny*m+nx,INF);
                }                
            }
        }
    }
    int ans=di.max_flow(S,T);
    if(ans>=INF){
        printf("%d\n",-1);
        return 0;
    }
    printf("%d\n",ans);
    return 0;
}

