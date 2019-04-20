#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0; (i)<(int)(n); ++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> P;
int n,m;
vector<int> G[105];
P edge[191];
int col[105];
int dist[105][105];

void bfs(int s){
    queue<int> que;
    dist[s][s]=0;
    que.push(s);
    while(que.size()){
        int v=que.front();
        que.pop();
        for(int i=0;i<G[v].size();i++){
            int nv=G[v][i];
            if(dist[s][nv]==-1){
                dist[s][nv]=dist[s][v]+1;
                que.push(nv);
            }
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&col[i]);
    }
    memset(dist,-1,sizeof(dist));
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--;
        b--;
        edge[i]=P(a,b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        bfs(i);
    }
    for(int i=0;i<=n;i++){
        if(i%2==0){
            for(int j=0;j<n;j++){
                int cnt=0;
                for(int k=0;k<n;k++){
                    if(dist[j][k]<=i/2){
                        cnt+=col[k];
                    }
                }
                if(cnt>=m){
                    printf("%d\n",i);
                    return 0;
                }
            }
        }else{
            for(int j=0;j<n-1;j++){
                int cnt=0;
                int a=edge[j].first;
                int b=edge[j].second;
                for(int k=0;k<n;k++){
                    if(dist[a][k]<=i/2 || dist[b][k]<=i/2){
                        cnt+=col[k];
                    }
                }
                if(cnt>=m){
                    printf("%d\n",i);
                    return 0;
                }
            }
        }
        
    }
    return 0;
}
