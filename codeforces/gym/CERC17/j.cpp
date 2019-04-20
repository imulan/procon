#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,bool> P;

#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)b;i++)
#define rep(i,n) repl(i,0,n)
#define dbg(x) cout<<#x"="<<x<<endl
#define fi first
#define se second
#define all(x) x.begin(),x.end()

int n;
vector<int> g[1000010];
vector<int> ds;
vector<int> res;

int sz;
inline int dfs(int v,int pre){
  int sum=0;
  for(int nv : g[v]){
    if(nv==pre)continue;
    int tmp=dfs(nv,v);
    if(tmp == -1)return -1;
    sum+=tmp;
  }

  if(sum+1>sz)return -1;
  if(sum+1==sz)return 0;
  else return sum+1;
}

const int INF = 12345678;
inline int find(){
    vector<int> d(n,INF);
    d[0] = 0;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int now = que.front();
        que.pop();
        for(int nx:g[now]){
            if(d[nx]>d[now]+1){
                d[nx] = d[now]+1;
                que.push(nx);
            }
        }
    }

    int md = 0;
    int u = 0;
    rep(i,n){
        if(d[i]>md){
            md = d[i];
            u = i;
        }
    }

    d = vector<int>(n,INF);
    vector<int> par(n,-1);
    d[u] = 0;
    que.push(u);
    while(!que.empty()){
        int now = que.front();
        que.pop();
        for(int nx:g[now]){
            if(d[nx]>d[now]+1){
                d[nx] = d[now]+1;
                par[nx] = now;
                que.push(nx);
            }
        }
    }

    md = 0;
    int v = 0;
    rep(i,n){
        if(d[i]>md){
            md = d[i];
            v = i;
        }
    }

    rep(loop,md/2) v = par[v];
    return v;
}

int main(){
  scanf("%d",&n);
  rep(i,n-1){
    int a,b;
    scanf("%d%d",&a,&b);
    a--;b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int start = find();
//   dbg(start);
  for(int i=1;i<=n;i++){
    if(n%i==0)ds.push_back(i);
  }

  for(int d : ds){
    if(d==n)continue;
    sz = d;
    if(dfs(start,-1)!=-1){
      res.push_back((n/d)-1);
    }
  }
  reverse(all(res));
  for(int r : res)printf("%d ", r);
  printf("\n");
  return 0;
}
