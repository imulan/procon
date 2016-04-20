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
#include <fstream>
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)

vector<long> G[200000];
const long INF=10000000../0;

int main(int argc, char const *argv[]) {
  long n;
  ll x,y;
  cin >>n >>x >>y;

  for(long i=0; i<n-1; ++i){
    long u,v;
    scanf(" %ld %ld", &u, &v);
    --u;
    --v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  if(x>y){
    bool only=false;
    for(long i=0; i<n; ++i){
      if(G[i].size()==n-1){
        only=true;
        break;
      }
    }

    if(only) cout << x+y*(n-2) << endl;
    else cout << y*(n-1) << endl;
  }
  else{
    //辺を1として、0からの距離
    long dist[200000];
    for(long i=0; i<n; ++i) dist[i]=INF;
    dist[0]=0;
    queue<long> que;
    que.push(0);
    while(!que.empty()){
      long v=que.front();
      que.pop();
      for(long i=0; i<G[v].size(); ++i){
        if(dist[G[v][i]] > dist[v]+1){
          dist[G[v][i]]=dist[v]+1;
          que.push(G[v][i]);
        }
      }
    }

    long m_index=-1;
    long m=0;
    for(long i=0; i<n; ++i){
      if(m<dist[i]){
        m=dist[i];
        m_index=i;
      }
    }

    //辺を1として、m_indexからの距離
    for(long i=0; i<n; ++i) dist[i]=INF;
    dist[m_index]=0;
    que.push(m_index);
    while(!que.empty()){
      long v=que.front();
      que.pop();
      for(long i=0; i<G[v].size(); ++i){
        if(dist[G[v][i]] > dist[v]+1){
          dist[G[v][i]]=dist[v]+1;
          que.push(G[v][i]);
        }
      }
    }

    long f_index=-1;
    m=0;
    for(long i=0; i<n; ++i){
      if(m<dist[i]){
        m=dist[i];
        f_index=i;
      }
    }
    //printf("m_index=%ld\nf_index=%ld\nm=%ld\n", m_index, f_index, m);

    cout << x*m+y*(n-1-m) << endl;
  }

  return 0;
}
