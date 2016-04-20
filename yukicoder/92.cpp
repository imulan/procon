#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int main(int argc, char const *argv[]) {
  int i,j,x;

  int n,m,k;
  cin >>n >>m >>k;

  //コスト、行き先で保存
  vector< pair<int,int> > v[101];

  rep(i,m){
    int a,b,c;
    cin >>a >>b >>c;
    v[a].pb(mp(c,b));
    v[b].pb(mp(c,a));
  }

  vector<int> d(k);
  rep(i,k) cin >>d[i];

  //現段階で居場所としてありえる場所
  bool valid[101];
  rep(i,n+1) valid[i]=true;

  rep(i,k){
    bool tmp[101];
    rep(j,n+1) tmp[j]=false;

    //d[i]にコストが一致する道があるかそれぞれ探す
    for(j=1; j<=n; ++j){
      if(!valid[j]) continue;

      for(x=0; x<v[j].size(); ++x){
        if(v[j][x].fi==d[i]){
          tmp[v[j][x].sc]=true;
        }
      }
    }

    rep(j,n+1) valid[j]=tmp[j];

    /*
    printf("turn %d:",i);
    for(j=1; j<=n; ++j){
      if(valid[j]) printf(" %d", j);
    }
    printf("\n");
    */
  }

  std::vector<int> ans;
  for(i=1; i<=n; ++i){
    if(valid[i]) ans.pb(i);
  }

  printf("%d\n", ans.size());
  rep(i,ans.size()){
    if(i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
