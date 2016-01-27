#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  vector<int> G[100001];

  cin >>n;
  for(int i=0; i<n-1; ++i){
    int a,b;
    scanf(" %d %d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }

  const int INF=1000000;

  //村1からの距離
  int dist[100001];
  for(int i=1; i<=n; ++i) dist[i]=INF;
  dist[1]=0;

  queue<int> que;
  que.push(1);
  //BFS
  while(!que.empty()){
    int v=que.front(); que.pop();
    for(int i=0; i<G[v].size(); ++i){
      if(dist[G[v][i]] > dist[v]+1){
        que.push(G[v][i]);
        dist[G[v][i]] = dist[v]+1;
      }
    }
  }

  int _m=0;
  int p=0; //答えの片方
  for(int i=1; i<=n; ++i){
    if(_m<dist[i]){
      _m=dist[i];
      p=i;
    }
  }

  //この村pからBFS
  for(int i=1; i<=n; ++i) dist[i]=INF;
  dist[p]=0;
  que.push(p);
  //BFS
  while(!que.empty()){
    int v=que.front(); que.pop();
    for(int i=0; i<G[v].size(); ++i){
      if(dist[G[v][i]] > dist[v]+1){
        que.push(G[v][i]);
        dist[G[v][i]] = dist[v]+1;
      }
    }
  }

  _m=0;
  int q=0; //答えのもう片方
  for(int i=1; i<=n; ++i){
    if(_m<dist[i]){
      _m=dist[i];
      q=i;
    }
  }

  printf("%d %d\n", p, q);

  return 0;
}
