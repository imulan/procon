#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)

int main(int argc, char const *argv[]) {
  int n, g, e;
  cin >>n >>g >>e;

  std::vector<int> p(g);
  REP(i,g) scanf(" %d", &p[i]);

  std::vector<int> a(e),b(e);
  REP(i,e) scanf(" %d %d", &a[i], &b[i]);

  //部分点
  if(e>13) return 0;

  int ans=100;
  REP(i,1<<e){ //どの友人関係を切るかbitloop
    int tmp=0;

    std::vector<int> G[100];
    REP(j,e){
      if( ((i>>j)&1)==0 ){ //追加
        G[a[j]].push_back(b[j]);
        G[b[j]].push_back(a[j]);
      }
      else ++tmp;
    }

    std::vector<bool> visit(n);
    fill(visit.begin(), visit.end(), false);

    visit[0]=true;
    //BFS
    queue<int> que;
    que.push(0);
    while(!que.empty()){
      int v=que.front();
      que.pop();
      REP(j,G[v].size()){
        if(!visit[G[v][j]]){
          que.push(G[v][j]);
          visit[G[v][j]]=true;
        }
      }
    }

    REP(j,g){
      if(visit[p[j]]) ++tmp;
    }

    ans = min(ans, tmp);
  }

  printf("%d\n", ans);

  return 0;
}
