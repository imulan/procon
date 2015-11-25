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
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)

int main(){
  int n;
  long m;
  int mp[400][400]={0};

  cin >> n >> m;
  for(long i=0; i<m; ++i){
    int u,v;
    scanf(" %d %d", &u, &v);
    u--;
    v--;
    mp[u][v]=1;
    mp[v][u]=1;
  }

  int tmp=0;
  for(int i=0; i<n; ++i) tmp+=mp[n-1][i];

  if(tmp==0 || tmp==n-1) printf("-1\n");
  else{
    int rt=!mp[0][n-1];
    //printf("rt=%d\n", rt);

    vector<bool> visit(n);
    vector<long> dist(n);
    fill(visit.begin(), visit.end(), false);
    fill(dist.begin(), dist.end(), 100000);

    queue<int> q;
    q.push(0);
    visit[0]=true;
    dist[0]=0;

    while(!q.empty()){
      int v=q.front(); q.pop();
      for(int i=0; i<n; ++i){
        if(mp[v][i]==rt && !visit[i]){
          visit[i]=true;
          dist[i] = min(dist[i], dist[v]+1);
          q.push(i);
        }
      }
    }

    if(dist[n-1]==100000) printf("-1\n");
    else printf("%ld\n", dist[n-1]);
  }

}
