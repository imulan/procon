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
  int y[100001]={0}, t[100001]={0};

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

  for(int i=0; i<r; ++i) y[yoko[i]]++;
  for(int i=0; i<c; ++i) t[tate[i]]++;

  //for(int i=0; i<=k; ++i) printf("yoko[%d]=%d\n",i ,y[i]);
  //for(int i=0; i<=k; ++i) printf("tate[%d]=%d\n", i, t[i]);

  for(int i=0; i<=k; ++i) ans+=(long)y[i]*t[k-i];

  for(set<pair<int, int> >::iterator it=candy.begin(); it!=candy.end(); ++it){
    int tmp=yoko[(*it).first]+tate[(*it).second];
    if(tmp==k) ans--;
    else if(tmp==k+1) ans++;
  }

  printf("%ld\n", ans);
}
