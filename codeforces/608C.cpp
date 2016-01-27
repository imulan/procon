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
  cin >>n;

  vector< pair<long,long> > b(n);
  for(long i=0; i<n; ++i)
    scanf(" %ld %ld", &b[i].first, &b[i].second);
  sort(b.begin(), b.end());

  vector<long> num(1000001); //累積和
  for(long i=0; i<n; ++i) ++num[b[i].first];
  for(long i=1; i<=1000000; ++i) num[i]+=num[i-1];

  vector<long> d(n); //b[i]を起動した時に破壊してしまう数
  for(long i=0; i<n; ++i){
    if(b[i].first==0){
      d[i]=0;
      continue;
    }
    else{
      long left = b[i].first-b[i].second-1;
      if(left>=0) d[i] = num[b[i].first-1]-num[left];
      else d[i] = num[b[i].first-1];
    }
  }

  vector<long> mem(n);
  fill(mem.begin(), mem.end(), -1);
  mem[0]=0; //0番を起動しても壊れるものはない

  for(long B=1; B<n; ++B){
    //B番を起動するとき
    long tmp=0;
    for(long i=B; i>=0; --i){
      if(mem[i]>=0){
        tmp+=mem[i];
        break;
      }
      tmp+=d[i];
      i-=d[i];
    }
    mem[B]=tmp;
    //printf("mem[%ld]= %ld\n", B, mem[B]);
  }


  long ans=0;
  //新たに設置するビーコンが何も影響を与えない場合どうなるか
  for(long i=n-1; i>=0; --i){
    ans+=d[i];
    i-=d[i];
  }

  //設置するビーコンでどこまで破壊するか決める
  for(long B=n-1; B>0; --B){
    long tmp = n-B;
    tmp += mem[B-1];
    ans = min(ans,tmp);
    //printf("%ld\n", tmp);
  }

  cout << ans << endl;

  return 0;
}
