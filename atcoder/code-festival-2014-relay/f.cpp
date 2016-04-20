#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

const int INF=100000000;
vector<int> G[100000];

int ans=0;
int dist[100000];

void dfs(int now,int depth,int parent){
  int i;
  rep(i,G[now].size()){
    if(G[now][i]==parent) continue;

    if(dist[G[now][i]]>dist[now]+1){
      dist[G[now][i]]=dist[now]+1;
      //printf("go %d\n",G[now][i]);
      dfs(G[now][i],depth+1,now);
    }
    else if(dist[G[now][i]]!=INF){//ループ発見
      //printf(" loop %d\n",depth+1-dist[G[now][i]]);
      ans=max(ans,depth+1-dist[G[now][i]]);
    }
  }
}


int main(int argc, char const *argv[]) {
  int i;

  int n;
  cin >>n;
  rep(i,n){
    int x,y;
    scanf(" %d %d",&x,&y);
    --x;
    --y;
    G[x].pb(y);
    G[y].pb(x);
  }

  fill(dist,dist+n,INF);
  dist[0]=0;
  dfs(0,0,-1);

  std::cout << ans << std::endl;
  return 0;
}
