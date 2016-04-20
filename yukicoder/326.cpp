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
  int n,k;
  cin >>n >>k;

  vector<int> p(n+1), a(n+1);
  for(int i=1; i<=n; ++i) p[i]=i;

  REP(i,k){
    int x,y;
    scanf(" %d %d", &x, &y);
    swap(p[x],p[y]);
  }

  for(int i=1; i<=n; ++i) scanf(" %d", &a[i]);

  int pos[101];
  for(int i=1; i<=n; ++i){
    pos[p[i]]=i;
  }

  /*
  printf("p::\n");
  for(int i=1; i<=n; ++i) printf("%d ", p[i]);
  printf("\n");
  */
  /*
  printf("pos::\n");
  for(int i=1; i<=n; ++i) printf("%d ", pos[i]);
  printf("\n");
  */

  vector<pair<int,int> > ans;
  //posをaに一致させるために入れ替えを発生させる
  for(int i=1; i<=n; ++i){
    //iはaの何番目にあるか
    int a_index=0;
    for(int j=1; j<=n; ++j){
      if(a[j]==i) a_index=j;
    }

    //その位置には現在vがある
    int v=pos[a_index];
    //iとvを交換したい
    if(i<v){ //(v,v-1),(v-1,v-2),...,(i+1,i)
      for(int j=v; j>i; --j){
        ans.push_back(make_pair(j-1,j));

        //pos上でj-1とjの値をもつindexを探す
        int tp,tq;
        for(int k=1; k<=n; ++k){
          if(pos[k]==j-1) tp=k;
          if(pos[k]==j) tq=k;
        }
        swap(pos[tp],pos[tq]);
      }
    }
    else if(i>v){ //(v,v+1),(v+1,v+2),...,(i-1,i)
      for(int j=v; j<i; ++j){
        ans.push_back(make_pair(j,j+1));

        //pos上でjとj+1の値をもつindexを探す
        int tp,tq;
        for(int k=1; k<=n; ++k){
          if(pos[k]==j) tp=k;
          if(pos[k]==j+1) tq=k;
        }
        swap(pos[tp],pos[tq]);
      }
    }

  }

  cout << ans.size() << endl;
  REP(i,ans.size()){
    printf("%d %d\n", ans[i].first, ans[i].second);
  }

  return 0;
}
