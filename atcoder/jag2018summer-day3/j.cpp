#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back

int n,m,s,t;
vector<int> G[100005];
int dist[100005][2];
typedef pair<int,int> P;

void bfs(){
    memset(dist,-1,sizeof(dist));
    dist[s][0]=0;
    queue<P> que;
    que.push(P(s,0));
    while(que.size()){
        P v=que.front();
        que.pop();
        for(int i=0;i<G[v.first].size();i++){
            int nv=G[v.first][i];
            int ns=1-v.second;
            if(dist[nv][ns]==-1){
                dist[nv][ns]=dist[v.first][v.second]+1;
                que.push(P(nv,ns));
            }
        }
    }
}

bool prime[30000005];

int main(){
    scanf("%d%d%d%d",&n,&m,&s,&t);
    s--;
    t--;
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    bfs();
    memset(prime,true,sizeof(prime));
    prime[0]=false;
    prime[1]=false;
    for(int i=2;i<=30000000;i++){
        if(prime[i]){
            for(int j=i*2;j<=30000000;j+=i){
                prime[j]=false;
            }
        }
    }
    if(dist[t][0]>0 && prime[dist[t][0]]){
        printf("%d\n",dist[t][0]);
    }else if(dist[t][1]>0){
        while(!prime[dist[t][1]]){
            dist[t][1]+=2;
        }
        printf("%d\n",dist[t][1]);
    }else{
        printf("%d\n",-1);
    }
    return 0;
}
