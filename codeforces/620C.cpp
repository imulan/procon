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
  long n;
  scanf(" %ld", &n);

  map<long,long> mp;
  vector< pair<long,long > > ans;

  long st=0;

  for(long i=0; i<n; ++i){
    long a;
    scanf(" %ld", &a);

    if(mp.find(a)==mp.end()) mp[a]=1;
    else{ //重複する数が見つかった、segmentを作る
      ans.push_back(make_pair(st+1,i+1));
      mp.clear();
      st=i+1;
    }
  }

  //output
  if(ans.size()==0){
    printf("-1\n");
  }
  else{
    //区間の数
    printf("%ld\n", ans.size());

    //それを前から順にみつける
    for(long i=0; i<ans.size(); ++i){
      if(i==ans.size()-1){
        printf("%ld %ld\n", ans[i].first, n);
      }
      else{
        printf("%ld %ld\n", ans[i].first, ans[i].second);
      }
    }
  }

  return 0;
}
