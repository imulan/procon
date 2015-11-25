#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<int> G[21];
int money[21]={0};

void dfs(int a){ //社員aの給料
  int big=0, small=1000000;

  if(G[a].size() == 0) money[a]=1;
  else{
    for(int i=0; i<G[a].size(); ++i){
      if(money[ G[a][i] ] == 0) dfs(G[a][i]);

      if(money[ G[a][i] ] > big) big = money[ G[a][i] ];
      if(money[ G[a][i] ] < small) small = money[ G[a][i] ];
    }

    money[a] = big+small+1;
  }

}

int main(){
  int n, b[21];

  scanf(" %d", &n);
  for(int i=2; i<=n; ++i){
    scanf(" %d", &b[i]);
    G[b[i]].push_back(i);
  }

  dfs(1);

  printf("%d\n", money[1]);
}
