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
  long n;
  long h[100000], sth[100000];

  cin >> n;
  for(long i=0; i<n; ++i){
    scanf(" %ld", &h[i]);
    sth[i]=h[i];
  }

  sort(sth, sth+n);

  map<long,long> mp;
  for(long i=0; i<n; ++i){
    if(mp.find(sth[i]) == mp.end()){
      //その値が数列内で一番最初に出たならそれを保存
      mp[sth[i]] = i;
    }
  }

  //本来何番目に出るべきなのか
  for(long i=0; i<n; ++i){
    long tmp=h[i];
    h[i] = mp[h[i]];
    mp[tmp] = mp[tmp]+1;
  }

  long ans=0;
  long start=0; //注目部の始点を記録

  //現時点で出た最も大きい値と小さい値
  long big=-1, small=n;
  for(long i=0; i<n; ++i){
    //更新
    big = max(big, h[i]);
    small = min(small, h[i]);
    //printf("small: %ld, big: %ld\n", small, big);

    //部分になり得るか判定
    if(start==small && big == i){
      //リセット
      big=-1;
      small=n;

      ans++;
      start = i+1;
    }
  }

  printf("%ld\n", ans);
}
