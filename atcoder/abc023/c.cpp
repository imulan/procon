#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <utility>
using namespace std;

int main(){
  int r, c, k, n;
  long ans=0;
  set<pair<int,int> > candy;

  int yoko[100000]={0}, tate[100000]={0};
  int yokomax=0, tatemax=0;

  scanf(" %d %d %d %d", &r, &c, &k, &n);

  for(int i=0; i<n; ++i){
    int a, b;
    scanf(" %d %d", &a, &b);
    a--;
    b--;

    //飴のある位置を記録
    candy.insert( make_pair(a, b) );
    yoko[a]++;
    tate[b]++;
  }

  for(int i=0; i<r; ++i) yokomax=max(yokomax, yoko[i]);
  for(int i=0; i<c; ++i) tatemax=max(tatemax, tate[i]);

  for(int i=0; i<r; ++i){
    if(yoko[i]+tatemax<k) continue;
    for(int j=0; j<c; ++j){
      int tmp=yoko[i]+tate[j];

      if(candy.find(pair<int, int>(i,j)) != candy.end()) tmp--;

      if(tmp==k) ans++;
    }
  }

  printf("%ld\n", ans);
}
