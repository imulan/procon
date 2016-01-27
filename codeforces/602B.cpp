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
  cin >> n;
  vector<long> a(n);
  for(long i=0; i<n; ++i) scanf(" %ld", &a[i]);

  long ans=0;
  long h=0, t=0;

  long one=0, two=0;
  long one_index=-1, two_index=-1;

  //しゃくとり法
  while(t<n){
    while (t<n) {

      if(one==0) {one=a[h]; one_index=h;}
      else{
        if(one==a[t]){
          one_index=t;
          t++;
        }
        else{
          if(two==0 && one!=a[t]){
            two=a[t];
            two_index=t;
            t++;
          }
          else if(two!=0 && one!=a[t]){
            if(two==a[t]){
              two_index=t;
              t++;
            }
            else{ //a[t]はoneともtwoとも違う値
              break;
            }
          }
        }
      }

    }

    //printf("h=%ld, t=%ld\n",h,t);
    ans=max(ans,t-h);

    int index;
    if(one_index<two_index){
      index=one_index+1;

      one=two;
      two=0;
      one_index=two_index;
      two_index=-1;
    }
    else{
      index=two_index+1;
      two=0;
      two_index=-1;
    }

    h=index;
  }

  printf("%ld\n", ans);
}
