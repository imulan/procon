#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

struct edge{ int to,cost; };
typedef pair<int,int> pi;
typedef pair<pi,int> pii;

const int INF=1000000000;

vector<edge> G[1000];

int main(int argc, char const *argv[]) {
  int i;

  int n,m;
  scanf(" %d %d",&n,&m);
  rep(i,m){
    int f,t,c;
    scanf(" %d %d %d",&f,&t,&c);
    G[f].pb(edge{t,c});
    G[t].pb(edge{f,c});
  }

  priority_queue<pii,vector<pii>,greater<pii>>que;

  int d4[1000][4];
  fill(d4[0],d4[1000],INF);
  d4[0][0]=0;
  que.push(pii(pi(0,0),0));
  while(!que.empty()){
    pii p=que.top();
    que.pop();
    int v=p.fi.sc;
    if(d4[v][p.sc]<p.fi.fi) continue;
    rep(i,G[v].size()){
      edge e=G[v][i];
      if(d4[e.to][(p.sc+e.cost)%4]>d4[v][p.sc]+e.cost){
        d4[e.to][(p.sc+e.cost)%4]=d4[v][p.sc]+e.cost;
        if(e.to!=n-1){
          que.push(pii(pi(d4[e.to][(p.sc+e.cost)%4],e.to),(p.sc+e.cost)%4));
        }
      }
    }
  }

  int d7[1000][7];
  fill(d7[0],d7[1000],INF);
  d7[0][0]=0;
  que.push(pii(pi(0,0),0));
  while(!que.empty()){
    pii p=que.top();
    que.pop();
    int v=p.fi.sc;
    if(d7[v][p.sc]<p.fi.fi) continue;
    rep(i,G[v].size()){
      edge e=G[v][i];
      if(d7[e.to][(p.sc+e.cost)%7]>d7[v][p.sc]+e.cost){
        d7[e.to][(p.sc+e.cost)%7]=d7[v][p.sc]+e.cost;
        if(e.to!=n-1){
          que.push(pii(pi(d7[e.to][(p.sc+e.cost)%7],e.to),(p.sc+e.cost)%7));
        }
      }
    }
  }

  printf("%d\n",min(d4[n-1][0],d7[n-1][0]));
  return 0;
}
