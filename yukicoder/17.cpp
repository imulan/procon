#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

const int INF=10000000;

int main(int argc, char const *argv[]) {
  int n;
  cin >>n;
  std::vector<int> s(n);
  rep(i,n) cin >>s[i];

  int cost[50][50];
  rep(i,n)rep(j,n) cost[i][j]=INF;
  rep(i,n) cost[i][i]=0;

  int m;
  cin >>m;
  rep(i,m){
    int a,b,c;
    cin >>a >>b >>c;
    cost[a][b]=cost[b][a]=c;
  }

  rep(k,n){
    rep(i,n){
      rep(j,n){
        if(cost[i][j]>cost[i][k]+cost[k][j])
          cost[i][j]=cost[i][k]+cost[k][j];
      }
    }
  }

  int ans=INF;
  for(int i=1; i<=n-2; ++i){ //1つめの地点
    for(int j=1; j<=n-2; ++j){ //2つめの地点
      if(i==j) continue;

      ans = min(ans, cost[0][i]+s[i]+cost[i][j]+s[j]+cost[j][n-1]);
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
